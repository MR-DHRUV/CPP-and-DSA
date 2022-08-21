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

void swap(int *p1, int *p2)
{
    int temp = *p1;
    *p1 = *p2;  
    *p2 = temp;
}

int linearSearch(struct Array *arr, int key)
{
    int index = 0;

    for (int i = 0; i < arr->length; i++)
    {
        if (arr->A[i] == key)
        {

            // int temp = arr->A[i];
            // arr->A[i] = arr->A[i - 1];
            // arr->A[i - 1] = temp;

            // better method
            swap(&arr->A[i], &arr->A[0]);

            return i;
        }
    }

    // when an element is search, its a high prbability that it will be searched again, so it is moved 1 index closer every time is is searched and ithis process is called transposition


    // another method is to brought the element searched to index 0 

    return -1;
};

int main()
{

    struct Array arr;
    arr.size = 10;
    arr.A = new int[arr.size];

    for (int i = 0; i < arr.size; i++)
    {
        arr.A[i] = i + 1;
    }

    arr.length = 10;
    Display(arr);

    cout << linearSearch(&arr, 5) << endl;
    Display(arr);
    cout << linearSearch(&arr, 11) << endl;
    cout << linearSearch(&arr, 1) << endl;

    return 0;
}