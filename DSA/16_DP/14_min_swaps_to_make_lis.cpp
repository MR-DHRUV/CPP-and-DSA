#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // ek tarah ka brute force haii ki har index pr swap krke check krte hue aage ja rhe haii, sabse minimum swaps wala path return kardia humn

    int solve(int i, bool swapped, vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &dp)
    {
        // base case
        if (i == nums1.size())
            return 0;

        if (dp[i][swapped] != -1)
            return dp[i][swapped];

        int ans = 1e9;

        // determining previous elements
        int prev1 = nums1[i - 1], prev2 = nums2[i - 1];

        if (swapped)
            swap(prev1, prev2);

        // chek if we have to swap or not
        if (nums1[i] > prev1 && nums2[i] > prev2)
        {
            ans = solve(i + 1, false, nums1, nums2, dp);
        }

        // swap case : check if we can swap or not
        if (nums1[i] > prev2 && nums2[i] > prev1)
        {
            ans = min(ans, 1 + solve(i + 1, true, nums1, nums2, dp));
        }

        return dp[i][swapped] = ans;
    }

    // O(1) space, O(N) time
    int solveTab(vector<int> &nums1, vector<int> &nums2)
    {
        vector<vector<int>> dp(2, vector<int>(2, 0));

        for (int i = nums1.size() - 1; i >= 1; i--)
        {
            for (int swapped = 1; swapped >= 0; swapped--)
            {
                int ans = 1e9;

                // determining previous elements
                int prev1 = nums1[i - 1], prev2 = nums2[i - 1];

                if (swapped)
                    swap(prev1, prev2);

                // chek if we have to swap or not
                if (nums1[i] > prev1 && nums2[i] > prev2)
                {
                    ans = dp[1][0];
                }

                // swap case : check if we can swap or not
                if (nums1[i] > prev2 && nums2[i] > prev1)
                {
                    ans = min(ans, 1 + dp[1][1]);
                }

                dp[0][swapped] = ans;
            }

            dp[1] = dp[0];
        }

        return min(dp[1][0], dp[1][1]);
    }

    /*
        Runtime
        171 ms
        Beats
        98.67%
        Memory
        90.3 MB
        Beats
        83.23%
    */
    int solveTabMaxOpt(vector<int> &nums1, vector<int> &nums2)
    {
        int dp[2][2] = {0};

        for (int i = nums1.size() - 1; i >= 0; i--)
        {
            for (int swapped = 1; swapped >= 0; swapped--)
            {
                int ans = 1e9;

                // determining previous elements
                int prev1 = i - 1 < 0 ? -1 : (swapped ? nums2[i - 1] : nums1[i - 1]);
                int prev2 = i - 1 < 0 ? -1 : (swapped ? nums1[i - 1] : nums2[i - 1]);

                // chek if we have to swap or not
                if (nums1[i] > prev1 && nums2[i] > prev2)
                    ans = dp[1][0];

                // swap case : check if we can swap or not
                if (nums1[i] > prev2 && nums2[i] > prev1)
                    ans = min(ans, 1 + dp[1][1]);

                dp[0][swapped] = ans;
            }

            // row swap
            dp[1][0] = dp[0][0];
            dp[1][1] = dp[0][1];
        }

        return min(dp[1][0], dp[1][1]);
    }

public:
    int minSwap(vector<int> &nums1, vector<int> &nums2)
    {
        // vector<vector<int>> dp(nums1.size() + 1, vector<int>(2, -1));

        // nums1.insert(nums1.begin(), -1);
        // nums2.insert(nums2.begin(), -1);

        return solveTabMaxOpt(nums1, nums2);
    }
};

int main()
{

    return 0;
}