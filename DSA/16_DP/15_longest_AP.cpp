//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
    // pure brute force
    int solve(int i, int l, int d, int A[], int &n)
    {
        if (i == n)
            return 0;

        // either include it in AP if possible or exclude it
        int ans = solve(i + 1, l, d, A, n); // exclude

        // include

        // first include
        if (l == -1)
        {
            ans = max(ans, 1 + solve(i + 1, i, -1, A, n));
        }
        // second include : calc d
        else if (l != -1 && d == -1)
        {
            d = abs(A[i] - A[l]); // calc d
            ans = max(ans, 1 + solve(i + 1, i, d, A, n));
        }
        // check if can include current or not
        else if (A[i] - A[l] == d)
        {
            ans = max(ans, 1 + solve(i + 1, i, d, A, n));
        }

        return ans;
    }

    // count elements with given a and d
    int countEle(int i, int d, int A[])
    {
        if (i < 0)
            return 0;

        int ans = 0;

        for (int j = i - 1; j >= 0; j--)
        {
            if (A[i] - A[j] == d)
            {
                ans++;
                i = j;
            }
        }

        return ans;
    }

    // int optimized brute force
    int optBrute(int A[], int n)
    {
        if (n <= 2)
            return n;

        // fix 2 elements to make a and d
        int ans = 0;

        // unordered_map<int, int> dp[n + 1];

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                ans = max(ans, 2 + countEle(i, A[j] - A[i], A));
            }
        }

        return ans;
    }

    int solveTab(int A[], int n)
    {
        if (n <= 2)
            return n;

        unordered_map<int, int> dp[n + 1];
        int ans = 0;

        // forward movement
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                int diff = A[i] - A[j];

                int cnt = 1; // concidering only i is part of dp

                // check if ans already present
                if (dp[j].count(diff))
                    cnt = dp[j][diff];

                dp[i][diff] = cnt + 1;
                ans = max(ans, dp[i][diff]);
            }
        }

        return ans;
    }

public:
    int lengthOfLongestAP(int A[], int n)
    {
        return solve(0, -1, -1, A, n);
    }
};



//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        Solution ob;
        auto ans = ob.lengthOfLongestAP(A, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends