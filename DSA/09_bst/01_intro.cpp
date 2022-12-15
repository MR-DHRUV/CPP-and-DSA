#include <bits/stdc++.h>
using namespace std;

int main()
{
    // binary search tree
    // it is a tree in which all the elements at the left of any node are smaller than the node and at right are larger than that node

    /*
             3
           /   \
          2      5
         / \    / \
       -1   1  4   6
    */

    // it has no duplicates
    // inorder traversal gives elements in sorted order
    // -1 1 2 3 4 5 6

    // with n nodes there can be 2nCn/n+1 bst can be generated

    // drawbacks of bst
    // height of bst with n nodes can be from O(logN) to O(N) and we have no control over its height
    // 40 20 30 60 50 10 70 will have O(logN) height while 10 20 30 40 50 60 70 will have O(N) height

    // solution
    // avl trees are height balanced bst 



    return 0;
}