#include <iostream>
using namespace std;

int main()
{
    // while execution of a program it i sbrought to memory and memory is devided into 3 parts
    // code section => isme main code hota haii jisko execute krna haii

    // stack => The amount of memory required by a program deciced at compile time is called static memory  / stack frame / activation record of a function as anyting decided on or before compile time is called satic. The portion of memory where static momory is stored is called stack.

    // top most activation record belongs to the currently executing function

    // main is also treated as a function

    // once function is executed is activation recored or static memory is removed from the stack

    // This memory is auto allcoated and auto destroyed

    // Stack is LIFO => Last In First Out

    // stack is used for organised memory

    //////////////////////////////////////////////////////////////////////////////////

    // heap

    // heap is used for unorganised memory
    // heap is utilised as a resourse
    // jab chahiye ho tab leliya else free krdia

    // program cant access heap memory directly, it can be accessed using a pointer;

    // Heap declareation
    int *p;
    p = new int[5];

    // freeing it
    delete[] p;

    int *a;
    a = new int;
    *a = 5;
    cout << *a << endl;

    delete a;

    // never declare array like this, as stack can run out of memory
    // int n;
    // cin>>n;
    // int arr[n];

    // for larger n stack will run out of memory and the program will crash.
    // so use dynamic array for creating arrays at runtime

    // CREATING 2-D ARRAY IN HEAP
    int row, col;
    cin >> row >> col;

    int **arr2d;

    // it is an array of type int * , that is it is an array of pointers in which every pointer points to a array of size m
    arr2d = new int *[row]; // this part makes row

    for (int i = 0; i < row; i++)
    {
        arr2d[i] = new int[col]; // this part makes columns
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr2d[i][j];
        }
    }

    cout << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr2d[i][j] << " ";
        }

        cout << endl;
    }

    // remember to free the heap
    for (int i = 0; i < row; i++)
    {
        delete[] arr2d[i];// pahle colums free honge then pointer array free hoga jo row bnata haii, ulta krdia toh internal arrays reh jayenge aur memory leak ho jaygi 
    }

    delete[] arr2d;

    // Jagged array is array of arrays such that member arrays can be of different sizes, i.e., we can create a 2-D array but with a variable number of columns in each row. These type of arrays are also known as Jagged arrays.

//   arr[][] ={{0, 1, 2},
//             {6, 4},
//             {1, 7, 6, 8, 9},
//             {5} 
//           };

    // ref - gfg

    return 0;
}