#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int solve(int s, int e, vector<vector<int>> &dp)
    {
        if (s >= e)
            return 0; // 1 hi posibility haii so koi cost nahi lagegi is stage par

        if (dp[s][e] != -1)
            return dp[s][e];

        // start to pick each no to get min nas of this interval
        int ans = 1e9;

        for (int i = s; i <= e; i++)
        {
            // say I pick i this time then

            // i+ as wrong ans tha toh ab bacche hue cases dekh rahe haii
            // baccha hue cases me se bhi koi ek hi ans hoga, as we have to cover worst case we'll choose one with maximum cost
            ans = min(ans, i + max(solve(s, i - 1, dp), solve(i + 1, e, dp)));
        }

        return dp[s][e] = ans;
    }

    int solveTab(int n)
    {
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for (int s = n; s >= 1; s--)
        {
            for (int e = 1; e <= n; e++)
            {
                int ans = 1e9;

                if (s >= e)
                {
                    ans = 0;
                }
                else
                {
                    for (int i = s; i <= e; i++)
                    {
                        ans = min(ans, i + max(dp[s][i - 1], dp[i + 1][e]));
                    }
                }

                dp[s][e] = ans;
            }
        }

        return dp[1][n];
    }

public:
    int getMoneyAmount(int n)
    {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        // we have to try each number such that cost of all posiblilies comes out to be minimun
        return solve(1, n, dp);
    }
};

int main()
{

    return 0;
}