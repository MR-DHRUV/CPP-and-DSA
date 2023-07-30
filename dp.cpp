#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int dp[21][10005];

    int solve(int i, int diff, vector<int> &rods)
    {
        if (i == rods.size())
            return diff == 0 ? 0 : -1e9;

        if (dp[i][diff + 5000] != -1)
            return dp[i][diff + 5000];

        int exclude = solve(i + 1, diff, rods);

        int include = max(solve(i + 1, diff + rods[i], rods), solve(i + 1, diff - rods[i], rods)) + rods[i];

        return dp[i][diff + 5000] = max(exclude, include);
    }

public:
    int tallestBillboard(vector<int> &rods)
    {
        memset(dp, -1, sizeof(dp));

        int ans = solve(0, 0, rods);

        if (ans <= 0)
            return 0;

        return ans / 2;
    }
};

int main()
{

    return 0;
}