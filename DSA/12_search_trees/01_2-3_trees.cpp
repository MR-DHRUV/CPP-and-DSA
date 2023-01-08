#include <bits/stdc++.h>
using namespace std;

class _23Trees
{
public:
  int k1;
  int k2;
};

int main()
{
  // 2-3 trees are search trees like bst
  // 2-3 trees are multiway search trees of degree 3
  // that is a node can have a maximum of 3 children
  // they are used in implimentation of databases

  // 2-3 tree means it can have 2 keys and 3 children at max
  // Since its a search tree we cant have duplicates 

  /*
          k1    k2
        /    |     \
      c1     c2     c3

    c1 < k1
    k1 < c2 < k2
    c3 > k2
  */


  // 2-3 trees are height balanced trees
  // they are B-tree of degree 3
  // B-Tree is a self-balancing search tree

  // B-Tree
  // All leaf nodes must be at same level
  // Every node must have atlest n/2 children
  // so 2-3 trees must have atlest 3/2 = 1.5 = 2 children

  // See copy for deletion and insertion 

  return 0;
}