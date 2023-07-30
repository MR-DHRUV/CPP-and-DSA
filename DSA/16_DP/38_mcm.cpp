//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{

    int solve(int s, int e, int arr[], vector<vector<int>> &dp)
    {
        // base case : start >= end
        if (s >= e)
            return 0;

        if (dp[s][e] != -1)
            return dp[s][e];

        int ans = 1e9 + 7;

        for (int part = s; part < e; part++)
        {
            // steps = cost of left partition + right + cost of joining
            // start mat will be of dimention arr[s-1]*arr[part] , end arr[part]*arr[e]
            int steps = (arr[s - 1] * arr[part] * arr[e]) + solve(s, part, arr, dp) + solve(part + 1, e, arr, dp);

            // part+1 isilie hua as we are concidering matrix of dimension [i-1]x[i]

            ans = min(ans, steps);
        }

        return dp[s][e] = ans;
    }

    int solveTab(int N, int arr[])
    {
        vector<vector<int>> dp(N, vector<int>(N, 0));

        for (int s = N - 2; s >= 1; s--)
        {
            for (int e = s + 1; e < N; e++)
            {
                dp[s][e]  = 1e9 + 7;

                for (int part = s; part < e; part++)
                {
                    int steps = (arr[s - 1] * arr[part] * arr[e]) + dp[s][part]  + dp[part + 1][e];
                    dp[s][e]  = min(dp[s][e] , steps);
                }
            }
        }

        return dp[1][N-1];
    }

public:
    int matrixMultiplication(int N, int arr[])
    {
        // no of operations when we multiplu NxM MxO matrices = NxMxO
        // it based on the partition pattern where will divide the array
        vector<vector<int>> dp(N, vector<int>(N, -1));
        return solve(1, N - 1, arr, dp);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.matrixMultiplication(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends