#include<iostream>
using namespace std;

int main()
{
    int *arr;
    arr = new int[5];

    // You cannot increase the size of array directly

    // increasing the size
    // Method: make new array and copy prev arr into it, then make arr point on q;

    int *q;
    q = new int[10];

    for (int i = 0; i < 5; i++)
    {
        q[i] = arr[i]; 
    };

    delete(arr);

    arr = q;
    q = NULL;


    return 0;
}