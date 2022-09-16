#include <bits/stdc++.h>
using namespace std;

void printArr(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" "; 
    }

    cout<<endl;
    
}


// insertion sort
// inserting an element in an sorted array at sorted position

// first i elements sort hote hain 1-1 krke

//  8 5 7 3 2
//  8 5 7 3 2
//  5 8 7 3 2
//  5 7 8 3 2
//  3 5 7 8 2
//  2 3 5 7 8

void insertionSort(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        int temp = arr[i];
        int j = i - 1;

        for (; j >= 0; j--)
        {
            if (arr[j] > temp)
            {
                arr[j + 1] = arr[j];
            }
            else
            {
                break;
            }
        }

        // j+1 islie hua kyuki else wale case me ek aur baar peeeche chala jayga 
        arr[j + 1] = temp;

        printArr(arr);
    }
}

// time complexity : O(n^2);
// space complexity : O(1);

// best case time complexity: O(n)


// why insertion sort
// with time array gets sorted;
// stable and adaptive algo 

int main()
{
    vector<int> arr = {6, 8, 3, 5, 9, 2, 1, 2, 4, 0};

    insertionSort(arr);

    return 0;
}


// adaptive
// stable
// designed for linked list