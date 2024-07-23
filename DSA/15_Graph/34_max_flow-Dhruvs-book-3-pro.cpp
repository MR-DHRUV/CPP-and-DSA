//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    bool BFS(int s, int t, vector<vector<int>> &adj, vector<int> &parent, int n)
    {
        vector<bool> visisted(n + 1, 0);

        queue<int> qt;
        qt.push(s);

        while (!qt.empty())
        {
            int f = qt.front();
            qt.pop();
            visisted[f] = 1;

            for (int i = 1; i <= n; i++)
            {
                // adj[f][i] > 0 means that pipe has remaining capacity, so the water can flow
                if (adj[f][i] > 0 && !visisted[i])
                {
                    parent[i] = f;
                    qt.push(i);

                    // we have found a augumented path, a path from s to t in which atlest 1 unit of water can flow
                    if (i == t)
                        return true;
                }
            }
        }

        return false;
    }

public:
    int findMaxFlow(int N, int M, vector<vector<int>> Edges)
    {
        // 1 -> N vertices haii
        // aur edges/ pipes de rakhe haii hume
        // har edge ki kutch flow capacity haii
        // we need an arrangement of pipes to allow max flow from 1 to Nth vertex
        // max flow may be from sum of pipes

        // ford fulkerson algorithm
        const int S = 1, T = N;

        // creating residual graph
        // here we will mark the amount of water that can be flowed though any pipe/edge
        vector<vector<int>> adj(N + 1, vector<int>(N + 1, 0));

        for (auto &e : Edges)
        {
            // initially pipe is bi-directional, so water can flow in either direction, as the network/graph is undirected
            adj[e[0]][e[1]] += e[2];
            adj[e[1]][e[0]] += e[2];
        }

        // we will use this parent array to store augumenting path found during BFS
        vector<int> parent(N + 1, -1);

        int max_flow = 0;

        // we will apply this algorithm till we find augumented path
        while (BFS(S, T, adj, parent, N))
        {
            // max flow for current path
            int flow = 1e9;

            // backtracking from parent array to generate the path and obtain min of all pipes as this will be the amount of water that can flow from current path

            for (int pipe = T; pipe != S; pipe = parent[pipe])
            {
                // the pipe is from parent[pipe]-> pipe
                int &p = parent[pipe];
                flow = min(flow, adj[p][pipe]);
            }

            // adding current flow
            max_flow += flow;

            // updating residual capacities
            for (int pipe = T; pipe != S; pipe = parent[pipe])
            {
                // the pipe is from parent[pipe]-> pipe
                int &p = parent[pipe];

                // decrease for forward edge
                adj[p][pipe] -= flow;

                // increase for backword edge
                adj[pipe][p] += flow;
            }
        }

        return max_flow;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int i, j, N, M, u, v, w;
        int res;
        scanf("%d %d", &N, &M);
        vector<vector<int>> Edges;
        for (i = 0; i < M; i++)
        {
            scanf("%d %d %d", &u, &v, &w);
            Edges.push_back({u, v, w});
        }
        Solution obj;
        res = obj.findMaxFlow(N, M, Edges);
        cout << res << endl;
    }
    return 0;
}
// } Driver Code Ends