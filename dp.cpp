#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int solve(int s, vector<int> &arr, int &k, vector<int> &dp)
    {
        if (s >= arr.size())
            return 0;

        if (dp[s] != -1)
            return dp[s];

        int ans = 0;

        // max partition can be of size k
        for (int part = s; part < s + k && part < arr.size(); part++)
        {
            int maxEle = arr[s];

            for (int i = s; i <= part; i++)
            {
                maxEle = max(maxEle, arr[i]);
            }

            ans = max(ans, (maxEle * (part - s + 1) + solve(part + 1, arr, k, dp)));
        }

        return dp[s] = ans;
    }

    int solveTab(vector<int> &arr, int k)
    {
        int dp[501] = {0};
        int maxEle[501][501] = {0};

        for (int i = 0; i < arr.size(); i++)
        {
            int maxi = arr[i];
            for (int j = i; j < arr.size(); j++)
            {
                maxi = max(maxi, arr[j]);
                maxEle[i][j] = maxi;
            }
        }

        for (int s = arr.size() - 1; s >= 0; s--)
        {
            // max partition can be of size k
            for (int part = s; part < s + k && part < arr.size(); part++)
            {
                dp[s] = max(dp[s], (maxEle[s][part] * (part - s + 1) + dp[part + 1]));
            }
        }

        return dp[0];
    }

public:
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        vector<int> dp(arr.size() + 1, -1);
        return solve(0, arr, k, dp);
    }
};

int main()
{

    return 0;
}