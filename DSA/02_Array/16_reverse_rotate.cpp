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

void Reverse1(struct Array *arr)
{

    int arrNew[arr->length];
    int len = arr->length;

    for (int i = 0; i < arr->length; i++)
    {
        arrNew[i] = arr->A[len - 1];
        len--;
    }

    for (int j = 0; j < arr->length; j++)
    {
        arr->A[j] = arrNew[j];
    }

    // O(n)
}

void swap(int *p1, int *p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void Reverse2(struct Array *arr)
{
    // swaping last with fist
    int j = arr->length - 1;

    for (int i = 0; i < arr->length / 2; i++)
    {
        swap(&arr->A[i], &arr->A[j]);
        j--;
    }
}

// left shift : sabko 1 - 1 krke leftme kardo aur jo right me 1 space bacche waha 0 lagado

void Lshift(struct Array *arr)
{
    int i = 0;

    for (i; i < arr->length; i++)
    {
        arr->A[i] = arr->A[i + 1];
    }

    arr->A[arr->length - 1] = 0;
}

void Rshift(struct Array *arr)
{
    int i = arr->length;

    for (i; i > 0; i--)
    {
        arr->A[i] = arr->A[i - 1];
    }

    arr->A[0] = 0;
}

// Rotation : 1st element ko last me lagado;

void Rotate(struct Array *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int temp = arr->A[0];
        Lshift(arr);
        arr->A[arr->length - 1] = temp;
    }
}

int main()
{
    // same driver code
    struct Array arr;
    arr.size = 10;
    arr.A = new int[arr.size];

    for (int i = 0; i < arr.size; i++)
    {
        arr.A[i] = i + 1;
    }

    arr.length = 10;
    Display(arr);
    cout << endl;

    Display(arr);

    struct Array *ptr = &arr;

    Reverse1(ptr);
    Display(arr);
    cout << endl;

    Reverse2(ptr);
    Display(arr);

    // Lshift(ptr);
    // Display(arr);

    // Rshift(ptr);
    // Display(arr);

    Rotate(ptr, 4);
    Display(arr);

    return 0;
}
