//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int isEularCircuit(int V, vector<int> adj[])
    {
        //  Euler circuit = all n nodes should have only even edges
        //  Euler path = n-2 nodes should have even edges and other two should have odd

        int count = 0;

        // count the edges with odd degree and check above condition
        for (int i = 0; i < V; i++)
        {
            if (adj[i].size() % 2 != 0)
                count++;
        }

        if (count == 0)
            return 2;
        else if (count == 2)
            return 1;

        return 0;
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
        int ans = obj.isEularCircuit(V, adj);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends