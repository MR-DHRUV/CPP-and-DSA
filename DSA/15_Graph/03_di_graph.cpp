#include<bits/stdc++.h>
using namespace std;



int main()
{
    // representation of directed graph
    /*

        1---->2
        | ^   |
        |  \  |
        V   \ V
        4---->3


        no of vertices = 4
        no of edges = 5

        1 adjacency matrix
        no of rows/col in matrix = no of vertices
        // M[u][v] = 1 when there is an edge b/w u->v

          1 2 3 4
       1  0 1 0 1
       2  0 0 1 0
       3  1 0 0 0
       4  0 0 1 0

       // space complexity : O(n2)
       // time complexity for any algo to traverse a graph in this form : O(n2)

       2 Adjacency List
       we maintain a ll for each vertex and in this list we store all the elements that are connected to it 

       1->2->4
       2->3
       3->1
       4->3

       // space complexity : O(V+2E) = O(V+E)
       // time complexity for any algo to traverse a graph in this form : O(V+E)

        3 Inverse adjacency list
        // here we make an element for incomming elements like 1 ke pass 3 arraa h

       1->3
       2->1
       3->2->4
       4->1

        // wighted graph
        in adjacency matrix we write weight instead of 1, this matrix is called cost adjacency matrix
        if we use linked representation we have a data member for weight in ll

        3 Compact List

    */


    return 0;
}