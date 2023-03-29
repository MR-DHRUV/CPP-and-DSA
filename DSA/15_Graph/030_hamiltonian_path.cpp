//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    void DFS(int v, vector<bool> &visited, int &vis, vector<vector<int>> &adj, const int &N)
    {
        if (!visited[v])
        {
            visited[v] = true;
            vis++;

            if (vis == N)
                return;

            // we can visit only 1 nbr from any node as we need a path such that each vertex is travesed only once
            // nbr
            for (int nbr : adj[v])
            {
                if (!visited[nbr])
                {
                    // call dfs
                    DFS(nbr, visited, vis, adj, N);

                    // backtracking stage
                    if (vis == N)
                    {
                        return;
                    }
                    else
                    {
                        // back track
                        vis--;
                        visited[nbr] = false;
                    }
                }
            }
        }
    }

public:
    bool check(int N, int M, vector<vector<int>> Edges)
    {
        // can be checked using using both bfs and dfs

        // get adj
        vector<vector<int>> adj(N);
        for (auto edge : Edges)
        {
            adj[edge[0] - 1].push_back(edge[1] - 1);
            adj[edge[1] - 1].push_back(edge[0] - 1);
        }

        // we may have to start from any vertex
        for (int i = 1; i < N; i++)
        {
            vector<bool> visited(N, false);
            int vis = 0;
            DFS(i, visited, vis, adj, N);

            if (vis == N)
                return true;
        }

        return false;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, M, X, Y;
        cin >> N >> M;
        vector<vector<int>> Edges;
        for (int i = 0; i < M; i++)
        {
            cin >> X >> Y;
            Edges.push_back({X, Y});
        }
        Solution obj;
        if (obj.check(N, M, Edges))
        {
            cout << "1" << endl;
        }
        else
            cout << "0" << endl;
    }
}
// } Driver Code Ends