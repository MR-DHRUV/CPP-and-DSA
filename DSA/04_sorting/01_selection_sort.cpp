#include <bits/stdc++.h>

using namespace std;

// selection sort
// diffrent rounds , aur har round me smallest elemnt laate hain aur usse uski sahi jagah pr place krdete hain

// 64 25 12 22 11

// sorting begains
// i=0 pr sbse smallest value lagado by SWAPING them

// 11 25 12 22 64
// aise hi aage wo value lagado jo i = 0 se bada ho aur baakiyo se small

// 11 12 25 22 64
// sorted now , break loop

void selectionSort(vector<int> &arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        swap(arr[i], arr[minIndex]);
    }
}

void printArr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

void selectionSortrec(int *arr, int n)
{
    if (n == 0 || n == 1)
    {
        return;
    }

    int min = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < arr[min])
        {
            min = i;
        }
    }
    swap(arr[0], arr[min]);
    return selectionSortrec(arr + 1, n - 1);
}

// time complexity : O(n^2) always
// space complexity : O(1)

// jab bhi no of elements kam ho , humesha selection sort use karo
// jab bhi memory `kam ho , humesha selection sort use karo

int main()
{
    int arr[] = {6, 8, 3, 5, 9, 2, 1, 2, 4, 0};

    selectionSortrec(arr, 10);
    printArr(arr, 10);

    return 0;
}
