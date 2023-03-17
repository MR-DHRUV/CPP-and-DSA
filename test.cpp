//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{

public:
    set<string> t1;

    int vis[100][100];

    string bfs(int i, int j, vector<vector<int>> &grid, string s)

    {

        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())

            return s;

        if (grid[i][j] == 0)

            return s;

        grid[i][j] = 0;

        return bfs(i - 1, j, grid, s + "u") + bfs(i, j - 1, grid, s + "l") + bfs(i + 1, j, grid, s + "d") + bfs(i, j + 1, grid, s + "r");
    }

    int countDistinctIslands(vector<vector<int>> &grid)
    {

        memset(vis, 0, sizeof(vis));

        for (int i = 0; i < grid.size(); i++)

        {

            for (int j = 0; j < grid[i].size(); j++)

            {

                if (grid[i][j] == 1 && vis[i][j] == 0)
                {

                    string str = bfs(i, j, grid, "");
                    cout<<str<<endl;
                    t1.insert(str);

                    vis[i][j] = 1;
                }
            }
        }

        return t1.size();
    }
};
//{ Driver Code Starts.

int main()
{

    // disable default
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

// set our properties
#ifndef IO_FROM_FILE
    freopen("C:\\Users\\Dhruv\\OneDrive\\Documents\\CPP + DSA\\input.txt", "r", stdin);
    freopen("C:\\Users\\Dhruv\\OneDrive\\Documents\\CPP + DSA\\output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends