#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int solve(int i, int j, string &text1, string &text2, vector<vector<int>> &dp)
    {
        if (i == text1.length() || j == text2.length())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        // if match
        if (text1[i] == text2[j])
        {
            return dp[i][j] = 1 + solve(i + 1, j + 1, text1, text2, dp);
        }

        // no match: I have 2 options either i will move i or j
        int ans = solve(i + 1, j, text1, text2, dp);
        ans = max(ans, solve(i, j + 1, text1, text2, dp));

        return dp[i][j] = ans;
    }

    int solveTab(string &text1, string &text2)
    {
        vector<vector<int>> dp(2, vector<int>(text2.length() + 1, 0));

        for (int i = text1.length() - 1; i >= 0; i--)
        {
            for (int j = text2.length() - 1; j >= 0; j--)
            {
                if (text1[i] == text2[j])
                {
                    dp[0][j] = 1 + dp[1][j + 1];
                }
                else
                {
                    // no match: I have 2 options either i will move i or j
                    dp[0][j] = dp[1][j];
                    dp[0][j] = max(dp[0][j], dp[0][j + 1]);
                }
            }

            dp[1] = dp[0];
        }

        return dp[0][0];
    }

public:
    int longestCommonSubsequence(string text1, string text2)
    {
        vector<vector<int>> dp(text1.length(), vector<int>(text2.length(), -1));
        return solve(0, 0, text1, text2, dp);
    }
};

int main()
{

    return 0;
}