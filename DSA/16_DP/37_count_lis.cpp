#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int countLis(vector<int> &nums)
    {
        vector<int> dp(nums.size(), 1), cnt(nums.size(), 0);

        int len = 1;

        for (int i = 0; i < nums.size(); i++)
        {
            for (int prev = 0; prev < i; prev++)
            {
                if (nums[i] > nums[prev] && dp[prev] + 1 > dp[i])
                {
                    dp[i] = 1 + dp[prev];
                    cnt[i] = cnt[prev];
                }
                else if (nums[i] > nums[prev] && dp[prev] + 1 == dp[i])
                {
                    cnt[i] += cnt[prev];
                }
            }

            len = max(len, dp[i]);
        }

        int ans = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (dp[i] == len)
                ans += cnt[i];
        }

        return ans;
    }
};

int main()
{

    return 0;
}