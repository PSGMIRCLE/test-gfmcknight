#include "KDT.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include<fstream>
#include<string>
using namespace std;

/**
 *  IMPORTANT!! YOU MUST USE THE FOLLOWING LINES OF CODE FOR PROMPTS AND OUTPUTS:
 *  To output size of tree: cout << "Size of tree: " << size << "\n";
 *  To output height of tree: cout << "Height of tree: " << height << "\n";
 *  To prompt the user to enter a coordinate: cout << "Enter coordinate (x, y): " << "\n";
 *
 *  To show the result of the nearest neighbor search: cout << "Nearest point in tree: " << nearestNeighbor << "\n";
 *  To prompt the user to try again: cout << "Search again? (y/n)" << "\n";
 *
 *  Use cin to process user input.
 *
 *  You MUST output size, then height, then prompt the user to search, as above.
 *
 *  You MUST have the prompt for entering the name appear if and only if 
 *  the user input for trying again is "y" followed by the return key
 *  You MUST have the program exit (exiting the prompt loop) if and only if
 *  the user input for trying again is "n" followed by the return key
 *  You should handle other inputs for the retry prompt, 
 *  but we will not be testing them.
 *
 *  Note that size, height, and name are local variables in main that you 
 *  should update accordingly. Also note that actor/actress names will be 
 *  in all caps, last name followed by first name 
 *  (except in odd cases, eg. "50 CENT" and "ICE-T")
*/

using namespace std;

int main(int argc, char* argv[])
{
	//Size of tree should be stored in local variable size.
	//Height of tree should be stored in local variable height.
	//Input name will be stored in a Point object nearestNeighbor
	unsigned int size = 0;
	unsigned int height = 0;
	Point nearestNeighbor;

	//Check for Arguments
	if(argc != 2){
		cout << "Invalid number of arguments.\n" 
		     << "Usage: ./main <input filename>.\n";
		return -1;
	}

	//Open file 
	ifstream in;
	in.open(argv[1], ios::binary);

	//Check if input file was actually opened
	if(!in.is_open()) 
	{
		cout<< "Invalid input file. No file was opened. Please try again.\n";
		return -1;
	}

	//Check for empty file
	in.seekg(0, ios_base::end); 
	unsigned int len = in.tellg();
	if(len==0) 
	{
		cout << "The file is empty. \n";
		return -1;
	}

	//Resets the stream to beginning of file
	in.seekg(0, ios_base::beg); 

	// My implementation begin
	double x, y;

    vector<Point> points;

    while (true) {
        in >> x;
        in >> y;
        if (!in.good()) break;
        points.push_back(Point(x, y));
    }

    KDT kdt;
    kdt.build(points);
    size = kdt.size();
    height = kdt.height();
    cout << "Size of tree: " << size << "\n";
    cout << "Height of tree: " << height << "\n";

    char input = 'y';
    while (input == 'y') {
        cout << "Enter coordinate (x, y): " << "\n";
        cin >> x; 
        cin >> y; 
        Point nearestNeighbor = *kdt.findNearestNeighbor(Point(x, y));
        cout << "Nearest point in tree: " << nearestNeighbor << "\n";
        cout << "Search again? (y/n)" << "\n";
        cin >> input;
    }

  	// My implementation end

	if(in.is_open())
	{
		in.close();
	}
	
	return 0;
}
