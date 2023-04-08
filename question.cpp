//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
    int solve(int tar, vector<int> &dp)
    {
        if (tar == 0)
            return 0;

        if (dp[tar] != -1)
            return dp[tar];

        int ans = tar; // 1 se bana dia tar baar 1 add krke

        for (int i = 1; i * i <= tar; i++)
        {
            if (tar - (i * i) >= 0)
                ans = min(ans, 1 + solve(tar - (i * i), dp));
        }

        return dp[tar] = ans;
    }

    int solveTab(int &n)
    {
        vector<int> dp(n + 1, 1e9);

        // base case
        dp[0] = 0;

        for (int tar = 1; tar <= n; tar++)
        {
            dp[tar] = tar; // 1 se bana dia tar baar 1 add krke

            for (int i = 1; i * i <= tar; i++)
            {
                if (tar - (i * i) >= 0)
                    dp[tar] = min(dp[tar], 1 + dp[tar - (i * i)]);
            }
        }

        return dp[n];
    }

public:
    int MinSquares(int n)
    {
        // vector<int> dp(n + 2, -1);
        return solveTab(n);
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        Solution ob;
        int ans = ob.MinSquares(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends