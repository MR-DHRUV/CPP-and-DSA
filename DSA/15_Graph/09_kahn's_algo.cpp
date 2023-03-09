//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// kahn's algo : way to obtain topological ordering using BFS traversal

// Algo
// find indegree of all the nodes and push nodes of 0 indegree into a queue
// do BFS, and add front in our ans everytime
// decrease the indegree of the vertices which are neibghour of this front
// again add the vertices of 0 indegree into queue

// intution
// jis node ki indegree 0 haii, we cannot reach that node from any other node thus that will be first in our ans
// aise krte krte hum indegree kam karte ja rahe haii vertex hatata hatate aur ans bnate ja rhe h

vector<int> kahn(int V, vector<int> adj[])
{
    vector<int> indeg(V, 0);

    for (int i = 0; i < V; i++)
    {
        for (auto j : adj[i])
        {
            indeg[j]++;
        }
    }

    queue<int> qt;

    for (int i = 0; i < V; i++)
    {
        if (indeg[i] == 0)
        {
            qt.push(i);
        }
    }

    vector<int> ans;

    // BFS
    while (!qt.empty())
    {
        int f = qt.front();
        qt.pop();

        ans.push_back(f);

        for (auto i : adj[f])
        {
            indeg[i]--; // 0 wali ki -1 ho jayga toh auto exclude

            if (indeg[i] == 0)
            {
                qt.push(i);
            }
        }
    }

    return ans;
}

class Solution
{
public:
    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {
        return kahn(V,adj);
    }
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
 *   contains the elements in topological sorted form
 *   V: number of vertices
 *   *res: array containing elements in topological sorted form
 *   adj[]: graph input
 */
int check(int V, vector<int> &res, vector<int> adj[])
{

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++)
    {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++)
    {
        for (int v : adj[i])
        {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++)
        {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }

    return 0;
}
// } Driver Code Ends