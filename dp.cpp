#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<vector<int>> dp;
    int solve(int i, int j, vector<int> &nums, int &cost)
    {
        if (i >= j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;
        if (nums[i] + nums[j] == cost)
            ans = 1 + solve(i + 1, j - 1, nums, cost);
        if (nums[i] + nums[i + 1] == cost)
            ans = max(ans, 1 + solve(i + 2, j, nums, cost));
        if (nums[j - 1] + nums[j] == cost)
            ans = max(ans, 1 + solve(i, j - 2, nums, cost));

        return dp[i][j] = ans;
    }

public:
    int maxOperations(vector<int> &nums)
    {
        // memset(dp, -1, sizeof(dp));
        dp.assign(2001, vector<int>(2001, -1));
        int cost = nums[0] + nums[1], ans = solve(2, nums.size() - 1, nums, cost);

        cost = nums[0] + nums.back();
        ans = max(ans, solve(1, nums.size() - 2, nums, cost));

        cost = nums.back() + nums[nums.size() - 2];
        ans = max(ans, solve(0, nums.size() - 3, nums, cost));

        return 1 + ans;
    }
};

int main()
{
  
  
    return 0;
}