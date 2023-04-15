#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int solve(int n, int time, vector<int> &satisfaction, vector<vector<int>> &dp)
    {
        if (n == satisfaction.size())
            return 0;

        if (dp[n][time] != -1)
            return dp[n][time];

        // include exclude game khelo bas

        // exclude
        int ans = solve(n + 1, time, satisfaction, dp);

        // include
        ans = max(ans, (satisfaction[n] * (time)) + solve(n + 1, time + 1, satisfaction, dp));

        return dp[n][time] = ans;
    }

    int solveTab(vector<int> &satisfaction)
    {
        vector<vector<int>> dp(satisfaction.size() + 2, vector<int>(satisfaction.size() + 2, 0));

        for (int n = satisfaction.size() - 1; n >= 0; n--)
        {
            for (int time = n + 1; time >= 1; time--)
            {
                // exclude
                int ans = dp[n + 1][time];

                // include
                ans = max(ans, (satisfaction[n] * (time)) + dp[n + 1][time + 1]);

                dp[n][time] = ans;
            }
        }

        return dp[0][1];
    }

    int solveTabSpOpt(vector<int> &satisfaction)
    {
        vector<vector<int>> dp(2, vector<int>(satisfaction.size() + 2, 0));

        for (int n = satisfaction.size() - 1; n >= 0; n--)
        {
            for (int time = n + 1; time >= 1; time--)
            {
                dp[0][time] = max(dp[1][time], (satisfaction[n] * (time)) + dp[1][time + 1]);
            }

            dp[1] = dp[0];
        }

        return dp[0][1];
    }

    int solveTabSpOpt1(vector<int> &satisfaction)
    {
        vector<int> dp(satisfaction.size() + 2, 0);

        for (int n = satisfaction.size() - 1; n >= 0; n--)
        {
            int prev = dp[n + 2];

            for (int time = n + 1; time >= 1; time--)
            {
                int temp = prev;
                prev = dp[time];

                dp[time] = max(dp[time], (satisfaction[n] * (time)) + temp);
            }
        }

        return dp[1];
    }

    // best approach
    int solveGreedy(vector<int> &satisfaction)
    {
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());

        // We will keep cooking all most satisfied dishes until
        // we find a dish that is so worst that it will make all of our
        // total satisfaction of dishes cooked till now negative
        // i.e worst satisfaction will be achieved if we took that dish so break out.

        int result = 0, total = 0;

        for (int dish = n - 1; dish >= 0; --dish)
        {
            if (satisfaction[dish] + total < 0)
            {
                // Worst dish encountered.
                break;
            }
            else
            {
                total += satisfaction[dish];
                result += total;
            }
        }

        return result;
    }

public:
    int maxSatisfaction(vector<int> &satisfaction)
    {
        sort(satisfaction.begin(), satisfaction.end());
        return solveTab(satisfaction);
    }
};

int main()
{
    Solution obj;

    vector<int> a = {4, 3, 2};
    cout << obj.maxSatisfaction(a);

    return 0;
}