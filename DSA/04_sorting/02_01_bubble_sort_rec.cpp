#include <bits/stdc++.h>
using namespace std;

void bubbleSortRec(int *arr, int n)
{
    if (n == 0 || n == 1)
    {
        return;
    }

    // ith largest element ko end me pohuncha dega, so ab n-1 from starting ko hi sort krna haii 
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }

    return bubbleSortRec(arr, n - 1);
}

int main()
{
    int arr[] = {6, 8, 3, 5, 9, 2, 1, 2, 4, 0};

    bubbleSortRec(arr, 10);

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}