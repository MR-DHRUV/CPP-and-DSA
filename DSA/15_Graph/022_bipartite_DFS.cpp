//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // any graph is bipartite or 2 colorable iff it can be divided into 2 sets of vertices such that vertices of any set dont have an edge amongst themselves.

    // any graph that is linear or contains a cycle of even length is bipartite

    // we will try to color the graph using 2 colors 0 and 1

    void DFS(int v, vector<int> &color, vector<int> adj[], bool &ans, int parentcolor)
    {
        if (color[v] == -1 && ans)
        {
            // colouring the current node
            color[v] = 1 - parentcolor;

            for (int nbr : adj[v])
            {
                if (color[nbr] != -1)
                {
                    if (color[nbr] == color[v])
                    {
                        ans = false;
                        return;
                    }
                }
                else
                {
                    // uncoloured
                    DFS(nbr, color, adj, ans, color[v]);
                }
            }
        }
    }

    bool isBipartite(int V, vector<int> adj[])
    {
        vector<int> color(V, -1); // -1 for uncoloured node

        for (int i = 0; i < V; i++)
        {
            if (color[i] == -1)
            {
                bool ans = true;
                DFS(i, color, adj, ans, 0);

                if (!ans)
                {
                    return false;
                }
            }
        }

        return true;
    }
};

//{ Driver Code Starts.
int main()
{

    // disable default
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

// set our properties
#ifndef IO_FROM_FILE
    freopen("C:\\Users\\Dhruv\\OneDrive\\Documents\\CPP + DSA\\input.txt", "r", stdin);
    freopen("C:\\Users\\Dhruv\\OneDrive\\Documents\\CPP + DSA\\output.txt", "w", stdout);
#endif

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
        bool ans = obj.isBipartite(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends