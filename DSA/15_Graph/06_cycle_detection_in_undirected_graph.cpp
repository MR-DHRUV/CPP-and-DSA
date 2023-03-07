//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

bool BFS(vector<int> adj[], unordered_map<int, bool> &visited, int v)
{
    unordered_map<int, int> parent;

    // iska abhi tk parent mallom nahi haii
    visited[v] = true;
    parent[v] = -1;

    queue<int> qt;
    qt.push(v);

    while (!qt.empty())
    {
        int f = qt.front();
        qt.pop();

        for (auto i : adj[f])
        {
            // condition for loop
            // agar yeh node pahle se hi visited haii aur pahle hum is node tak kisi aur raaste se gaye the i.e yeh node humari current node ka parent nahi haii
            if (i != parent[f] && visited[i] == true)
            {
                return true;
            }
            else if (!visited[i])
            {
                qt.push(i);
                visited[i] = true;
                parent[i] = f;
            }
        }
    }

    return false;
}

bool chkCycleBFS(int V, vector<int> adj[])
{
    // cycle can be detected using both bfs and dfs

    // using BFS
    // how will bfs check the presence of a cycle

    /*
        4--5--6
           |  |
           7--8
    */

    // while dowing BFS suppose we are at node 5 at present, we'll visit 6 and 7
    // now we're at 6 and we'll visit 8
    // now we're at 7 and we'll try to visit 8 but 8 is already visited and "7 does not have 8 as its parent", 7 ka parent 5 haii, that signifies that there exists a path starting from a point from which we can reach 8 and 7, and now we have a path from 7 to 8 that proves the existance of a loop

    unordered_map<int, bool> visited;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            bool isCycle = BFS(adj, visited, i);
            if (isCycle)
            {
                return true;
            }
        }
    }

    return false;
}

void DFS(vector<int> adj[], unordered_map<int, bool> &visited, unordered_map<int, int> &parent, bool &ans, int v, int p)
{
    if (!visited[v] && !ans)
    {
        visited[v] = true;
        parent[v] = p;

        for (auto i : adj[v])
        {
            if (ans)
                return;

            if (visited[i] && i != parent[v])
            {
                ans = true;
                return;
            }
            else if (!visited[i])
            {
                DFS(adj, visited, parent, ans, i, v);
            }
        }
    }
}

bool chkCycleDFS(int V, vector<int> adj[])
{
    // cycle can be detected using both bfs and dfs

    // using DFS
    // how will bfs check the presence of a cycle

    /*
        4--5--6
           |  |
           7--8
    */

    // same parent type approach
    // start dfs
    // 4->5->6->8->7
    // ab jab maii jana chahunga 7 se 5 par 5 pahle hi visited haii aur 5 par pahle maii 4 se gaya tha i.e uska parent 4 haii
    // thus is tareeke se cycle ka pata lag jayga

    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    bool ans = false;

    for (int i = 0; i < V && ans == false; i++)
    {
        if (!visited[i])
        {
            DFS(adj, visited, parent, ans, i, -1);
        }
    }

    return ans;
}

// } Driver Code Ends
class Solution
{
public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[])
    {
        return chkCycleDFS(V, adj);
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
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends