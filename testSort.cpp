#include "KDT.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;

void printPoints(vector<Point>& pts, int emphasis) {
  for (int i = 0; i < pts.size(); i++) {
    if (i == emphasis) cout << "======" << endl;
    cout << pts[i] << endl;
    if (i == emphasis) cout << "======" << endl;
  }
}

vector<Point> getPoints() {
  vector<Point> points;
  points.push_back(Point(1, 1));
  points.push_back(Point(3, 2));
  points.push_back(Point(2, 3));
  points.push_back(Point(5, 4));
  points.push_back(Point(3, 5));
  points.push_back(Point(4, 6));
  points.push_back(Point(1, 7));
  points.push_back(Point(9, 8));
  points.push_back(Point(-1, 9));
  points.push_back(Point(5, 10));
  points.push_back(Point(20, 11));
  points.push_back(Point(8, 12));
  points.push_back(Point(4, 13));
  points.push_back(Point(6, 14));
  points.push_back(Point(10, 15));
  return points;
}

int main() {

  vector<Point> points = getPoints();
  cout << "Points before order" << endl;
  printPoints(points, -1);

  KDT kdt;
  kdt.orderStats(points, 0, 14, 0, 0);
  cout << "Points after order" << endl;
  printPoints(points, 0);

  points = getPoints();
  kdt.orderStats(points, 0, 14, 14, 0);
  cout << "Points after order" << endl;
  printPoints(points, 14);

  points = getPoints();
  kdt.orderStats(points, 0, 14, 11, 1);
  cout << "Points after order" << endl;
  printPoints(points, 11);

}
