//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{

    void DFS(int node, int parent, int &time, vector<int> &disc, vector<int> &low, vector<bool> &visited, vector<int> adj[], vector<int> &ap)
    {
        if (!visited[node])
        {
            visited[node] = true;
            disc[node] = low[node] = time++;

            int child = 0; // we are only counting children which are unvisited from before

            for (auto nbr : adj[node])
            {
                // same edge
                if (nbr == parent)
                {
                    continue;
                }

                // new edge
                if (!visited[nbr])
                {
                    DFS(nbr, node, time, disc, low, visited, adj, ap);

                    // updating low
                    low[node] = min(low[node], low[nbr]);

                    // check articulation point
                    // removal of this node will diconnect parent and nbr
                    if (low[nbr] >= disc[node] && parent != -1)
                    {
                        ap[node] = 1;
                    }

                    child++;
                }

                // back edge
                else
                {
                    low[node] = min(low[node], disc[nbr]);
                }
            }

            // -1 case
            if (parent == -1 && child > 1)
            {
                ap[node] = 1;
            }
        }
    }

public:
    vector<int> articulationPoints(int V, vector<int> adj[])
    {
        // node, on removal of which a connected component is divided into 2 or more connected components
        // approach
        // simmilar to finding bridges using tarjans algo

        // condition to check articulation point
        // low[nbr] >= disc[node] && parent != -1

        // why ?
        // if low[nbr] < disc[node], means that if node is removed nbr is still reachable from some other node
        // but low[nbr] >= disc[node] this is not sufficent condition everytime as it does not ensure dijointness
        // parent must be equal to -1 to ensure that the graph becomes disconnected as removal of this node will create a gap b/w parent of node and its nbr

        // this whole process can detect all the articulation points other than the starting node, thus starting node has to be handled separately

        // if(parent == -1 && noOfChild[node] > 1) then its an articulation point

        /*
            0-----3
            |  \
            |   \
            1    4
            |
            2

        */

        int time = 0;
        vector<int> disc(V, -1);
        vector<int> low(V, INT_MAX);
        vector<bool> visited(V, false);

        vector<int> ap(V, -1);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                DFS(i, -1, time, disc, low, visited, adj, ap);
            }
        }

        vector<int> ans;

        for (int i = 0; i < V; i++)
        {
            if (ap[i] == 1)
            {
                ans.push_back(i);
            }
        }

        if (ans.size() == 0)
        {
            return {-1};
        }

        return ans;
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
        vector<int> ans = obj.articulationPoints(V, adj);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends