#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int solve(int i, int sum, vector<int> &arr, vector<vector<int>> &dp)
{
    // base case
    if (i == 0)
    {
        // handling zero elements
        if (sum == 0 && arr[0] == 0)
            return 2;

        else if (sum == 0 || sum - arr[i] == 0)
            return 1;

        return 0;
    }

    if (dp[i][sum] != -1)
        return dp[i][sum];

    int notTake = solve(i - 1, sum, arr, dp);
    int take = sum - arr[i] >= 0 ? solve(i - 1, sum - arr[i], arr, dp) : 0;

    return dp[i][sum] = (take + notTake) % mod;
}

int findWays(vector<int> &nums, int target)
{
    vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));
    return solve(nums.size() - 1, target, nums, dp);
}

int countPartitions(int n, int d, vector<int> &arr)
{
    int total = 0;

    for (int &i : arr)
        total += i;

    // no we need to make 2 arrays such that s1-s2 == d and s1 > s2

    // s1-s2 = d
    // (total-s2) -s2 = d
    // total-d = 2 s2
    // total-d/2 = s2

    // so now we have to find no of subarrays with sum total-d/2
    // if total-d is not divisible by 2 then the ans is 0 as we cant partition the array
    if ((total - d) < 0 || (total - d) % 2 != 0)
        return 0;

    return findWays(arr, (total - d) / 2);
}

int main()
{

    return 0;
}