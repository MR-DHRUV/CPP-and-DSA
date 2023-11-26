//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DSU
{
    vector<int> parent, rank;

public:
    DSU(int n)
    {
        parent.resize(n + 1);
        rank.resize(n + 1, 1);

        iota(parent.begin(), parent.end(), 0);
    }

    int findSet(int n)
    {
        if (parent[n] == n)
            return n;

        return parent[n] = findSet(parent[n]);
    }

    void unionByRank(int n1, int n2)
    {
        int p1 = findSet(n1), p2 = findSet(n2);

        if(p1 == p2)
            return;

        if(rank[p1] > rank[p2])
            parent[p2] = p1;
        else if (rank[p1] < rank[p2])
            parent[p1] = p2;
        else
        {
            rank[p1]++;
            parent[p2] = p1;
        }    
    }
};

class Solution
{
public:
    // Function to detect cycle using DSU in an undirected graph.
    int detectCycle(int V, vector<int> adj[])
    {
        
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        int ans = obj.detectCycle(V, adj);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends