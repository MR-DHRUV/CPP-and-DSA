#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int solve(int i, bool buy, int cnt, vector<int> &prices, vector<vector<vector<int>>> &dp)
    {
        if ((cnt <= 0 && buy) || i == prices.size())
            return 0;

        if (dp[i][buy][cnt] != -1)
            return dp[i][buy][cnt];

        // ignore
        int ans = solve(i + 1, buy, cnt, prices, dp);

        if (buy)
        {
            ans = max(ans, solve(i + 1, false, cnt - 1, prices, dp) - prices[i]);
        }
        else
        {
            ans = max(ans, solve(i + 1, true, cnt, prices, dp) + prices[i]);
        }

        return dp[i][buy][cnt] = ans;
    }

    // O(N) time O(1) space 
    int solveTab(vector<int> &prices)
    {
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(2, vector<int>(3, 0)));

        for (int i = prices.size() - 1; i >= 0; i--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int count = 0; count <= 2; count++)
                {
                    if (!(count == 0 && buy))
                    {
                        dp[0][buy][count] = dp[1][buy][count];

                        if (buy)
                        {
                            dp[0][buy][count] = max(dp[0][buy][count], dp[1][false][count - 1] - prices[i]);
                        }
                        else
                        {
                            dp[0][buy][count] = max(dp[0][buy][count], dp[1][true][count] + prices[i]);
                        }
                    }
                }
            }

            dp[1] = dp[0];
        }

        return dp[0][true][2];
    }

public:
    int maxProfit(vector<int> &prices)
    {
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(3, -1)));

        return solve(0, true, 2, prices, dp);
    }
};

int main()
{

    return 0;
}