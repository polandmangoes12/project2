#ifndef AVL_TREE_H
#define AVL_TREE_H
#include <vector>

#include "dsexceptions.h"
#include <iostream>    
using namespace std;

//define AVL tree node
template <typename Comparable>
struct AvlNode
{
  Comparable element;
  AvlNode   *left;
  AvlNode   *right;
  int       height;

  //constructor
  AvlNode( const Comparable & theElement, AvlNode *lt,
	   AvlNode *rt, int h = 0 )
    : element( theElement ), left( lt ), right( rt ),
      height( h ) { }
};



// AvlTree class
//
// CONSTRUCTION: with ITEM_NOT_FOUND object used to signal failed finds
//
// ******************PUBLIC OPERATIONS*********************
// void insert( x )       --> Insert x
// void remove( x )       --> Remove x (unimplemented)
// bool contains( x )     --> Return true if x is present
// Comparable findMin( )  --> Return smallest item
// Comparable findMax( )  --> Return largest item
// boolean isEmpty( )     --> Return true if empty; else false
// void makeEmpty( )      --> Remove all items
// void printTree( )      --> Print tree in sorted order
// ******************ERRORS********************************
// Throws UnderflowException as warranted

template <typename Comparable>
class AvlTree
{
public:

  /* default constructor  */
  AvlTree( );

  /* constructor */
  AvlTree( const AvlTree & rhs );

  /* destructor */
  ~AvlTree( );
  
  AvlNode<Comparable> *root; //the pointer to root

  /*
   * Find the smallest item in the tree.
   * Throw UnderflowException if empty.
   */
  const Comparable & findMin( ) const;


  /*
   * Find the largest item in the tree.
   * Throw UnderflowException if empty.
   */
  const Comparable & findMax( ) const;


  /*
   * Returns true if x is found in the tree.
   */
  bool contains( const Comparable & x ) const;

  
  /*
   * Test if the tree is empty.
   * Return true if empty, false otherwise.
   */
  bool isEmpty( ) const;

  /*
   * Print the tree contents in sorted order.
   */
  void printTree( ) const;

  /*
   * Make the tree empty.
   */
  void makeEmpty( );

  /*
   * Insert x into the tree; duplicates are ignored.
   */
  void insert( const Comparable & x );


   /*
    * Double rotate binary tree node: first left child.
    * with its right child; then node k3 with new left child.
    * For AVL trees, this is a double rotation for case 2.
    * Update heights, then set new root.
    */
   void doubleWithLeftChild( AvlNode<Comparable> * & k3 );

      /*
    * Double rotate binary tree node: first right child.
    * with its left child; then node k3 with new right child.
    * For AVL trees, this is a double rotation for case 2.
    * Update heights, then set new root.
    */
    void doubleWithRightChild( AvlNode<Comparable> * & k3 );

    //inOrder traversal
    void inOrder(AvlNode<Comparable> *&root, std::vector<Comparable>& traversal);

  /*
   * Method to find the kth smallest element in a tree with count (AKA number of nodes) known
   * inputs: root node, int count, int k
   * returns kth smallest element
   */
   //int kthSmallest(AvlNode<Comparable> *&root, int counter, int k);
   int kthSmallest(AvlNode<Comparable> *&root, int counter, int k);

   /*
    * Method to find the kth smallest element in a tree with root node root
    * inputs: root node, integer k
    * returns kth smallest element
    */
   //int findkth(AvlNode<Comparable> * & root, int k);
   int findkth(AvlNode<Comparable> *&root, int k);
   /*
    * Method to print the preorder traversal sequence
    */
   void preOrder(AvlNode<Comparable> *&root) const;
 
   /*
    * Method to print the postorder traversal sequence
    */
   void postOrder(AvlNode<Comparable> *&root) const;
 
   /*
    * Method to return the number of nodes in a tree with root root
    * inputs: root node
    * returns integer (AKA number of nodes in the tree)
    */
   int count(AvlNode<Comparable> *&root);
  
private:
  
  /*
   * Internal method to insert into a subtree.
   * x is the item to insert.
   * t is the node that roots the subtree.
   * Set the new root of the subtree.
   */
  void insert( const Comparable & x, AvlNode<Comparable> * & t );


  /*
   * Internal method to find the smallest item in a subtree t.
   * Return node containing the smallest item.
   */
  AvlNode<Comparable> * findMin( AvlNode<Comparable> *t ) const;

  /*
   * Internal method to find the largest item in a subtree t.
   * Return node containing the largest item.
   */
  AvlNode<Comparable> * findMax( AvlNode<Comparable> *t ) const;


  /*
   * Internal method to test if an item is in a subtree.
   * x is item to search for.
   * t is the node that roots the tree.
   */
  bool contains( const Comparable & x, AvlNode<Comparable> *t ) const;


  /*
   * Internal method to make subtree empty.
   */
  void makeEmpty( AvlNode<Comparable> * & t );


  /*
   * Internal method to print a subtree rooted at t in 
   * sorted order.
   */
  void printTree( AvlNode<Comparable> *t ) const;


  /*
   * Internal method to clone subtree.
   */
  AvlNode<Comparable> * clone( AvlNode<Comparable> *t ) const;

  
  /*
   * Return the height of node t or -1 if NULL.
   */
  int height( AvlNode<Comparable> *t ) const;


  /* return the larger of the two input integers */
  int max( int lhs, int rhs ) const;

  
  /*
   * Rotate binary tree node with left child.
   * For AVL trees, this is a single rotation for case 1.
   * Update heights, then set new root.
   */
  void rotateWithLeftChild( AvlNode<Comparable> * & k2 );

      /*
   * Rotate binary tree node with right child.
   * For AVL trees, this is a single rotation for case 4.
   * Update heights, then set new root.
   */
   void rotateWithRightChild( AvlNode<Comparable> * & k1 );

 };
 
 #include "AvlTree.cpp"
 
 #endif
 