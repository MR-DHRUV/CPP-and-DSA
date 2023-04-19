#include <bits/stdc++.h>
using namespace std;

class Solution
{   
    // 20_stock... wali approach haii same to same 
    int solveTab(vector<int> &prices, int k)
    {
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(2, vector<int>(k + 1, 0)));

        for (int i = prices.size() - 1; i >= 0; i--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int count = 0; count <= k; count++)
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

        return dp[0][true][k];
    }

public:
    int maxProfit(int k, vector<int> &prices)
    {
        return solveTab(prices, k);
    }
};

int main()
{

    return 0;
}