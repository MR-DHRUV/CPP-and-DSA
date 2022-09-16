#include <bits/stdc++.h>
using namespace std;

// altest no of columns should be known
pair<int, int> binSearch(int arr[][3], int target, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (arr[i][j] == target)
            {
                pair<int, int> res;
                res.first = i;
                res.second = j;

                return res;
            }
        }
    }

    pair<int, int> res;
    res.first = -1;
    res.second = -1;

    return res;
}

int main()
{
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    cout << binSearch(arr, 5, 3, 3).first << endl;
    cout << binSearch(arr, 5, 3, 3).second << endl;

    return 0;
}