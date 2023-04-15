#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int solve(int i, int n, vector<int> &slices, vector<vector<int>> &dp)
    {
        if (i >= slices.size() || n <= 0)
            return 0;

        if (dp[i][n] != -1)
            return dp[i][n];

        // we can either eat this slice or not
        int ans = solve(i + 1, n, slices, dp);

        // eat
        ans = max(ans, slices[i] + solve(i + 2, n - 1, slices, dp));

        return dp[i][n] = ans;
    }

    int solveTab(vector<int> &slices)
    {
        int totalSlices = slices.size();
        int count = (slices.size()+1)/3;

        vector<vector<int>> dp(3, vector<int>((count) + 1, 0));

        for (int i = totalSlices - 1; i >= 0; i--)
        {
            for (int n = 1; n <= count; n++)
            {
                // we can either eat this slice or not
                int ans = dp[1][n];

                // eat
                ans = max(ans, slices[i] + dp[2][n - 1]);

                dp[0][n] = ans;
            }

            dp[2] = dp[1];
            dp[1] = dp[0];
        }

        return dp[0][count];
    }

public:
    int maxSizeSlices(vector<int> &slices)
    {
        int n = slices.size() / 3;

        auto s1 = slices, s2 = slices;
        s1.erase(s1.begin());
        s2.erase(s2.end() - 1);

        // vector<vector<int>> dp(slices.size() + 1, vector<int>(n + 1, -1));
        // int ans = solve(0, n, s1, dp);

        // dp = vector<vector<int>>(slices.size() + 1, vector<int>(n + 1, -1));
        // ans = max(ans, solve(0, n, s2, dp));

        int ans = max(solveTab(s1), solveTab(s2));

        return ans;
    }
};

int main()
{
    Solution obj;

    vector<int> a = {1, 2, 3, 4, 5, 6};
    cout << obj.maxSizeSlices(a);

    vector<vector<int>> cuboids = {
        {50, 45, 20},
        {95, 37, 53},
        {45, 23, 12}};

    // cout << obj.maxHeight(cuboids) << endl;

    return 0;
}