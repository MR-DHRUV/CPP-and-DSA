//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


// using dfs : it can generate topologial order
void dfsR(vector<int> adj[], stack<int> &st, unordered_map<int, bool> &visited, int v)
{
    if (visited[v] == false)
    {
        visited[v] = true;
        for (int i = 0; i < adj[v].size(); i++)
        {
            if (visited[adj[v][i]] == false)
            {
                dfsR(adj, st, visited, adj[v][i]);
            }
        }

        // pushing at the last as all the nodes that can be reached from here will be already in the stack, thus they will be later in the ordering 
        st.push(v);
    }
}

vector<int> DFSTopo(int V, vector<int> adj[])
{
    // keep following a path until we have reach a vertex at which there are no unvisited connected nodes, when we are at such a vertex we push it in the stack as it will be the last one in topological order as there is no vertex that can be reached from this edge 
    // we will usa a stack as the nodes in the last of the dfs path will be pushed first the stack and earliar ones will be pushed later after all the possible paths will be traversed 

    unordered_map<int, bool> visited;
    vector<int> ans;
    stack<int> st;

    for (int i = 0; i < V; i++)
    {
        dfsR(adj, st, visited, i);
    }

    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}

class Solution
{
public:
    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {
        return DFSTopo(V,adj);
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