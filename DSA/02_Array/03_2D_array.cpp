#include<iostream>
using namespace std;

int main()
{
    // memory allocated is linear in a multi-dimensional-array
    // Direct method = stack only
    int A[3][4];

    // 3X4  3 rows , 4 columns 


    // stack + heap both used
    int *N_Darray[3];
    // dont confuse b/w size and indexing
    // size starts from 1 while indexing starts from 0
    N_Darray[0] = new int[4];
    N_Darray[1] = new int[4];
    N_Darray[2] = new int[4];


    // heap only
    int **heap_nd_arr; // doubble pointer in heap
    *heap_nd_arr = new int [3];

    heap_nd_arr[0] = new int[4];
    heap_nd_arr[1] = new int[4];
    heap_nd_arr[2] = new int[4];



    return 0;
}