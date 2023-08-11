//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    long long int solve(int i, int sum, int coins[], int &N, vector<vector<long long int>> &dp)
    {
        if (i == 0)
            return (sum % coins[0] == 0) * 1ll;

        if (dp[i][sum] != -1)
            return dp[i][sum];

        // exclude
        long long int ans = solve(i - 1, sum, coins, N, dp);

        // try to use current coin
        if (sum - coins[i] >= 0)
            ans += solve(i, sum - coins[i], coins, N, dp);

        return dp[i][sum] = ans;
    }

public:
    long long int count(int coins[], int N, int val)
    {
        vector<vector<long long int>> dp(N + 1, vector<long long int>(val + 1, 0));

        for (int i = 0; i < N; i++)
        {
            for (int sum = 0; sum <= val; sum++)
            {
                if (i == 0)
                {
                    dp[i][sum] = sum % coins[i] == 0;
                }
                else
                {
                    long long int ans = dp[i - 1][sum];

                    // try to use current coin
                    if (sum - coins[i] >= 0)
                        ans += dp[i][sum - coins[i]];

                    dp[i][sum] = ans;
                }
            }
        }

        return dp[N - 1][val];
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++)
            cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}

// } Driver Code Ends