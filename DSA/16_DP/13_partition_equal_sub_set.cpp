//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
    int solve(int i, int sumA, int arr[], int &n, vector<vector<int>> &dp)
    {
        // base case
        if (sumA == 0)
            return 1;

        if (i >= n || sumA < 0)
            return 0;

        if (dp[i][sumA] != -1)
            return dp[i][sumA];

        // we can either take current element in part 1 or part 2
        // our target is to make sum of any part totalSum/2

        if (solve(i + 1, sumA - arr[i], arr, n, dp)) // part 1
            return dp[i][sumA] = 1;

        if (solve(i + 1, sumA, arr, n, dp)) // part 2
            return dp[i][sumA] = 1;

        return dp[i][sumA] = 0;
    }

    int solveTab(int arr[], int &n, int sum)
    {
        vector<vector<int>> dp(2, vector<int>(sum + 2, 0));

        // base case
        dp[0][0] = 1;
        dp[1][0] = 1;

        // dp[i][j] represents that we want to make sum j using i no of elements

        for (int i = n - 1; i >= 0; i--)
        {
            for (int sumA = 1; sumA <= sum; sumA++)
            {
                if ((sumA - arr[i] >= 0 && dp[1][sumA - arr[i]]) || dp[1][sumA])
                    dp[0][sumA] = 1;
            }

            // optimization
            if (dp[0][sum] == 1)
                return 1;

            dp[1] = dp[0];
        }

        return dp[0][sum];
    }

public:
    int equalPartition(int N, int arr[])
    {
        long long sum = 0;
        for (int i = 0; i < N; i++)
        {
            sum += arr[i];
        }

        // if sum is odd we cant divide it into 2 parts
        if (sum % 2 != 0)
            return 0;

        vector<vector<int>> dp(N + 1, vector<int>((sum / 2) + 1, -1));
        return solve(0, sum / 2, arr, N, dp);

        return solveTab(arr, N, sum / 2);
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
        if (ob.equalPartition(N, arr))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
// } Driver Code Ends