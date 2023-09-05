//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
    void DFS(vector<vector<pair<int, int>>> &adj, int v, stack<int> &st, unordered_map<int, bool> &visited)
    {
        if (!visited[v])
        {
            visited[v] = true;

            for (auto edge : adj[v])
            {
                if (!visited[edge.first])
                {
                    DFS(adj, edge.first, st, visited);
                }
            }

            st.push(v);
        }
    }

    stack<int> topoSort(int v, vector<vector<pair<int, int>>> &adj)
    {
        stack<int> st;
        unordered_map<int, bool> visited;

        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                DFS(adj, i, st, visited);
            }
        }

        return st;
    }

public:
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
    {
        // Algo
        // find topological ordering first
        // then create a distance array initialised to -1 representing there's no path initially
        // make distance[src] = 0
        // now mark the distance or the weight of vertices which can be reached from this src
        // then select next vertex from topological sort whose path is determined and try to minimize the distance of vertices connected to it and so on.....
        // vertices are traversed acc to topolocial sort as if edge is from u to v, then we must first determine the distance of u then v.

        // prepareing adjacency list
        vector<vector<pair<int, int>>> adj(N);

        for (auto edge : edges)
        {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

        // INIT
        stack<int> st = topoSort(N, adj);
        int src = 0; // fixed acc to question

        vector<int> dist(N, INT_MAX); // INT_MAX to denote that that vertex is unreachable
        dist[src] = 0;

        while (!st.empty())
        {
            int t = st.top();
            st.pop();

            if (dist[t] != INT_MAX)
            {
                for (auto edge : adj[t])
                {
                    // minimise/ relax
                    if (dist[t] + edge.second < dist[edge.first])
                    {
                        dist[edge.first] = dist[t] + edge.second;
                    }
                }
            }
        }
        
        // mark unreachable nodes
        for (int i = 0; i < dist.size(); i++)
        {
            if (dist[i] == INT_MAX)
            {
                dist[i] = -1;
            }
        }

        return dist;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i)
        {
            vector<int> temp;
            for (int j = 0; j < 3; ++j)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends