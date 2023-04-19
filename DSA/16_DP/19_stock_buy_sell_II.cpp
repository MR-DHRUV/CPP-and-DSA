#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int solve(int i, bool buy, vector<int> &prices, vector<vector<int>> &dp)
    {
        // base case
        if (i == prices.size())
            return 0;

        if (dp[i][buy] != -1)
            return dp[i][buy];

        // at any day i can either buy/sell or ignore

        int ans = solve(i + 1, buy, prices, dp); // ignore

        if (buy)
        {
            ans = max(ans, solve(i + 1, false, prices, dp) - prices[i]); // i pr kharid lia
        }
        else
        {
            // selling
            ans = max(ans, prices[i] + solve(i + 1, true, prices, dp));
        }

        return dp[i][buy] = ans;
    }

    // O(N) time and O(1) space
    int solveTab(vector<int> &prices)
    {
        vector<vector<int>> dp(2, vector<int>(2, 0));

        for (int i = prices.size() - 1; i >= 0; i--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                int ans = dp[1][buy]; // ignore

                if (buy)
                {
                    ans = max(ans, dp[1][false] - prices[i]); // i pr kharid lia
                }
                else
                {
                    // selling
                    ans = max(ans, prices[i] + dp[1][true]);
                }

                dp[0][buy] = ans;
            }

            dp[1] = dp[0];
        }

        return dp[0][1];
    }

public:
    int maxProfit(vector<int> &prices)
    {
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2, -1));
        return solve(0, true, prices, dp);
    }
};

int main()
{

    return 0;
}