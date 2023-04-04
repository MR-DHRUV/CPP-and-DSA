#include <bits/stdc++.h>
using namespace std;

// at each point we can cut into 3 types of pieces
int solve(int n, vector<int> &arr, vector<int> &dp)
{
    if (n == 0)
        return 0;

    if (n < 0)
        return 1e9;

    if (dp[n] != -1)
        return dp[n];

    // cutting
    int ans = -1;

    for (int len : arr)
    {
        int t = solve(n - len, arr, dp);

        if (t < 1e9)
        {
            ans = max(ans, 1 + t); // 1 for current piece
        }
    }

    if (ans == -1)
        return dp[n] = 1e9;

    return dp[n] = ans;
}

int cutSegments(int n, int x, int y, int z)
{
    vector<int> arr = {x, y, z};
    vector<int> dp(n + 1, -1);

    int ans = solve(n, arr, dp);

    return ans >= 1e9 ? 0 : ans;
}

int main()
{
    // Solution obj;

    vector<int> a = {4, 0, 8, 10, 5, 6};

    // cout << houseRobber(a);
    return 0;
}