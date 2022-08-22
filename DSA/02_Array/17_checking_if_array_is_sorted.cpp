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

// inserting element in sorted array such that it reamins sorted
void SortedInsert(struct Array *arr, int element)
{
    int len = arr->length;

    if (len < arr->size)
    {
        // ulta start hoga loop
        // last se check karega small haii ya bada 
        // if element to be insterted small then element at  i-1 ko i pe copu krdega as i empty haii  and loopp will continue  
        // if element to be insterted larger then usse i pr laga dega aur break;  
        for (int i = len; i > 0; i--)
        {
            if (element < arr->A[i - 1])
            {
                arr->A[i] = arr->A[i - 1];
            }

            else
            {
                arr->A[i] = element;
                break;
            }
        }

        arr->length++;
    }
    else
    {
        cout << "Array is completely filled" << endl;
    }
}

int isSorted(struct Array arr)
{
    // last elemnt ke lie nahi chalana so length -1
    for (int i = 0; i < arr.length - 1; i++)
    {
        if (arr.A[i] > arr.A[i + 1])
        {
            return -1;
        }
    }

    return 1;
}

int main()
{
    // same driver code
    struct Array arr;
    arr.size = 10;
    arr.A = new int[arr.size];

    for (int i = 0; i < 8; i++)
    {
        arr.A[i] = (i + 1) * 2;
    }

    arr.length = 8;
    Display(arr);

    struct Array *ptr = &arr;

    SortedInsert(ptr, 10);
    Display(arr);
    cout << isSorted(arr) << endl;

    return 0;
}
