#ifndef KDT_HPP
#define KDT_HPP

#include <algorithm> // sort, max, min
#include <iostream>  // cout, cin, and cerr
#include <math.h>    // pow, abs
#include <vector>    // vector<typename>
#include <limits>    // numeric_limits<type>::max()
#include "BST.hpp"

using namespace std;

class Point {
  private:
    double delta = 0.00005;
  public:
    /** x and y point coordinates */
    double x, y;

    /** Default constructor: point at (0, 0) */
    Point(): x(0.0), y(0.0) { }

    /** constructor that defines point location */
    Point(double x, double y): x(x), y(y) { }

    /** Equals operator */
    bool operator == (const Point& other) const {
      return abs(x - other.x) < delta && abs(y - other.y) < delta;
    }

    /** Not-equals operator */
    bool operator != (const Point& other) const {
      return abs(x - other.x) > delta || abs(y - other.y) > delta;
    }

    /** Not-equals operator */
    bool operator < (const Point& other) const {
      cerr << "This operator should not be called, you will need " <<
        "check the x and y components each time" << endl;
      return false;
    }

    /** Calculate and return the distance between two points p1 and p2
     */ // TODO
    static double squareDistance(const Point& p1, const Point& p2) {
      return pow((p1.x - p2.x), 2.0) + pow((p1.y - p2.y), 2.0 );
    }
};

std::ostream& operator << (std::ostream& out, const Point& data) {
  out << "(" << data.x << ", " << data.y << ")";
  return out;
}


bool xLessThan(const Point & p1, const Point & p2) {
  return p1.x < p2.x;
}

bool yLessThan(const Point & p1, const Point & p2) {
  return p1.y < p2.y;
}

class KDT : public BST<Point> {
  public:

    /** Given a vector of Point references, insert a copy into the BST.
     *  Return true if the item was added to the KDTree
     *         false if an equivalent item was found in the tree
     *  Note. Because of the nature of the KDTree, a simple < operator
     *        will not be sufficient.  You will need to check the x and y 
     *        coordinates individually.  Two functions have been provided
     *        for your convenience above, and you may find them useful for the
     *        sort function from #include<algorithm>.
     *  Note. Since KDT inherits from BST, you still have access to the 
     *        root, isize, and iheight member variables.
     */ // TODO
    virtual unsigned int build(vector<Point>& items) {
      return 0;
    }


    /** Find the nearest neighbor to a given point
     *  Returns the point in the kd-tree nearest to the parameter item.
     *  Note. THIS IS DIFFERENT THAN HOW THE PREVIOUS FIND FUNCTION WORKS
     *  Note. Since KDT inherits from BST, you still have access to the 
     *        root, isize, and iheight member variables.
     *  Note. The dimension ordering you used to build the tree must be used
     *        to search through it.
     */ // TODO
    virtual iterator findNearestNeighbor(const Point& item) const {
      return 0;
    }
    
    /** For the kd-tree, the find method should not be used.  Use the function
     *  findNearestNeighbor instead.
     */
    virtual iterator find(const Point& item) const override {
      cerr << "The KD Tree find method should not be called" << endl;
      cerr << "Use findNearestNeighbor instead" << endl;
      return 0;
    }


    /** For the kd-tree, the insert method should not be used.  The tree is
     *  built all at once.  There should be no scenario where you add individual
     * points.
     */
    virtual bool insert(const Point& item) override {
      cerr << "The KD Tree insert method should not be called" << endl;
      return false;

    }
  private:

    /** Recursively add a subset of the array to the KD tree
     *  Parameters items: the list of points that are used to build the kd tree
     *             start: the starting index for this subsection of the tree
     *             end: the non-inclusive ending index for this subtree
     *             dimension: 0 if sorting along the x-axis, and 1 if sorting
     *                        along the y-axis
     *  PostConditions: the parent node should have its left and right children
     *                  set if there are any available points and recursive
     *                  calls should be made for the left and right subtree 
     *                  (again, if there are any remaining points).
     */ // TODO
    BSTNode<Point>* buildSubset(vector<Point> items, unsigned int start, 
                                 unsigned int end, unsigned int dimension, 
                                 unsigned int height) {
      return 0;
    }

    /** Find the node in the subtree with that is closes to the given point p
     *  Parameters: node the root of the subtree being searched
     *              queryPoint the point whose nearest neighbor should be found
     *              smallestSquareDistance the smallest distance value found in
     *                the tree so far which can be updated
     *              closestPoint the node corresponding to the current closest
     *                node in the tree which can be udpated
     *              dimension 0 if the node splits along the x-axis and 1 
     *                if the node splits the place along the y-axis
     *  Return: a BSTNode object that represents the point in the subtree
     *          closest to the given point p (including the root node)
     */ // TODO
    void  findNNHelper(BSTNode<Point> * node, const Point& queryPoint,
                                 double * smallestSquareDistance, 
                                 BSTNode<Point> ** closestPoint,
                                 unsigned int dimension) const {
    }
};


#endif // KDT_HPP
