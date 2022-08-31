#include <iostream>
using namespace std;

int floor(int arr[], int n, int target)
{
    int i = 0;

    int j = n - 1;

    if (target > arr[n-1])
    {
        return arr[n-1];
    }

    while (i <= j)
    {
        int mid = (i + j) / 2;

        if (arr[mid] == target)
        {
            return arr[mid];
        }

        else if (target > arr[mid - 1] && arr[mid] > target)
        {
            return arr[mid - 1];
        }
        else if (arr[mid] > target)
        {
            j = mid - 1;
        }

        else if (arr[mid] < target)
        {
            i = mid + 1;
        }
    }

    return -1;
}


int floorKunal(int arr[], int n, int target)
{
    int i = 0;

    int j = n - 1;

    if (target <= 0)
    {
        return arr[0];
    }

       while (i <= j)
    {
        int mid = (i + j) / 2;

        if (arr[mid] == target)
        {
            return arr[mid];
        }

        else if (arr[mid] < target)
        {
            i = mid + 1;
        }

        else if (arr[mid] > target)
        {
            j = mid - 1;
        }

    }

    return arr[j];
}




int main()
{
    int arr[] = {1, 2, 3, 5, 6, 7, 9, 23, 56};

    cout << floor(arr, 9, 1) << endl;
    cout << floor(arr, 9, 2) << endl;
    cout << floor(arr, 9, 4) << endl;
    cout << floor(arr, 9, 60) << endl;
    cout << floor(arr, 9, 22) << endl;
    cout << floor(arr, 9, 23) << endl;
    cout << floor(arr, 9, 50) << endl;


    cout << floorKunal(arr, 9, 1) << endl;
    cout << floorKunal(arr, 9, 2) << endl;
    cout << floorKunal(arr, 9, 4) << endl;
    cout << floorKunal(arr, 9, 60) << endl;
    cout << floorKunal(arr, 9, 22) << endl;
    cout << floorKunal(arr, 9, 23) << endl;
    cout << floorKunal(arr, 9, 50) << endl;

    return 0;
}