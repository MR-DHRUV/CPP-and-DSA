#include<iostream>
using namespace std;

int main()
{

    // n-ary trees
    // like 2 ary trees are called binary trees
    // n is the degree of the tree


    // strict m-ary tree
    // a node can have either m or 0 children

    // min and max nodes in a strict m-ary tree of height h
    // min : (m * h ) + 1
    // max : (1 + m^1 + m^2 + ....... + m^h) = ( (m^h+1) - 1 ) / m - 1


    // min and max height of a strict m-ary tree from n nodes
    // min : logm[n(m-1)+1]-1
    // max : n-1/m 

    // no of leaf nodes 'n(0)' 
    // n(0) = n(m)*(m-1) + 1 where n(m) is no of nodes of degree m
    // e = (m-1)i + 1





    return 0;
}