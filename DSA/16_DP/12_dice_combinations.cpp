//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    long long solve(int n, int sum, int &m, int &x, vector<vector<long long>> &dp)
    {
        // base condition
        if (n == 0 || sum > x)
        {
            if (sum == x)
                return 1;

            return 0;
        }

        if (dp[n][sum] != -1)
            return dp[n][sum];

        long long ans = 0;

        for (int i = 1; i <= m; i++)
        {
            if (sum + i <= x)
                ans += solve(n - 1, sum + i, m, x, dp);
        }

        return dp[n][sum] = ans;
    }

    long long solveTab(int &N, int &m, int &x)
    {
        vector<vector<long long>> dp(2, vector<long long>((N * 1ll * x) + 2, 0));
        dp[1][x] = 1;

        for (int n = 1; n <= N; n++)
        {
            for (int sum = x; sum >= 0; sum--)
            {
                long long ans = 0;

                for (int i = 1; i <= m; i++)
                {
                    if (sum + i <= x)
                        ans += dp[1][sum + i];
                }

                dp[0][sum] = ans;
            }

            dp[1] = dp[0];
        }

        return dp[1][0];
    }

public:
    long long noOfWays(int M, int N, int X)
    {
        // code here
        // N dic haii with M faces
        // total combinations will be N*M
        vector<vector<long long>> dp(N + 1, vector<long long>((N * 1ll * X) + 2, -1));
        return solve(N, 0, M, X, dp);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int M, N, X;

        cin >> M >> N >> X;

        Solution ob;
        cout << ob.noOfWays(M, N, X) << endl;
    }
    return 0;
}
// } Driver Code Ends