#include <bits/stdc++.h>
using namespace std;

void bucketSort(float arr[], int n)
{

    // Create n empty buckets
    vector<float> b[n];

    // Put array elements in different buckets
    for (int i = 0; i < n; i++)
    {
        // Calculate index in bucket
        int bi = n * arr[i]; 
        
        b[bi].push_back(arr[i]);
    }

    // 3) Sort individual buckets
    for (int i = 0; i < n; i++)
        sort(b[i].begin(), b[i].end());

    // 4) Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < b[i].size(); j++)
            arr[index++] = b[i][j];
}

int main()
{
    // Bucket sort is mainly useful to sort a large set of floating point numbers which are in range from 0.0 to 1.0 and are uniformly distributed across the range.

    return 0;
}