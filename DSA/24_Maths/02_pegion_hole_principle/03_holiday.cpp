#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long int

// we dont have to maintain a visited as graph will not have cycle
int DFS(int n, int parent, int &ans, vector<vector<vector<int>>> &adj)
{
    int treeSize = 1;

    for (auto &nbr : adj[n])
    {
        // to avoid looping
        if (nbr[0] != parent)
        {
            int childTreeSize = DFS(nbr[0], n, ans, adj);
            ans += (min(childTreeSize, adj.size() - 1 - childTreeSize)) * 2 * nbr[1];

            treeSize += childTreeSize;
        }
    }

    return treeSize;
}

int32_t main()
{
    // N <= 10^5, so we cannot find all source shortest path or try all permutations

    // say our graph has edges with weight e1 e2 ..... en
    // Total distance = n1e1 + n2e2 + n3e3 + ....
    // say we visit e1 n1 times and so on... or the no of people that will travel through this edge

    // we can say that to maximize the total distance we need to maximize the use of each edge

    // so to do so we can say that if an edge connects a to b, the max no of people that travells will be equal to

    // min(nodes conneted to a, nodes connected to b) *2
    // *2 as jitne gaye utne aaye bhi

    // we will use dfs approach to find no of nodes connected to each node

    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(NULL);

    int t;
    cin >> t;

    for (int ii = 1; ii <= t; ii++)
    {
        int n, i, j, k;
        cin >> n;

        vector<vector<vector<int>>> adj(n + 1);

        n--;
        while (n--)
        {
            cin >> i >> j >> k;
            adj[i].push_back({j, k});
            adj[j].push_back({i, k});
        }

        int ans = 0;
        DFS(1, -1, ans, adj);

        cout << "Case #" << ii << ": " << ans << endl;
    }

    return 0;
}