#include <bits/stdc++.h>
using namespace std;

class Solution
{

    int dfs(int n, int p, vector<vector<int>> &adj, map<pair<int, int>, bool> &mp)
    {
        int ans = 0;

        for (auto &nbr : adj[n])
        {
            if (nbr == p)
                continue;

            // If there is an edge from n -> nbr then map will give 1, but I need 1 when edge is not present, so 1 - mp[]
            ans += dfs(nbr, n, adj, mp) + (1 - mp[{n, nbr}]);
        }

        return ans;
    }

    void reroot(int n, int p, vector<vector<int>> &adj, map<pair<int, int>, bool> &mp, vector<int> &ans)
    {
        ans[n] = ans[p];

        // if I have parent -> node edge then for this node to reach all other nodes, I need 1 more reversed edge, else I need 1 less reversed edge as parent wanted 1 more reversal to reach its child

        if (mp[{p, n}])
            ans[n]++;
        else
            ans[n]--;

        for (int &nbr : adj[n])
        {
            if (nbr == p)
                continue;

            reroot(nbr, n, adj, mp, ans);
        }
    }

public:
    vector<int> minEdgeReversals(int n, vector<vector<int>> &edges)
    {
        vector<int> ans(n, 0);
        vector<vector<int>> adj(n);
        map<pair<int, int>, bool> mp;

        for (auto &e : edges)
        {
            mp[{e[0], e[1]}] = 1;

            // add both edges, so that I can traverse the complete graph from any node
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        ans[0] = dfs(0, -1, adj, mp);

        for (int &nbr : adj[0])
            reroot(nbr, 0, adj, mp, ans);

        return ans;
    }
};

//////////////// optimised : search to O(1) from O(logN)
class SolutionFast
{
    // max node value can be 1e5 so I will take a prime number larger than it and calculate hash to optimize 2d map to 1d map;

    inline long long hash(int &u, int &v)
    {
        return (104107 * 1ll * u) + v;
    }

    int dfs(int n, int p, vector<vector<int>> &adj, unordered_map<long long, bool> &mp)
    {
        int ans = 0;

        for (auto &nbr : adj[n])
        {
            if (nbr == p)
                continue;

            ans += dfs(nbr, n, adj, mp) + (1 - mp[hash(n, nbr)]);
        }

        return ans;
    }

    void reroot(int n, int p, vector<vector<int>> &adj, unordered_map<long long, bool> &mp, vector<int> &ans)
    {
        ans[n] = ans[p] + (mp[hash(p, n)] == 1 ? 1 : -1);

        for (int &nbr : adj[n])
        {
            if (nbr == p)
                continue;

            reroot(nbr, n, adj, mp, ans);
        }
    }

public:
    vector<int> minEdgeReversals(int n, vector<vector<int>> &edges)
    {
        vector<int> ans(n, 0);
        vector<vector<int>> adj(n);
        unordered_map<long long, bool> mp;

        for (auto &e : edges)
        {
            mp[hash(e[0], e[1])] = 1;
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        ans[0] = dfs(0, -1, adj, mp);

        for (int &nbr : adj[0])
            reroot(nbr, 0, adj, mp, ans);

        return ans;
    }
};

int main()
{
    // For every node i in the range [0, n - 1], your task is to independently calculate the minimum number of edge reversals required so it is possible to reach any other node starting from node i through a sequence of directed edges.

    return 0;
}