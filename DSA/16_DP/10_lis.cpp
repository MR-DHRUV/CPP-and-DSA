//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    int solveMem(int i, int prev, int &n, int a[], vector<vector<int>> &dp)
    {
        if (i == n)
            return 0;

        if (dp[i][prev + 1] != -1)
            return dp[i][prev + 1];

        // exclude
        int ans = solveMem(i + 1, prev, n, a, dp);

        // check if we can include or not
        if (prev == -1 || a[i] > a[prev])
            ans = max(ans, 1 + solveMem(i + 1, i, n, a, dp));

        return dp[i][prev + 1] = ans;
    }

    int solveTab(int &n, int a[])
    {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int prev = i - 1; prev >= -1; prev--)
            {
                // exclude
                int ans = dp[i + 1][prev + 1];

                // check if we can include or not
                if (prev == -1 || a[i] > a[prev])
                    ans = max(ans, 1 + dp[i + 1][i + 1]);

                dp[i][prev + 1] = ans;
            }
        }

        return dp[0][0];
    }

    int solveTabSpaceOpt(int &n, int a[])
    {
        vector<vector<int>> dp(2, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int prev = i - 1; prev >= -1; prev--)
            {
                // exclude
                int ans = dp[1][prev + 1];

                // check if we can include or not
                if (prev == -1 || a[i] > a[prev])
                    ans = max(ans, 1 + dp[1][i + 1]);

                dp[0][prev + 1] = ans;
            }

            dp[1] = dp[0];
        }

        return dp[0][0];
    }

    // Best Solution : DP + Binary Search

    /*
        concider
        5 8 3 7 9 1

        bin search se sahi jagah nikalo seq me if small or = haii else greater haii toh add krdo include array me

        5
        5 8
        3 8
        3 7
        3 7 9
        1 7 9

        ans = len of this arr
    */

    int binSearch(vector<int> &inc, int tar)
    {
        int s = 0;
        int e = inc.size() - 1;
        int ans = 0;

        while (s <= e)
        {
            int mid = s + (e - s) / 2;

            if (inc[mid] == tar)
                return mid;
            else if (inc[mid] < tar)
                s = mid + 1;
            else
            {
                ans = mid;
                e = mid - 1;
            }
        }

        return ans;
    }

    int solveBinS(int n, int a[])
    {
        vector<int> inc;

        for (int i = 0; i < n; i++)
        {
            if (inc.empty() || a[i] > inc.back())
                inc.push_back(a[i]);
            else
            {
                inc[binSearch(inc, a[i])] = a[i];
            }
        }

        return inc.size();
    }

public:
    // Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        // vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        // kutch nahi haii include exclude wali game khelni haii
        return solveBinS(n, a);
    }
};

//{ Driver Code Starts.
int main()
{
    // taking total testcases
    int t, n;
    cin >> t;
    while (t--)
    {
        // taking size of array
        cin >> n;
        int a[n];

        // inserting elements to the array
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        // calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends