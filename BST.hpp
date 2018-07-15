#ifndef BST_HPP
#define BST_HPP
#include "BSTNode.hpp"
#include "BSTIterator.hpp"
#include <iostream>
#define NODE BSTNode<Data>*
using namespace std;

template<typename Data>
class BST {

protected:

  /** Pointer to the root of this BST, or 0 if the BST is empty */
  BSTNode<Data>* root;

  /** Number of Data items stored in this BST. */
  unsigned int isize;

  /** Height of this BST. */
  unsigned int iheight;
  
public:

  /** define iterator as an aliased typename for BSTIterator<Data>. */
  typedef BSTIterator<Data> iterator;

  /** Default constructor.
      Initialize an empty BST.
   */
  BST() : root(0), isize(0), iheight(0) {  }


  /** Default destructor.
      Delete every node in this BST.
   */
  virtual ~BST() {
    deleteAll(root);
  }

  /** Given a reference to a Data item, insert a copy of it in this BST.
   *  Return  true if the item was added to this BST
   *  as a result of this call to insert,
   *  false if an item equal to this one was already in this BST.
   *  Note: This function should use only the '<' operator when comparing
   *  Data items. (should not use ==, >, <=, >=)  For the reasoning
   *  behind this, see the assignment writeup.
   */
  virtual bool insert(const Data& item) {
    if (root) {
      bool found = false;
      unsigned int depth = 0;
      NODE n = helper(root, &found, &depth, item);

      if (found) return false;

      isize++;
      iheight = max(iheight, depth + 1);
      
      if (item < n->data) {
        n->left = new BSTNode<Data>(item);
        n->left->parent = n;
      } else {
        n->right = new BSTNode<Data>(item);
        n->right->parent = n;
      }
      return true;
    }

    isize = 1;
    root = new BSTNode<Data>(item);
    return true;
  }


  /** Find a Data item in the BST.
   *  Return an iterator pointing to the item, or pointing past
   *  the last node in the BST if not found.
   *  Note: This function should use only the '<' operator when comparing
   *  Data items. (should not use ==, >, <=, >=).  For the reasoning
   *  behind this, see the assignment writeup.
   */
  virtual iterator find(const Data& item) const {
    bool found = false;
    if (root) {
      NODE n = helper(root, &found, 0, item);
      if (found) return BST::iterator(n);
    } 
    return 0; 
  }

  
  /** Return the number of items currently in the BST.
   */
  unsigned int size() const {
     return isize;
  }
  
  /** Return the height of the BST.
   */
  unsigned int height() const {
      return iheight;
  }


  /** Return true if the BST is empty, else false.
   */
  bool empty() const {
      return isize == 0;
  }

  /** Return an iterator pointing to the first item in the BST (not the root).
   */
  iterator begin() const {
    return BST::iterator(first(root));
  }

  /** Return an iterator pointing past the last item in the BST.
   */
  iterator end() const {
    return typename BST<Data>::iterator(0);
  }


  /** Inorder traverse BST, print out the data of each node in ascending order.
      Implementing inorder and deleteAll base on the pseudo code is an easy way to get started.
      Pseudo Code:
      if current node is null: return;
      recursively traverse left sub-tree
      print current node data
      recursively traverse right sub-tree
   */
  void inorder() const {
    inorder_h(root);
  }


private:

  static void inorder_h(NODE node) {
    if (!node) return;
    inorder_h(node->left);
    cout << node->data << endl;
    inorder_h(node->right);
  }

  /** Find the first element of the BST
   */ 
  static BSTNode<Data>* first(BSTNode<Data>* root) {
    if (root && root->left) return first(root->left);
    return root;
  }

  /** do a postorder traversal, deleting nodes
   */
  static void deleteAll(BSTNode<Data>* n) {
    /* Pseudo Code:
      if current node is null: return;
      recursively delete left sub-tree
      recursively delete right sub-tree
      delete current node
    */
    if (n == 0) return;
    deleteAll(n->left);
    deleteAll(n->right);
    delete n;
  }

  static NODE helper(NODE cur, bool* eq, unsigned int* dep, const Data& item) {
    NODE n = 0;
    if (!(cur->data < item || item < cur->data)) { if (eq) *eq = true; return cur; }
    if (item < cur->data) n = cur->left; 
    if (cur->data < item) n = cur->right;
    if (!n) { if (eq) *eq = false; return cur; }
    if (dep) ++*dep;
    return helper(n, eq, dep, item);
  }
};


#endif //BST_HPP
