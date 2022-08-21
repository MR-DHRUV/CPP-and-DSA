#include <iostream>
using namespace std;

struct Array
{
    int *A;
    int size;
    int length;
};

void Display(struct Array arr)
{
    cout << "The array is" << endl;

    for (int i = 0; i < arr.length; i++)
    {
        cout << arr.A[i] << " ";
    };
    cout << endl;
}


int linearSearch(struct Array arr, int key)
{
    int index = 0;

    for (int i = 0; i < arr.length; i++)
    {
        if(arr.A[i] == key ){
            return i;
        }
    } 

    // if element is not found
    return -1;   

    // best care : O(1)
    // worst care : O(n)

    // average case : ( n(n+1)/2 ) / n = n+1/2 = O(n)
};

int main()
{

    // 1 linear search
    // 2 binary search

    // linear search
    // jo dhundte hain usse key bolte hain

    // unique elements hone chahiye , repetition hoga toh koi 1 hi milega
    // we want to get the index of element we are searching for

    struct Array arr;
    arr.size = 10;
    arr.A = new int[arr.size];

    for (int i = 0; i < arr.size; i++)
    {
        arr.A[i] = i+1;
    }

    arr.length = 10;
    Display(arr);

    cout<<linearSearch(arr,5)<<endl;
    cout<<linearSearch(arr,11)<<endl;
    cout<<linearSearch(arr,1)<<endl;
    

    return 0;
}