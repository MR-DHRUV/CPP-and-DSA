//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // vvvip algo
        // used to find the shortest path from the source to all vertices in the given graph.

        // algo
        // init a distance array initialised with INT_MAX and dist[S] = 0
        // we need a priority queue/set to obtain vertex of minDistance/min weighted edge
        // push (S,0) in set to initialize it

        // follow bfs iteration style , using set will make elements of it sorted on the basis of distance
        // ElogV

        vector<int> dist(V, INT_MAX);
        dist[S] = 0;

        set<pair<int, int>> st; // first weight then vertex
        st.insert({0, S});      // init

        while (!st.empty())
        {
            // fetch top node
            auto top = *(st.begin());
            st.erase(st.begin());

            int d = top.first;
            int t = top.second;

            for (auto i : adj[t])
            {
                // we want to relax i
                if (d + i[1] < dist[i[0]])
                {
                    // modify set
                    auto record = st.find({dist[i[0]], i[0]});

                    if (record != st.end())
                    {
                        st.erase(record);
                    }

                    // update distance
                    dist[i[0]] = d + i[1];

                    // push record
                    st.insert({dist[i[0]], i[0]});
                    // if relaxed, this node is pushed again into set as all the nodes which are being reached using this node are required to be relaxed again
                }
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
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E)
        {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin >> S;

        Solution obj;
        vector<int> res = obj.dijkstra(V, adj, S);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends