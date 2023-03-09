//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

bool kahnCycleDetect(int V, vector<int> adj[])
{
    // using BFS
    // how will bfs check the presence of a cycle

    /*
        4-->5-->6
            ^   |
            |   v
            7<--8
    */

    // using kahn's algo
    // for a cyclic graph, topolocial sort will be invalid
    // by invalid we mean if cycle hoga edge baar baar repeat hoga thus size of topological order will become greater than the no of vertices

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

    int cnt = 0;

    // BFS
    while (!qt.empty() && cnt <= V)
    {
        int f = qt.front();
        qt.pop();

        cnt++;

        for (auto i : adj[f])
        {
            indeg[i]--; // 0 wali ki -1 ho jayga toh auto exclude

            if (indeg[i] == 0)
            {
                qt.push(i);
            }
        }
    }

    if (cnt == V)
    {
        return false; // no cycle , valid topo
    }

    return true;
}

// backtrack krenge for speed
void DFS(vector<int> adj[], unordered_map<int, bool> &visited, unordered_map<int, bool> &DFSvisited, bool &ans, int v)
{
    if (!visited[v] && !ans)
    {
        visited[v] = true;
        DFSvisited[v] = true;

        for (auto i : adj[v])
        {
            if (ans)
                return;

            if (DFSvisited[i])
            {
                ans = true;
                return;
            }
            else if (!visited[i])
            {
                DFS(adj, visited, DFSvisited, ans, i);
            }
        }

        // backtrack
        DFSvisited[v] = false;
    }
}

bool chkCycleDFS(int V, vector<int> adj[])
{
    // cycle can be detected using both bfs and dfs

    // using DFS
    // how will bfs check the presence of a cycle

    /*
        4-->5-->6
            ^   |
            |   v
            7<--8
    */

    // same parent type approach
    // start dfs
    // agar dfs ke 1 cycle me maii kisi node par wapas aajau mtlb cycle haii
    // 1 cycle mtlb 1 baar bhi reccurise function return nahi hua kisi aur node pr jane ke lie
    // jaise 4->5->6->8->7->5 yeh 1 cycle haii

    unordered_map<int, bool> visited;
    unordered_map<int, bool> DFSvisited; // 1 cycle ko track krne ke lie
    bool ans = false;

    for (int i = 0; i < V && ans == false; i++)
    {
        if (!visited[i])
        {
            DFS(adj, visited, DFSvisited, ans, i);
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
        return kahnCycleDetect(V, adj);
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