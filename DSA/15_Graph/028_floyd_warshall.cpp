//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    void shortest_distance(vector<vector<int>> &matrix)
    {
        // O(N3)
        // Used to determine all source shortest path
        // here we are determining the shortest path from every node to every other node

        // we are given adj matrix

        // Algo
        // go to every node from every node and try to minimize everything
        // since we are not moving on a path or reccursive going somewhere , this algo will not stuck on -ve edge cycle and will detect correct shortest path

        for (int via = 0; via < matrix.size(); via++)
        {
            for (int i = 0; i < matrix.size(); i++)
            {
                for (int j = 0; j < matrix[0].size(); j++)
                {
                    // i se j gaya direct
                    // i se via gaya , via se j

                    // checking if we can reach or not
                    if (matrix[i][via] != -1 && matrix[via][j] != -1)
                    {
                        // if current edge is unreachable by default
                        if (matrix[i][j] == -1)
                        {
                            matrix[i][j] = matrix[i][via] + matrix[via][j];
                        }
                        else
                        {
                            matrix[i][j] = min(matrix[i][j], (matrix[i][via] + matrix[via][j]));
                        }
                    }
                }
            }
        }
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<vector<int>> matrix(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        obj.shortest_distance(matrix);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends