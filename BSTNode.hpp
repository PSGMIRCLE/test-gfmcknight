#ifndef BSTNODE_HPP
#define BSTNODE_HPP
#include <iostream>
#include <iomanip>
using namespace std;

template<typename Data>
class BSTNode {

public:

  /** Constructor.  Initialize a BSTNode with the given Data item,
   *  no parent, and no children.
   */
  BSTNode(const Data & d) : data(d) {
    left = 0;
    right = 0;
    parent = 0;
  }

  BSTNode<Data>* left;
  BSTNode<Data>* right;
  BSTNode<Data>* parent;
  Data const data;   // the const Data in this node.

  /** Return the successor of this BSTNode in a BST, or 0 if none.
   ** PRECONDITION: this BSTNode is a node in a BST.
   ** POSTCONDITION:  the BST is unchanged.
   ** RETURNS: the BSTNode that is the successor of this BSTNode,
   ** or 0 if there is none.
   */
  BSTNode<Data>* successor() {
    BSTNode<Data>* cur = this;
    if (right) {
      cur = cur->right;
      while (cur->left) cur = cur->left;
      return cur;
    }

    while (cur->parent) {
      if (cur == cur->parent->left) break;
      cur = cur->parent;
    }
    cur = cur->parent;

    return cur;
  }

}; 

/** Overload operator<< to print a BSTNode's fields to an ostream. */
template <typename Data>
ostream & operator<<(ostream& stm, const BSTNode<Data> & n) {
  stm << '[';
  stm << setw(10) << &n;                 // address of the BSTNode
  stm << "; p:" << setw(10) << n.parent; // address of its parent
  stm << "; l:" << setw(10) << n.left;   // address of its left child
  stm << "; r:" << setw(10) << n.right;  // address of its right child
  stm << "; d:" << n.data;               // its data field
  stm << ']';
  return stm;
}

#endif // BSTNODE_HPP
