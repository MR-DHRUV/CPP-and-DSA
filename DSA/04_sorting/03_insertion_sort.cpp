#include <bits/stdc++.h>
using namespace std;

// insertion sort

// new array me daalo ek ek krke sorted order me

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

    return 0;
}