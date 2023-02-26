//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{

    void DFS(vector<vector<int>> &adj, int i, vector<int> &visited, vector<int> &temp)
    {
        temp.push_back(i);
        visited[i]++;

        for (auto it : adj[i])
        {
            if (!visited[it])
            {
                DFS(adj, it, visited, temp);
            }
        }
    }

public:
    int findNumberOfGoodComponent(int v, vector<vector<int>> &adj)
    {
        vector<int> visited(v + 1, 0);
        int ans = 0;
        for (int i = 1; i <= v; i++)
        {
            if (!visited[i])
            {
                vector<int> t;
                DFS(adj, i, visited, t);

                bool flag = false;

                for (int i = 0; i < t.size(); i++)
                {
                    if (adj[t[i]].size() < t.size() - 1)
                    {
                        flag = true;
                        break;
                    }
                }

                if (flag == false)
                {
                    ans++;
                }
            }
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
        int E, V;
        cin >> E >> V;
        vector<vector<int>> adj(V + 1, vector<int>());
        for (int i = 0; i < E; i++)
        {
            int u, v;

            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;

        int res = obj.findNumberOfGoodComponent(V, adj);
        cout << res << "\n";
    }
    return 0;
}
// } Driver Code Ends