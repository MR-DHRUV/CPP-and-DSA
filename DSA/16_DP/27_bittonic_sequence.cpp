//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    int solve(int i, int last, bool isInc, vector<int> &nums, vector<vector<vector<int>>> &dp)
    {
        // base case
        if (i == nums.size())
            return 0;

        if (dp[i][last + 1][isInc] != -1)
            return dp[i][last + 1][isInc];

        // exclude case
        int ans = solve(i + 1, last, isInc, nums, dp);

        // include case

        // either this is first element or part of increasing subsequence
        if (last == -1 || (nums[i] > nums[last] && isInc))
        {
            ans = max(ans, 1 + solve(i + 1, i, isInc, nums, dp));
        }
        // start decresing from here
        else if (nums[i] < nums[last])
        {
            ans = max(ans, 1 + solve(i + 1, i, false, nums, dp));
        }

        return dp[i][last + 1][isInc] = ans;
    }

    int solveMem(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<vector<int>>> dp(n + 3, vector<vector<int>>(n + 3, vector<int>(2, 0)));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int last = i - 1; last >= -1; last--)
            {
                for (int isInc = 0; isInc <= 1; isInc++)
                {
                    // cout<<i<<" "<<last<<" "<<isInc<<endl;

                    if (last > -1)
                        dp[i][last + 1][isInc] = dp[i + 1][last][isInc];

                    if (isInc == 1)
                    {
                        if ((last == -1 || nums[i] > nums[last]))
                            dp[i][last + 1][isInc] = max(dp[i][last + 1][isInc], 1 + dp[i + 1][i][isInc]);
                    }
                    else if (isInc == 0 && nums[i] < nums[last])
                    {
                        dp[i][last + 1][isInc] = max(dp[i][last + 1][isInc], 1 + dp[i + 1][i][0]);
                    }
                }
            }
        }

        return dp[0][0][true];
    }

    vector<int> lis(vector<int> &nums)
    {
        vector<int> inc, ans;

        inc.push_back(nums[0]);
        ans.push_back(1);

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > inc.back())
            {
                inc.push_back(nums[i]);
            }
            else
            {
                int idx = lower_bound(inc.begin(), inc.end(), nums[i]) - inc.begin();
                inc[idx] = nums[i];
            }

            ans.push_back(inc.size());
        }

        return ans;
    }

    vector<int> lds(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> inc, ans(n);

        // isme array reverse haii inc wala that is in decending order

        for (int i = n - 1; i >= 0; i--)
        {
            int idx = lower_bound(inc.begin(), inc.end(), nums[i]) - inc.begin();

            if (idx == inc.size())
            {
                inc.push_back(nums[i]);
            }
            else
            {
                inc[idx] = nums[i];
            }

            ans[i] = inc.size();
        }

        return ans;
    }

    int solveFast(vector<int> &nums)
    {
        // approach
        // find lis for all indexes (0 to n)
        // find longest decreasing subsequence from back
        // ans = lis[i] + lds[i] -1;
        vector<int> li = lis(nums), ld = lds(nums);
        int ans = 0;

        for (auto i : li)
            cout << i << " ";

        cout << endl;

        for (auto i : ld)
            cout << i << " ";

        cout << endl;

        for (int i = 0; i < nums.size(); i++)
        {
            ans = max(ans, (li[i] + ld[i] - 1));
        }

        return ans;
    }

public:
    int LongestBitonicSequence(vector<int> nums)
    {
        vector<vector<vector<int>>> dp(nums.size() + 1, vector<vector<int>>(nums.size() + 1, vector<int>(2, -1)));

        // mujhe longest mountain array batana haii
        return solveFast(nums);
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        Solution ob;
        int ans = ob.LongestBitonicSequence(nums);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends