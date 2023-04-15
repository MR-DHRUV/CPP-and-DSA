#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int solve(int i, int j, vector<int> &v)
    {
        // base case
        if (i + 1 == j)
            return 0;

        int ans = INT_MAX;

        for (int k = i + 1; k < j; k++)
        {
            ans = min(ans, v[i] * v[j] * v[k] + solve(i, k, v) + solve(k, j, v));
        }

        return ans;
    }

    int solveMem(int i, int j, vector<int> &v, vector<vector<int>> &dp)
    {
        // base case
        if (i + 1 == j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = INT_MAX;

        for (int k = i + 1; k < j; k++)
        {
            ans = min(ans, (v[i] * v[j] * v[k]) + solveMem(i, k, v, dp) + solveMem(k, j, v, dp));
        }

        return dp[i][j] = ans;
    }

    int solveTab(vector<int> &v)
    {
        int n = v.size();

        // base case already covered as dp is init to 0
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; i--)
        {
            // i+2 as triangle minimum 3 nodes se banega
            for (int j = i + 2; j < n; j++)
            {
                int ans = INT_MAX;

                for (int k = i + 1; k < j; k++)
                {
                    ans = min(ans, (v[i] * v[j] * v[k]) + dp[i][k] + dp[k][j]);
                }

                dp[i][j] = ans;
            }
        }

        // initialy memoization jab kr rhe the toh yehi call ki thi
        return dp[0][n - 1];
    }

public:
    int minScoreTriangulation(vector<int> &values)
    {
        // int n = values.size();
        // vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        // return solveMem(0, n - 1, values, dp);

        return solveTab(values);
    }
};

int main()
{

    return 0;
}