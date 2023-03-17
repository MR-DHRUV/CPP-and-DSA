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

    bool BFS(int v, vector<int> &color, vector<int> adj[])
    {
        // calls will be made for disconnected components so lets color first element with color 0
        color[v] = 0;

        queue<int> qt;
        qt.push(v);

        while (!qt.empty())
        {
            int f = qt.front();
            qt.pop();

            // try to color neighbour of f

            for (auto nbr : adj[f])
            {
                // if already colored check if the color is right or not
                if (color[nbr] != -1)
                {
                    if (color[nbr] == color[f])
                    {
                        return false;
                    }
                }
                else
                {
                    // uncolored
                    color[nbr] = 1 - color[f];
                    //           1 - 0 = 1
                    //           1 - 1 = 0

                    qt.push(nbr);
                }
            }
        }

        return true;
    }

    bool isBipartite(int V, vector<int> adj[])
    {
        vector<int> color(V, -1); // -1 for uncoloured node

        for (int i = 0; i < V; i++)
        {
            if (color[i] == -1)
            {
                if (!BFS(i, color, adj))
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
    freopen("C:\\Users\\Dhruv\\OneDrive\\Documents\\CPP + DSA\\input.txt","r",stdin);
    freopen("C:\\Users\\Dhruv\\OneDrive\\Documents\\CPP + DSA\\output.txt","w",stdout);
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