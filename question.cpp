//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{

    int solve(int l, int price[], vector<int> &dp)
    {
        if (l <= 0)
            return 0;

        if (dp[l] != -1)
            return dp[l];

        // no cut
        int ans = price[l - 1];

        // cut
        for (int i = 1; i < l; i++)
        {
            ans = max(ans, price[i] + solve(l - i, price, dp));
        }

        return dp[l] = ans;
    }

public:
    int cutRod(int price[], int n)
    {
        vector<int> dp(n + 1, -1);
        return solve(n, price, dp);
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
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends