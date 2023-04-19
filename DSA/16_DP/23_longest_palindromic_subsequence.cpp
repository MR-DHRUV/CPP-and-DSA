#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int dp[1001][1001];

    int solve(int i, int j, string &s)
    {
        if (i == s.length() || j < 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        // if match
        if (s[i] == s[j])
        {
            return dp[i][j] = 1 + solve(i + 1, j - 1, s);
        }

        // no match: I have 2 options either i will move i or j
        int ans = solve(i + 1, j, s);
        ans = max(ans, solve(i, j - 1, s));

        return dp[i][j] = ans;
    }

    int solveTab(string s)
    {
        vector<vector<int>> dp(2, vector<int>(s.length() + 1, 0));

        for (int i = s.length() - 1; i >= 0; i--)
        {
            for (int j = 0; j < s.length(); j++)
            {
                // if match
                if (s[i] == s[j])
                {
                    dp[0][j] = 1;

                    if (j > 0)
                        dp[0][j] += dp[1][j - 1];
                }
                else
                {
                    // no match: I have 2 options either i will move i or j
                    dp[0][j] = dp[1][j];

                    if (j > 0)
                        dp[0][j] = max(dp[0][j], dp[0][j - 1]);
                }
            }

            dp[1] = dp[0];
        }

        return dp[0][s.length() - 1];
    }

public:
    int longestPalindromeSubseq(string s)
    {
        memset(dp,-1,sizeof(dp));
        return solve(0, s.length() - 1, s);
    }
};

int main()
{

    return 0;
}