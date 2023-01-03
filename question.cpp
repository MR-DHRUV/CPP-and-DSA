//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{

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
                // stl :: lower_bound returns the index of element that is just greater than it ina sorted array using binary search
                // lower bound returns address of that location
                // so index = add - base address
                int index = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
                temp[index] = arr[i];
            }
        }

        return temp.size();
    }

public:
    int removeStudents(int H[], int N)
    {

        int ans = N - LIS(H, N);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;

        int H[N];
        for (int i = 0; i < N; i++)
            cin >> H[i];

        Solution ob;
        cout << ob.removeStudents(H, N) << endl;
    }
    return 0;
}
// } Driver Code Ends