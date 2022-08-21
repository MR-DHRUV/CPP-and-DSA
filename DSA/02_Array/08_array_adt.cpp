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
}

int main()
{
    // array as abstract data type

    // Array Space
    // size
    // Length (no of elements present)


    // we will learn to impliment following operations

    // display()
    // add(x) / append(x)
    // Insert(index x)
    // delete(index x)
    // Search(x)
    // get(index)
    // set(index x)
    // max() / min()
    // reverse()
    // shift()/ rotate()

    // initialazion of array
    struct Array arr;
    cout << "Enter size of an array : ";
    cin >> arr.size;

    arr.A = new int[arr.size];
    arr.length = 0; // as no elemnt is there curretly

    int n;
    cout << "Enter the no of elements you want to enter : ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter " << i + 1 << "th element : ";
        cin >> arr.A[i];
    }

    arr.length = n;

    Display(arr);

    return 0;
}