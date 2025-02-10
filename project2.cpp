/************************************************************/
/* Author: Michelle Kilgallen */
/* Major: non-degree */
/* Creation Date: February 8, 2025 */
/* Due Date: February 13, 2025 */
/* Course: CSC 402 */
/* Professor Name: Dr. Zhang */
/* Assignment: Project 2 */
/* Filename: project2_MichelleKilgallen.cpp */
/* Purpose: The program will ask the user for a sequence of integers, use them to build an AVL tree, and print the total number of nodes, pre-order, post-order traversal sequence of the tree. The test program will then test the findkth() method, which will take the root node and an integer k as inputs and return the k’th smallest element in the tree. */
/************************************************************/
#include <iostream>
#include "AvlTree.h"
using namespace std;


int main( )
{
  //a simple test
  AvlTree<int> t;
  int i;
  
  //insert ten integers
  for( i = 1; i <= 10; i ++)
    t.insert( i );
  
  //print tree
  t.printTree( );

  cout << "Test finished" << endl;
  return 0;
}
