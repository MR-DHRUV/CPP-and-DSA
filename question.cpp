//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    int findCity(int n, int m, vector<vector<int>> &edges, int distanceThreshold)
    {

        // All source shortest path
        vector<vector<int>> adj(n, vector<int>(n, -1));
        vector<int> nbr(n, 0);
        int max = 1e9, ans = 0;

        for (auto &e : edges)
        {
            adj[e[0]][e[1]] = e[2];
            adj[e[1]][e[0]] = e[2];
        }

        for (int via = 0; via < adj.size(); via++)
        {
            for (int i = 0; i < adj.size(); i++)
            {
                for (int j = 0; j < adj[0].size(); j++)
                {
                    // i se j gaya direct
                    // i se via gaya , via se j

                    // checking if we can reach or not
                    if (adj[i][via] != -1 && adj[via][j] != -1)
                    {
                        // if current edge is unreachable by default
                        if (adj[i][j] == -1)
                        {
                            adj[i][j] = adj[i][via] + adj[via][j];
                        }
                        else
                        {
                            adj[i][j] = min(adj[i][j], (adj[i][via] + adj[via][j]));
                        }
                    }
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (adj[i][j] != -1 && adj[i][j] <= distanceThreshold)
                    nbr[i]++;
            }

            if (nbr[i] <= max)
            {
                ans = i;
                max = nbr[i];
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i)
        {
            vector<int> temp;
            for (int j = 0; j < 3; ++j)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends