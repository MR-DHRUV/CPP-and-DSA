//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // starts from abritary vertex v
        // makes MST by choosing minimum weighted edge at any point
        // complexity O(V logE) using heap else O(VE)

        // min heap to obtain minimum weighted edge at any instant
        priority_queue<int, vector<int>, greater<int>> minHeap;
        vector<int> near(V, -1); // to track visted edges and select the nearest(min weighted) edge

        int ans = 0;                // stores minimum weight
        vector<pair<int, int>> MST; // stores edges of MST

        // lets start from vertex 0

        

    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E)
        {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends