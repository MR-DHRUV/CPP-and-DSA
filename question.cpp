//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // Function to reverse every sub-array group of size k.
    void reverseInGroups(vector<long long> &arr, int n, int k)
    {
        // code here

        if (k >= n)
        {
            reverse(arr.begin(), arr.end());
        }

        else
        {
            vector<long long>::iterator it = arr.begin();

            while (it+k < arr.end())
            {
                reverse(it, it + k);
                it += k;
            }

            cout<<(it - arr.begin())<<endl;

            if (it < arr.end())
            {
                reverse(it, arr.end());
            }
        }
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> arr;
        int k;
        cin >> k;

        for (long long i = 0; i < n; i++)
        {
            long long x;
            cin >> x;
            arr.push_back(x);
        }
        Solution ob;
        ob.reverseInGroups(arr, n, k);

        for (long long i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends

// 36 93 64 48 96 55 70 0 82 30 16 22 38 53 19 50 91 43 70 88 10 57 14 94 13 36 59 32 54 58 18 82 67
// Your Output: 
// 38 22 16 30 82 0 70 55 96 48 64 93 36 36 13 94 14 57 10 88 70 43 91 50 19 53 0 0 0 0 0 0 67 
// Expected Output: 
// 38 22 16 30 82 0 70 55 96 48 64 93 36 36 13 94 14 57 10 88 70 43 91 50 19 53 67 82 18 58 54 32 59 