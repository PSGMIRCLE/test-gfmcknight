#include "KDT.hpp"
#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<Point> vector_from_file(string filename) {
  //Open file 
	ifstream in;
	in.open(filename, ios::binary);

	//Check if input file was actually opened
	if(!in.is_open()) 
	{
		cout<< "Invalid input file. No file was opened. Please try again.\n";
    exit(-1);
	}

	//Check for empty file
	in.seekg(0, ios_base::end); 
	unsigned int len = in.tellg();
	if(len==0) 
	{
		cout << "The file is empty. \n";
    exit(-1);
	}

	//Resets the stream to beginning of file
	in.seekg(0, ios_base::beg);
 
  KDT tree;
  string line;

  vector<Point> points;
  while (in.good()) {
    double x, y;
    in >> x;
    in >> y;
    points.push_back(Point(x, y));
  }
  
  if(in.is_open())
	{
		in.close();
	}

  return points;
}

int run_tests(vector<Point>& kdt_build_points,
              vector<Point>& test_cases, vector<Point>& solutions) {

  if (test_cases.size() != solutions.size()) {
    cerr << "Number of test cases and solutions must be equivalent" << endl;
    exit(-1);
  }

  int error_count = 0;

  KDT* tree = new KDT();
  tree->build(kdt_build_points);

  if (tree->size() != kdt_build_points.size()) {
    cerr << "Test failed for tree size" << endl;
    cerr << "\tExpected: " << kdt_build_points.size() << endl;
    cerr << "\tActual: " << tree->size() << endl;
    error_count++;
  }

  unsigned int targetHeight = kdt_build_points.size() == 0 ?
        0 : (unsigned int)log2(kdt_build_points.size()) + 1;

  if (tree->height() != targetHeight) {
    cerr << "Test failed for tree height" << endl;
    cerr << "\tExpected: " << targetHeight << endl;
    cerr << "\tActual: " << tree->height() << endl;
    error_count++;
  }

  vector<Point>::iterator test_it = test_cases.begin();
  vector<Point>::iterator solution_it = solutions.begin();
  for (; test_it != test_cases.end() && solution_it != solutions.end(); 
      test_it++, solution_it++) {
    Point find_result = *tree->findNearestNeighbor(*test_it);
    
    if (find_result != *solution_it) {
      cerr << "Test failed for find of point " << *test_it << endl;
      cerr << "\tExpected: " << *solution_it << endl;
      cerr << "\tActual: " << find_result << endl;
      error_count++;
    }
  }

  delete tree;
  return error_count;
}

int custom_tests() {

  cout << "Running custom tests" << endl;

  vector<Point> points = vector_from_file("custom_points.txt");
  int error_count = 0;

  vector<Point> test_cases;
  test_cases.push_back(Point(3, 9));
  test_cases.push_back(Point(4.5, 5));
  test_cases.push_back(Point(100, 100));
  test_cases.push_back(Point(6, 13));

  vector<Point> solutions;
  solutions.push_back(Point(6, 9)); 
  solutions.push_back(Point(4, 5)); 
  solutions.push_back(Point(-1, 50)); 
  solutions.push_back(Point(5, 12)); 

  error_count += run_tests(points, test_cases, solutions);
  return error_count;
  
}

// Exhaustive testing
int exhaustive_tests() {
  cout << "Running exhaustive tests" << endl;

  int error_count = 0;

  vector<Point> points = vector_from_file("test_points.txt");
  vector<Point> test_cases = vector_from_file("queryPoints.txt");
  vector<Point> solutions = vector_from_file("solutionPoints.txt");

  error_count += run_tests(points, test_cases, solutions);

  return error_count;
}

// DO NOT ADD ANY CHARACTERS AFTER THE BACKSLASHES!
#define ASSERT_NOTHING_FOUND(T, P) if (T.findNearestNeighbor(P) != T.end()) \
{ \
  cerr << "Incorrect value on empty tree for point " << P << endl; \
  error_count++; \
}

int empty_test() {
  
  cout << "Running tests on empty tree" << endl;

  int error_count = 0;

  KDT tree;
  vector<Point> points;
  tree.build(points);

  if (tree.size() != 0) {
    cerr << "Test failed for tree size" << endl;
    cerr << "\tExpected: " << 0 << endl;
    cerr << "\tActual: " << tree.size() << endl;
    error_count++;
  }
  if (tree.height() != 0) {
    cerr << "Test failed for tree height" << endl;
    cerr << "\tExpected: " << 0 << endl;
    cerr << "\tActual: " << tree.height() << endl;
    error_count++;
  }

  ASSERT_NOTHING_FOUND(tree, Point(-1, -1))
  ASSERT_NOTHING_FOUND(tree, Point(2, 3))
  ASSERT_NOTHING_FOUND(tree, Point(2000, -3000))
  ASSERT_NOTHING_FOUND(tree, Point(-23.5692, 34.762)) 

  return error_count; 
}


int main(int argc, char* argv[])
{
	//Check for Arguments
	if(argc != 1){
		cout << "Invalid number of arguments.\n" 
		     << "Usage: ./kdt2 >.\n";
		return -1;
	}

  int error_count = custom_tests() + empty_test() + exhaustive_tests();

	if (error_count == 0) {
    cout << "Tests passed" << endl;
    return 0;
  }

  else {
    cout << endl << "Failed " << error_count << " tests" << endl;
    return 1;
  }
}