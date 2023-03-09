#include <bits/stdc++.h>
using namespace std;

// disjoint set is a data structure that stores non overlapping or disjoint subset of elements

// operations
// 1 findSet -> returns the identity element of the set
// 2 Union -> unites two disjoint sets

// find parent
// find parent of any element will return its parent element in the set and it will also act as identity/ characterstic element

// 1 disjopint set will have 1 parent/identity/characterstic element

// union by rank
// rank : depth of any disjoint set;
// eg
/*
     7
    / \
    5 6
    /
    4
   /
  1

  depth : 3
  parent of all the nodes is 7
  thus to avoid travelling this tree, we perform path compression and convert all the desendants into children of parent
*/
// 1 me 2 add kare ya 2 me 1 is decided by rank
// humesha jiska rank jhyada haii usme add hoga as updation of parents kam hoga
// equal me kisime bhi add krdo

// while performing union we perform path compression to aviod travelling nodes to find the parent node, we rather update parent of all connected nodes when parent of parent is updated

class disjointSet
{
    int n;

    vector<int> parent;
    vector<int> rank;

public:
    disjointSet(int n)
    {
        parent = vector<int>(n);
        rank = vector<int>(n);

        // init
        makeSet();
    }

    // initializes the disjoint sets
    void makeSet()
    {
        for (int i = 0; i < n; i++)
        {
            parent[i] = i; // initially sab apne parent h
            rank[i] = 0;   // initially rank sbka 0
        }
    }

    int findParent(int node)
    {
        if (parent[node] == node)
        {
            return node;
        }

        // path compression , taaki next time O(1) me khooj lu
        return parent[node] = findParent(parent[node]);
    }

    void unionSet(int s1, int s2)
    {
        int p1 = findParent(s1);
        int p2 = findParent(s2);

        // can be only united iff they dont have same parents
        if (p1 != p2)
        {
            if (rank[p1] < rank[p2])
            {
                parent[p1] = p2; // update parent 
            }
            else if(rank[p1] > rank[p2])
            {
                parent[p2] = p1;
            }
            else
            {
                parent[p2] = p1;

                // update rank 
                rank[p1]++;
            }
        }
    }
};

int main()
{

    return 0;
}