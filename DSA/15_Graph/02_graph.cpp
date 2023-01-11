#include<bits/stdc++.h>
using namespace std;



int main()
{
    // representation of undirected graph
    /*

        1----2
        | \  |
        |  \ |
        4----3
        \    /
         \  /
           5 

        no of vertices = 5
        no of edges = 7

        1 adjacency matrix
        no of rows/col in matrix = no of vertices

          1 2 3 4 5
       1  0 1 1 1 0
       2  1 0 1 0 0
       3  1 1 0 1 1
       4  1 0 1 0 1
       5  0 0 1 1 0

       // space complexity : O(n2)
       // time complexity for any algo to traverse a graph in this form : O(n2)

       2 Adjacency List
       we maintain a ll for each vertex and in this list we store all the elements that are connected to it 

       1->2->4->3
       2->1->3
       3->1->2->4->5
       4->1->3->5
       5->4->3

       // space complexity : O(V+2E) = O(V+E)
       // time complexity for any algo to traverse a graph in this form : O(V+E)

       // wighted graph
           
           9
        1----2
      6 | \4 | 5
        |  \ |
        4----3
      2 \  8 / 7
         \  /
           5 

        in adjacency matrix we write weight instead of 1, this matrix is called cost adjacency matrix
        if we use linked representation we have a data member for weight in ll

        I -> infinity
          1 2 3 4 5
       1  I 9 4 6 I
       2  1 I 1 I I
       3  1 1 I 1 1
       4  1 I 1 I 1
       5  I I 1 1 I


       3 compact list representation
       stores data in 1d array
       size of array = v+2e+2

       // first v locations represent vertices and at those indices we store starting point of their adjacency list
       // leave 1 location vacant
       
        1----2
        | \  |
        |  \ |
        4----3
        \    /
         \  /
           5 

        space = 5 + 2*7 +2 = 22   

        /-> empty

        /  7  10 12 16 19 21  2  3  4  1  3  1  2  4  5  1  3  5  4  3
        00 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16 17 18 19 20

        6th index stores the end index of adjacecncy list of lase vertex, we mark that postion with an index outside the array that is size

       // space complexity : O(V+E), when e is almost eual to v => O(N)
       // time complexity for any algo to traverse a graph in this form : O(n2)

    */


    return 0;
}