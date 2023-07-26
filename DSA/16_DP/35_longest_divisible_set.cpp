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

    // this code will work for printing lis(koi bhi 1 print krdega)
    vector<int> solveTab(vector<int> &nums)
    {
        // based on lis approach
        sort(nums.begin(), nums.end());

        // since we have sorted the array, we ony need to check next%prev as 8%4 = 0 but 4%8 != 0
        // also we dont need to check for whole array as if say 1,4 belongs to subset and next element is 16

        // then 16%4 = 0 and since its divisible by previous element and previous element belongs to set that means 16 will be divisibe by all previous elements of the set

        // Now all we need is a longest divisible subsequence
        vector<int> dp(nums.size(), 1), hash(nums.size());

        // hash[i] means the lis at index i has previous element at index hash[i];

        int len = 1, lastIndex = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            hash[i] = i; // say lis at index i is of len = 1

            for (int prev = 0; prev < i; prev++)
            {
                if (nums[i] % nums[prev] == 0 && dp[prev] + 1 > dp[i])
                {
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }

            // tracking lis start
            if (dp[i] > len)
            {
                len = dp[i];
                lastIndex = i;
            }
        }

        // reverse enginner to make array
        vector<int> ans(len--);
        ans[len--] = nums[lastIndex];

        while (hash[lastIndex] != lastIndex)
        {
            lastIndex = hash[lastIndex];
            ans[len--] = (nums[lastIndex]);
        }
        return ans;
    }

public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<int> ans, dp(nums.size() + 1, -1);
        solve(0, {}, nums, dp, ans);
        return ans;
    }
};

int main()
{

    return 0;
}