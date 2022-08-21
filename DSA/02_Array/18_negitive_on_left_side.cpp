#include <iostream>
using namespace std;

struct Array
{
    int A[10];
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

void negpos(struct Array *arr)
{
    int arrNew[arr->length];
    int j = arr->length - 1;
    int i = 0;

    while (arr->A[i] < 0)
    {
        i++;
        swap(&arr->A[i], &arr->A[j]);
    }

    while (arr->A[j] >= 0)
    {
        j--;

        swap(&arr->A[i], &arr->A[j]);
    }
}

int main()
{
    // same driver code
    struct Array arr = {2, 3, -1, -3, 2, -9, -8, 3, 4};

    arr.length = 9;
    Display(arr);

    negpos(&arr);
    Display(arr);

    return 0;
}

// not working /////////////////////////////////////////////