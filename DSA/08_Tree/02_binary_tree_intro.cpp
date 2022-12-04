#include<iostream>
using namespace std;

int main()
{
    // tree of degree 2 is called binary tree
    // that is every node can have atmost 2 children

    // No of binary trees using N nodes
    // 1. All are unlabled : then there can be (2nCn/n+1) different trees
    // (2nCn/n+1) is called catalan number
    // no of trees with maximum height : ( 2^(n-1) ) 
    
    // labled nodes : (2nCn/n+1) * n! (n ways to arrange n different nodes within a formation)
    
    // max and min no nodes in a tree with given height
    // min : height+1
    // max : sum of (2^0 + 2^1 + ...... + 2^height) = (2^(height+1) - 1) [sum of gp]
    
    // max and min height of a tree with n nodes
    // max : n-1
    // min : log2(n+1) -1 
    

    // no of leaf nodes 'n(0)' 
    // n(0) = n(2) + 1 where n(2) is no of nodes of degree 2

    // strict / proper / complete binary tree
    // har node pr ya toh 0 children ho ya toh 2 , there can't be 1 children 
    // pura ho complete ho
    
    

    
    return 0;
}