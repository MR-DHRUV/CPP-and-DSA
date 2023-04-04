#include <bits/stdc++.h>
using namespace std;

int solveMem(int i, vector<int> &nums, vector<int> &dp)
{
    if (i >= nums.size())
        return 0;

    // base case
    if (i >= nums.size() - 2)
        return dp[i] = nums[i];

    if (dp[i] != -1)
        return dp[i];

    return dp[i] = nums[i] + max(solveMem(i + 2, nums, dp), solveMem(i + 3, nums, dp));
}

int solveTab(vector<int> &nums)
{
    int n = nums.size();

    // space optimization
    vector<int> dp(3, 0);
    dp[1] = nums[n - 1];
    dp[0] = nums[n - 2];

    // everytime we can either include n-2 or n-3 so we'll keep max everytime
    for (int i = n - 3; i >= 0; i--)
    {
        int currSum = nums[i] + max(dp[1], dp[2]);

        // update dp
        dp[2] = dp[1];
        dp[1] = dp[0];
        dp[0] = currSum;
    }

    // max ans can be from 0 or 1
    return max(dp[0], dp[1]);
}

int maximumNonAdjacentSum(vector<int> &nums)
{
    vector<int> dp(nums.size() + 1, -1);
    return max(solveMem(0, nums, dp), solveMem(1, nums, dp));
}

int main()
{
    // Solution obj;

    vector<int> a = {4, 0, 8, 10, 5, 6};

    cout << maximumNonAdjacentSum(a);
    return 0;
}