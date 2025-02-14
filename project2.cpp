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
#include <vector>
using namespace std;


int main( )
{
  //a simple test
  AvlTree<int> t;
  int i;
  std::vector<int> nums;
  //do{
  std::cout<<"\nEnter a sequence of numbers to build the AVL tree (enter -1 to end):"<<std::endl;
  //}while(cin!=-1);
  while(std::cin>>i)
  {
    if (i==-1)
    {
      break;
    }
    nums.push_back(i);
  }
  //insert ten integers
  //int count=0;
  for(int node: nums)
  {
    t.insert(node);
    //count++;
  }

  int counter=t.count(t.root);

  std::cout<<"The AVL tree has "<<counter<<" nodes in total.";

  std::cout<<"\nPre-order tree traversal:        ";
  t.preOrder(t.root);
  std::cout<<"\nPost-order tree traversal:       ";
  t.postOrder(t.root);

  int k;
  std::cout<<"\nSearch for the kth smallest value. Enter k:";
  std::cin>>k;
  int kth = t.findkth(t.root, k);
  std::cout<<"\nThe kth smallest value in the AVL tree is "<<kth<<".\n";
  
  //print tree
  //t.printTree( );

  //cout << "Test finished" << endl;
  return 0;
}
