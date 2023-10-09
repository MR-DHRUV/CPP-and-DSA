#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numOfArrays(int n, int m, int k)
    {
        const int mod = 1e9 + 7;

        vector<vector<int>> dp(m + 1, vector<int>(k + 1, 0));
        vector<vector<int>> pfx(m + 1, vector<int>(k + 1, 0));
        vector<vector<int>> prevDp(m + 1, vector<int>(k + 1, 0));
        vector<vector<int>> prevPfx(m + 1, vector<int>(k + 1, 0));

        for (int j = 1; j <= m; j++)
        {
            prevDp[j][1] = 1;
            prevPfx[j][1] = j;
        }

        for (int _ = 2; _ <= n; _++)
        {
            dp.assign(m + 1, vector<int>(k + 1, 0));
            pfx.assign(m + 1, vector<int>(k + 1, 0));

            for (int maxNum = 1; maxNum <= m; maxNum++)
            {
                for (int cost = 1; cost <= k; cost++)
                {
                    dp[maxNum][cost] = (static_cast<long long>(maxNum) * prevDp[maxNum][cost]) % mod;

                    if (maxNum > 1 && cost > 1)
                    {
                        dp[maxNum][cost] = (dp[maxNum][cost] + prevPfx[maxNum - 1][cost - 1]) % mod;
                    }

                    pfx[maxNum][cost] = (pfx[maxNum - 1][cost] + dp[maxNum][cost]) % mod;
                }
            }

            prevDp = dp;
            prevPfx = pfx;
        }

        return pfx[m][k];
    }
};

int main()
{

    return 0;
}