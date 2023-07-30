#include <bits/stdc++.h>
using namespace std;

// since we will only have 20 cities we can keep a track of visited cities in O(1) using bitset, i.e we will set i'th bit to mark ith city is visited

int solve(int src, int mask, vector<vector<int>> &cost, vector<vector<int>> &dp)
{
    if (mask == 0)
        return cost[src][0]; // back to 0 ki cost

    if (dp[src][mask] != -1)
        return dp[src][mask];

    int ans = 1e9 + 7;

    // go to all unvisited cities and find shortest path
    for (int j = 0; j < cost.size(); j++)
    {
        // if 1, then unvisited
        if (mask & ((1 << j)))
        {
            ans = min(ans, cost[src][j] + solve(j, (mask ^ (1 << j)), cost, dp));
        }
    }

    return dp[src][mask] = ans;
}

int total_cost(vector<vector<int>> cost)
{
    // start from 0 then all cities then back to 0 in min cost
    int n = cost.size();

    if (n == 1)
        return 0;

    // n cities haii 0 to n-1
    int mask = (1 << n) - 1; // n baar krdia haii i.e O to n i.e n+1 position par haii 1 agar isme se 1 minus krdu maii toh 0 to n-1 bits set jo jayengi

    // dp
    vector<vector<int>> dp(n + 1, vector<int>(mask + 1, -1));

    mask ^= (1 << 0); // marking the city 0 visited by unsetting the 0th bit

    return solve(0, mask, cost, dp);
}

int main()
{

    return 0;
}