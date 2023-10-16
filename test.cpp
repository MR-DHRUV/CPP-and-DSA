//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Back-end complete function Template for C++

class Solution
{
public:
    vector<vector<int>> transitiveClosure(int N, vector<vector<int>> matrix)
    {
        for (int via = 0; via < matrix.size(); via++)
        {
            for (int i = 0; i < matrix.size(); i++)
            {
                for (int j = 0; j < matrix[0].size(); j++)
                {
                    if (matrix[i][j] == 1)
                        continue;

                    // i se j gaya direct
                    // i se via gaya , via se j

                    // checking if we can reach or not
                    if (matrix[i][via] != 0 && matrix[via][j] != 0)
                    {
                        matrix[i][j] = 1;
                    }
                }
            }
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        vector<vector<int>> graph(N, vector<int>(N, -1));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                cin >> graph[i][j];

        Solution ob;
        vector<vector<int>> ans = ob.transitiveClosure(N, graph);
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                cout << ans[i][j] << " ";
            cout << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends