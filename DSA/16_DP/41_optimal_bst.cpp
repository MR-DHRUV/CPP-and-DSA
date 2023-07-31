//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int optimalSearchTree(int keys[], int freq[], int n)
    {
        // prefix sum freq array
        vector<int> sum(n, 0);
        sum[0] = freq[0];
        for (int i = 1; i < n; i++)
        {
            sum[i] = freq[i] + sum[i - 1];
        }

        // based on diagonal traversal of the matrix where dp[i][j] = dp[i][k-1] + dp[k][j] + w[i][j]

        vector<vector<int>> dp(n, vector<int>(n, 1e9));

        for (int g = 0; g < n; g++)
        {
            for (int i = 0, j = g; j < n; i++, j++)
            {
                if (g == 0)
                    dp[i][j] = freq[i];
                else if (g == 1)
                    dp[i][j] = min(freq[i] + freq[j] * 2, freq[i] * 2 + freq[j]);
                else
                {
                    // sum of i to j in O(1)
                    int prefix = i - 1 < 0 ? 0 : sum[i - 1];
                    int s = sum[j] - prefix;

                    // making each node in interval i to j as root
                    int ans = 1e9 + 7;
                    for (int k = i; k <= j; k++)
                    {
                        int l = i == k ? 0 : dp[i][k - 1];
                        int r = k == j ? 0 : dp[k + 1][j];

                        ans = min(ans, l + r);
                    }

                    dp[i][j] = ans + s;
                }
            }
        }

        return dp[0][n - 1];
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
        int keys[n];
        for (int i = 0; i < n; i++)
            cin >> keys[i];
        int freq[n];
        for (int i = 0; i < n; i++)
            cin >> freq[i];
        Solution ob;
        cout << ob.optimalSearchTree(keys, freq, n) << endl;
    }
    return 0;
}
// } Driver Code Ends