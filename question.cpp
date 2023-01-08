//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    long long countPairs(int n, int arr[], int k)
    {
        // Approach
        // we need pairs that whose difference is divisible by k
        // if we find out modulo k of each no in the array and store is count in a hash table
        // say k=4 and 3 is occuring 4 times, that means if we subtract one 3 from another we'll get 0 that will be divisible by 4
        // say one of the 3 corresponds to 7 (7%4 = 3) and another to 3 (3%3 = 3) itself and the the abs(7-3) = 4 and 4%4 = 0, thus we can say that jinka modulo k equal haii unka difference is divisible by k

        // no of elements corresponding to any value will be n(n-1)/2
        // say 3 elemensts haii toh
        // abs(3a-3b) , abs(3b-3c) and abs(3a-3c) are only pairs
        // 3 * 2 / 2 = 3 gives our result

        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            arr[i] = arr[i] % k;
            mp[arr[i]]++;
        }

        long long ans;
        for (auto i : mp)
        {
            ans += (i.second * (i.second - 1)) / 2;
        }

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
        int n, k;
        cin >> n;

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        cin >> k;

        Solution ob;
        cout << ob.countPairs(n, arr, k) << endl;
    }
    return 0;
}
// } Driver Code Ends