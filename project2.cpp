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
