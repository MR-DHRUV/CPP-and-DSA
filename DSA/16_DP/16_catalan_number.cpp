//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    const int mod = 1e9 + 7;

    // making n as root node
    long long solve(int n, vector<int> &dp)
    {
        // only 1 bst for n<=1 nodes
        if (n == 0 || n == 1)
            return 1;

        if (n == 2)
            return 2;

        if (dp[n] != -1)
            return dp[n];

        long long ans = 0;

        // making i as root
        for (int i = 1; i <= n; i++)
        {
            // no of ways to arrange n nodes making i as root will be no of ways to arrange nodes in left * no of ways to arrange nodes in rignt
            long long temp = (solve(i - 1, dp) % mod * solve(n - i, dp) % mod) % mod;
            ans = (ans + temp) % mod;
        }

        return dp[n] = ans % mod;
    }

    int solveTab(int N)
    {
        vector<long long> dp(N + 1, 0);

        // base cases
        dp[0] = dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= N; i++)
        {
            // making i as root
            for (int j = 1; j <= i; j++)
            {
                dp[i] = (dp[i] + (dp[j - 1] * dp[i - j]) % mod) % mod;
            }
        }

        return dp[N] % mod;
    }

public:
    // Function to return the total number of possible unique BST.
    int numTrees(int n)
    {
        vector<int> dp(n + 3, -1);
        return solve(n, dp);
    }
};

//{ Driver Code Starts.
#define mod (int)(1e9 + 7)
int main()
{

    // taking total testcases
    int t;
    cin >> t;
    while (t--)
    {

        // taking total number of elements
        int n;
        cin >> n;
        Solution ob;
        // calling function numTrees()
        cout << ob.numTrees(n) << "\n";
    }
}
// } Driver Code Ends