#include <iostream>
using namespace std;

int main()
{
    // single valued variable also called scalar variable
    int num = 9;

    // array is a collection of data of simmilar data type
    // conigous memory
    int arr[5];
    int arr1[] = {1, 2, 3, 4, 5};

    // static and dynamic arrays
    // static array : size is fixed and cannot be mofdified, created in stack as its size is decided during compile time
    int staticArr[5];



    //dynamic array
    // created in stack during runtime

    int size;
    cout<<"Enter the size or array : ";
    cin>>size;

    int dynamicArray[size];

    // craeting array inside heap
    int *ptr;
    ptr = new int[5];
    // dynamic array of size 5;
    // using new keyword memory is allocated from heap


    delete(ptr);



    return 0;
}