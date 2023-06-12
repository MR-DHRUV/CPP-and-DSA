#include <bits/stdc++.h>
using namespace std;

class Solution
{
    static inline auto max(vector<int> a, vector<int> b)
    {
        if (a.size() > b.size())
            return a;

        return b;
    }

    void solve(int i, vector<int> sub, vector<int> &nums, vector<int> &dp, vector<int> &res)
    {
        if (i >= nums.size())
        {
            res = max(res, sub);
            return;
        }

        int last = sub.size() == 0 ? 1 : sub.back();

        if ((int)sub.size() > dp[i] && (nums[i] % last == 0))
        {
            dp[i] = sub.size();

            sub.push_back(nums[i]);
            solve(i + 1, sub, nums, dp, res);

            // backtrack
            sub.pop_back();
        }

        // exclude case
        solve(i + 1, sub, nums, dp, res);
    }

public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        vector<int> ans, dp(nums.size() + 1, -1);
        solve(0, {}, nums, dp, ans);
        return ans;
    }
};

int main()
{

    return 0;
}