#include <bits/stdc++.h>
using namespace std;

class Solution
{
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
    
public:
    int countSubsetsWithGivenSum(vector<int> &nums, int target)
    {
        vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));
        return solve(nums.size() - 1, target, nums, dp);
    }
};

int main()
{

    return 0;
}