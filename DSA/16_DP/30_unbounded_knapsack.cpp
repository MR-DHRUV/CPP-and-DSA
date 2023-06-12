//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{

    int solve(int i, int W, int val[], int wt[], vector<vector<int>> &dp)
    {
        if (i < 0)
            return 0;

        if (dp[i][W] != -1)
            return dp[i][W];

        int ans = solve(i - 1, W, val, wt, dp);

        if (wt[i] <= W)
            ans = max(ans, (val[i] + solve(i, W - wt[i], val, wt, dp)));

        return dp[i][W] = ans;
    }

public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // here we can take any item any number of times
        // so here all we have to do is modify our take case such that we dont change the index as we can re concider that value
        vector<vector<int>> dp(N,vector<int>(W+1,-1));
        return solve(N - 1, W, val, wt, dp);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, W;
        cin >> N >> W;
        int val[N], wt[N];
        for (int i = 0; i < N; i++)
            cin >> val[i];
        for (int i = 0; i < N; i++)
            cin >> wt[i];

        Solution ob;
        cout << ob.knapSack(N, W, val, wt) << endl;
    }
    return 0;
}
// } Driver Code Ends