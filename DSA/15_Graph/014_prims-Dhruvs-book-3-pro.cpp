//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int spanningTree(int V, vector<vector<int>> adj[]) // o(V2)
    {
        // starts from abritary vertex v
        // makes MST by choosing minimum weighted edge at any point
        // complexity O(V logE) using heap else O(VE)

        // Algo
        // we need 3 arrays key(initilised to INT_MAX ), mst(initialised to false) and parent(initialised to -1)
        // mst to track whether a node is included in mst or not
        // parent to track parent of each node

        // starting from 0
        // make key[0] = 0
        // parent[0] = -1
        // mst[0] = true

        // now we'll traverse the adj[0] and mark the weights of adjacent nodes in the key array and update their parent
        // now repeat the process, get min from key which is not included in mst and repeat the steps

        // min weight will be the sum of key array
        // parent array will define the mst
        // mst is just visited map

        vector<int> key(V, INT_MAX);
        vector<bool> mst(V, false);
        vector<int> parent(V, -1);

        // init
        key[0] = 0;
        parent[0] = -1;
        mst[0] = true;

        int ans = 0;

        for (int i = 0; i < V; i++)
        {
            // finding the minimum weighted node
            int mini = INT_MAX;
            int u;

            for (int j = 0; j < V; j++)
            {
                if (mst[j] == false && key[j] < mini)
                {
                    mini = key[j];
                    u = j;
                }
            }

            mst[u] = true; // include it

            // checking its adj
            for (auto j : adj[u])
            {
                // updating the key array
                if (mst[j[0]] == false && j[1] < key[j[0]])
                {
                    key[j[0]] = j[1];
                    parent[j[0]] = u;
                }
            }
        }

        for (int i = 0; i < V; i++)
        {
            ans += key[i];
        }

        return ans;
    }

    int spanningTreeFast(int V, vector<vector<int>> adj[]) // o(ElogV)
    {
        // starts from abritary vertex v
        // makes MST by choosing minimum weighted edge at any point
        // complexity O(V logE) using heap else O(VE)

        // Algo
        // instead of key array we'll use minHeap or set

        vector<bool> mst(V, false);
        vector<int> parent(V, -1);
        vector<int> key(V, INT_MAX);

        set<pair<int, int>> st;
        st.insert({0, 0}); // weight then vertex

        parent[0] = -1;
        key[0] = 0;

        while (!st.empty())
        {
            auto top = *(st.begin());
            st.erase(st.begin());
            mst[top.second] = true;

            for (auto edge : adj[top.second])
            {
                int e = edge[0];
                int w = edge[1];

                // now our set is the key array
                // we have to update set with minimum weights for all possible adges we have

                // new weight is smaller and this vertex is not included in mst
                if (w < key[e] && !mst[e])
                {
                    auto inSet = st.find({key[e], e});

                    if (inSet != st.end())
                    {
                        st.erase(inSet);
                    }

                    st.insert({w, e});

                    // update parent and weight
                    parent[e] = top.second;
                    key[e] = w;
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < V; i++)
        {
            // cout<<parent[i]<<" ";
            ans += key[i];
        }

        return ans;
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

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends