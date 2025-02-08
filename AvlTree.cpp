template <typename Comparable>
AvlTree<Comparable>::AvlTree( ) : root( NULL )
{
  //set root to null
}



template <typename Comparable>
AvlTree<Comparable>::AvlTree( const AvlTree & rhs ) : root( NULL )
{
  //in fact this is a shallow copy
  *this = rhs;
}

template <typename Comparable>
AvlTree<Comparable>::~AvlTree( )
{
  //call the helper function
  makeEmpty( );
}


template <typename Comparable>
const Comparable & AvlTree<Comparable>::findMin( ) const
{
  if( isEmpty( ) )
    throw UnderflowException( );
  return findMin( root )->element;
}


template <typename Comparable>
const Comparable & AvlTree<Comparable>::findMax( ) const
{
  if( isEmpty( ) )
    throw UnderflowException( );
  return findMax( root )->element;
}


template <typename Comparable>
bool AvlTree<Comparable>::contains( const Comparable & x ) const
{
  //call helper function
  return contains( x, root );
}


template <typename Comparable>
bool AvlTree<Comparable>::isEmpty( ) const
{
  return root == NULL;
}


template <typename Comparable>
void AvlTree<Comparable>::printTree( ) const
{
  if( isEmpty( ) )
    cout << "Empty tree" << endl;
  else
    printTree( root ); 
}


template <typename Comparable>
void AvlTree<Comparable>::makeEmpty( )
{
  makeEmpty( root );
}


template <typename Comparable>
void AvlTree<Comparable>::insert( const Comparable & x )
{
  insert( x, root );
}
     

template <typename Comparable>
void AvlTree<Comparable>::insert( const Comparable & x, AvlNode<Comparable> * & t )
{
  if( t == NULL )
    t = new AvlNode<Comparable>( x, NULL, NULL );
  else if( x < t->element )
    {
      //recursively insert x into left subtree
      insert( x, t->left );

      //do tree rotation if necessary
      if( height( t->left ) - height( t->right ) == 2 )
	if( x < t->left->element )
	  rotateWithLeftChild( t );
	else
	  doubleWithLeftChild( t );
    }
  else if( t->element < x )
    {
      //recursively insert x into right subtree
      insert( x, t->right );

      //do tree rotation if necessary
      if( height( t->right ) - height( t->left ) == 2 )
	if( t->right->element < x )
	  rotateWithRightChild( t );
	else
	  doubleWithRightChild( t );
    }
  else
    ;  // Duplicate; do nothing

  //finally reset the height of node t
  t->height = max( height( t->left ), height( t->right ) ) + 1;
}


template <typename Comparable>
AvlNode<Comparable> * AvlTree<Comparable>::findMin( AvlNode<Comparable> *t ) const
{
  if( t == NULL )
    return NULL;
  if( t->left == NULL )
    return t;
  return findMin( t->left );
}


template <typename Comparable>
AvlNode<Comparable> * AvlTree<Comparable>::findMax( AvlNode<Comparable> *t ) const
{
  if( t != NULL )
    while( t->right != NULL )
      t = t->right;
  return t;
}



template <typename Comparable>
bool AvlTree<Comparable>::contains( const Comparable & x, AvlNode<Comparable> *t ) const
{
  if( t == NULL )
    return false;
  else if( x < t->element )
    return contains( x, t->left );
  else if( t->element < x )
    return contains( x, t->right );
  else
    return true;    // Match
}



template <typename Comparable>
void AvlTree<Comparable>::makeEmpty( AvlNode<Comparable> * & t )
{
  if( t != NULL )
    {
      makeEmpty( t->left );
      makeEmpty( t->right );
      delete t;
    }
  t = NULL;
}


template <typename Comparable>
void AvlTree<Comparable>::printTree( AvlNode<Comparable> *t ) const
{
  if( t != NULL )
    {
      printTree( t->left );
      cout << t->element << endl;
      printTree( t->right );
    }
}


template <typename Comparable>
AvlNode<Comparable> * AvlTree<Comparable>::clone( AvlNode<Comparable> *t ) const
{
  if( t == NULL )
    return NULL;
  else
    return new AvlNode<Comparable>( t->element, clone( t->left ), clone( t->right ), t->height );
}



template <typename Comparable>
int AvlTree<Comparable>::height( AvlNode<Comparable> *t ) const
{
  return t == NULL ? -1 : t->height;
}

template <typename Comparable>
int AvlTree<Comparable>::max( int lhs, int rhs ) const
{
  return lhs > rhs ? lhs : rhs;
}


template <typename Comparable>
void AvlTree<Comparable>::rotateWithLeftChild( AvlNode<Comparable> * & k2 )
{
  AvlNode<Comparable> *k1 = k2->left;
  k2->left = k1->right;
  k1->right = k2;
  k2->height = max( height( k2->left ), height( k2->right ) ) + 1;
  k1->height = max( height( k1->left ), k2->height ) + 1;
  k2 = k1;
}


template <typename Comparable>
void AvlTree<Comparable>::rotateWithRightChild( AvlNode<Comparable> * & k1 )
{
  AvlNode<Comparable> *k2 = k1->right;
  k1->right = k2->left;
  k2->left = k1;
  k1->height = max( height( k1->left ), height( k1->right ) ) + 1;
  k2->height = max( height( k2->right ), k1->height ) + 1;
  k1 = k2;
}


template <typename Comparable>
void AvlTree<Comparable>::doubleWithLeftChild( AvlNode<Comparable> * & k3 )
{
  rotateWithRightChild( k3->left );
  rotateWithLeftChild( k3 );
}


template <typename Comparable>
void AvlTree<Comparable>::doubleWithRightChild( AvlNode<Comparable> * & k1 )
{
  rotateWithLeftChild( k1->right );
  rotateWithRightChild( k1 );
}



