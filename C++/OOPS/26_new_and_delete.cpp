#include <iostream>
using namespace std;

int main()
{
    // new
    // dynamic intialization hota haii yeh
    int *p = new int(4);

    // dynamic memory allocation
    // dynamic array of 3 integers
    // it is continues i.e blocks ek ke baad ek hain, randomised nahi hain
    int *arr = new int[3];

    arr[0] = 1;
    arr[1] = 10;
    arr[2] = 100;

    cout << "The value at address p is " << (*p) << endl;

    cout << "The address of block 1 is " << arr << endl;
    cout << "The address of block 2 is " << ++arr << endl;
    cout << "The address of block 3 is " << ++arr << endl;
    
    cout << "The value of arr[0] is " << arr[0] << endl;
    cout << "The value of arr[1] is " << arr[1] << endl;
    cout << "The value of arr[2] is " << arr[2] << endl;

    // delete
    // freeing of memory
    delete[] arr;

    cout<<endl<<endl;

    //trash value will be given as arr is removed from memory
    cout << "The value of arr[0] is " << arr[0] << endl;
    cout << "The value of arr[1] is " << arr[1] << endl;
    cout << "The value of arr[2] is " << arr[2] << endl;

    return 0;
}