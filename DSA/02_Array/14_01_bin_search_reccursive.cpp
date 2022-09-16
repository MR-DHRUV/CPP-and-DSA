#include <iostream>
using namespace std;

int binarySearch(int *input, int n, int val)
{
    return binSRec(input, val, 0, n - 1);
}

int binSRec(int arr[], int target, int start, int end)
{

    if (target == 0)
    {   
        //for array of non -ve elements
        if (arr[0] == 0)
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }

    if (start == end && arr[start] != target)
    {
        return -1;
    }

    int mid = start + (end - start) / 2;
    if (arr[mid] == target)
    {
        return mid;
    }
    else if (arr[mid] > target)
    {
        return binSRec(arr, target, start, mid - 1);
    }
    else
    {
        return binSRec(arr, target, mid + 1, end);
    }
}

int main()
{

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    cout << binSRec(arr, 10, 0, 8);

    return 0;
}