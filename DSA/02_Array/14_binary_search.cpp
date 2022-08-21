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

int binarySearch(struct Array arr, int key)
{
    // to perform binary search the key condition is that the array must be sorted in assending order

    // to perform binary search we need 3 variables
    // low = index of smallest element
    // high = index of largest element
    // middle = low+high/2

    // concepts : low = mid + 1
    // concepts : high = mid - 1
    // concepts : divide list by 2 every time in this method

    // init
    int low = 0;
    int high = arr.length;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr.A[mid] == key)
        {
            return mid;
        }

        else if (arr.A[mid] > key)
        {
            high = mid - 1;
        }

        else
        {
            low = mid + 1;
        }
    }

    return -1;
};

int binarySearchReccursive(struct Array arr,int low, int high, int key)
{

    int mid = (low + high) / 2;

    if (arr.A[mid] == key)
    {
        return mid;
    }

    else if (arr.A[mid] > key)
    {
        return binarySearchReccursive(arr, low, mid - 1, key);
    }

    else
    {
        return binarySearchReccursive(arr, mid +1, high, key);
    }

    return -1;
};

// Complexity of binary search  for both methods are same;
//  best = O(1)
//  worst = O(log2N) log N base 2

int main()
{

    struct Array arr;
    arr.size = 11;
    arr.A = new int[arr.size];

    for (int i = 0; i < arr.size; i++)
    {
        arr.A[i] = i + 1;
    }

    arr.length = 11;
    Display(arr);
    cout<<endl;

    cout << binarySearch(arr, 2) << endl;
    cout << binarySearch(arr, 3) << endl;
    cout << binarySearch(arr, 4) << endl;
    cout << binarySearch(arr, 5) << endl;
    cout << binarySearch(arr, 6) << endl;
    cout << binarySearch(arr, 7) << endl;
    cout << binarySearch(arr, 8) << endl;

    cout<<endl;

    cout << binarySearchReccursive(arr,0, arr.length ,2) << endl;
    cout << binarySearchReccursive(arr,0, arr.length ,3) << endl;
    cout << binarySearchReccursive(arr,0, arr.length ,4) << endl;
    cout << binarySearchReccursive(arr,0, arr.length ,5) << endl;
    cout << binarySearchReccursive(arr,0, arr.length ,6) << endl;
    cout << binarySearchReccursive(arr,0, arr.length ,7) << endl;
    cout << binarySearchReccursive(arr,0, arr.length ,8) << endl;

    return 0;
}

// average case analysis of binary search
// time complexity : logN
