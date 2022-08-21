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

int Length(struct Array arr)
{
    int len = 0;
    int i = 0;

    while (arr.A[i])
    {
        len++;
        i++;
    }

    return len;
}

struct Array *Union(struct Array arr1, struct Array arr2)
{
    struct Array *arr3;
    arr3 = new struct Array[sizeof(struct Array)];
    arr3->size = arr1.length + arr2.length;

    int i = 0;

    for (; i < arr1.length; i++)
    {
        arr3->A[i] = arr1.A[i];
    }

    int duplicacy = 0;
    // 2nd array cant be copied blindly as we cant add duplicate elements

    for (int j = 0; j < arr2.length; j++)
    {
        bool same = false;

        for (int k = 0; k < arr1.length; k++)
        {

            if (arr3->A[k] == arr2.A[j])
            {
                same = true;
                duplicacy++;
            }
        }

        if (same == false)
        {
            arr3->A[i] = arr2.A[j];
            i++;
        }
    }

    // so that no trash elment is printed
    arr3->length = arr1.length + arr2.length - duplicacy;

    return arr3;

    // O(n^2)
};

struct Array *SortedUnion(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;

    struct Array *arr3;
    arr3 = new struct Array[sizeof(struct Array)];
    arr3->size = 10;

    int duplicacy = 0;

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] == arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
            duplicacy++;
        }

        else if (arr1->A[i] < arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
        }
        else
        {
            arr3->A[k++] = arr2->A[j++];
        }
    }

    for (; i < arr1->length; i++)
    {
        arr3->A[k++] = arr1->A[i];
    }
    for (; j < arr2->length; j++)
    {
        arr3->A[k++] = arr2->A[j];
    }

    // so that no trash elment is printed
    arr3->length = arr1->length + arr2->length - duplicacy;

    return arr3;
    // O(n)
}

// if  unsorted array is given the unsorted array is result
// if  sorted array is given the sorted array is result
struct Array *Intersection(struct Array arr1, struct Array arr2)
{

    struct Array *arr3;
    arr3 = new struct Array[sizeof(struct Array)];
    arr3->size = 10;

    int length = 0;

    for (int i = 0; i < arr1.length; i++)
    {
        for (int j = 0; j < arr2.length; j++)
        {
            if (arr2.A[j] == arr1.A[i])
            {
                arr3->A[length] = arr1.A[i];
                length++;
            }
        }
    }

    arr3->length = length;
    return arr3;
    // O(n^2)
}

// arr1 - arr2
struct Array *Diffrence(struct Array arr1, struct Array arr2)
{

    struct Array *arr3;
    arr3 = new struct Array[sizeof(struct Array)];
    arr3->size = 10;

    int length = 0;

    for (int i = 0; i < arr1.length; i++)
    {
        bool isPresent = false;

        for (int j = 0; j < arr2.length; j++)
        {
            if (arr2.A[j] == arr1.A[i])
            {
               isPresent = true;
            }
        }

        if(isPresent == false){
            arr3->A[length] = arr1.A[i];
            length++;
        }
    }

    arr3->length = length;
    return arr3;
    // O(n^2)
};

int main()
{
    struct Array arr1 = {{2, 6, 10, 15, 25, 35 , 45}, 10, 7};
    struct Array arr2 = {{10, 15, 20, 25, 30}, 10, 5};
    struct Array *arr3;
    struct Array *arr4;

    arr3 = Intersection(arr1, arr2);
    Display(*arr3);

    arr4 = Diffrence(arr1, arr2);
    Display(*arr4);

    return 0;
}
