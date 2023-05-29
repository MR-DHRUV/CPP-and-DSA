#include <bits/stdc++.h>
using namespace std;

int LIS(int arr[], int n)
{
    vector<int> temp;
    temp.push_back(arr[0]);

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > temp.back())
        {
            temp.push_back(arr[i]);
        }
        else
        {
            // stl :: lower_bound returns the index of element that is just greater than it in a sorted array using binary search
            // lower bound returns address of that location
            // so index = add - base address
            int index = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[index] = arr[i];
        }
    }

    return temp.size();
}

int main()
{
    

    return 0;
}