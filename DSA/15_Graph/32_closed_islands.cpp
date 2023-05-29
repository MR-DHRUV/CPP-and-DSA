//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    // adj list
    int drow[4] = {-1, 0, 1, 0};
    int dcol[4] = {0, 1, 0, -1};

    void markInvalid(int x, int y, vector<vector<int>> &matrix, vector<vector<int>> &visited)
    {
        // mark
        matrix[x][y] = 0;
        visited[x][y] = 1;

        // traversing the nbr of this 1
        for (int i = 0; i < 4; i++)
        {
            int nrow = x + drow[i];
            int ncol = y + dcol[i];

            if (nrow >= 0 && ncol >= 0 && nrow < matrix.size() && ncol < matrix[0].size() && visited[nrow][ncol] == 0 && matrix[nrow][ncol] == 1)
            {
                markInvalid(nrow, ncol, matrix, visited);
            }
        }
    }

    void dfs(int x, int y, vector<vector<int>> &matrix, vector<vector<int>> &visited)
    {
        // mark
        visited[x][y] = 1;

        // traversing the nbr of this 1
        for (int i = 0; i < 4; i++)
        {
            int nrow = x + drow[i];
            int ncol = y + dcol[i];

            if (nrow >= 0 && ncol >= 0 && nrow < matrix.size() && ncol < matrix[0].size() && visited[nrow][ncol] == 0 && matrix[nrow][ncol] == 1)
            {
                dfs(nrow, ncol, matrix, visited);
            }
        }
    }

public:
    int closedIslands(vector<vector<int>> &matrix, int N, int M)
    {
        // Code here

        // SIMPLIFIED APPROACH
        // all the one's that are at edges are not valid islands
        // so we will make all the 1's that are at edges 0 and 1's connected
        // then count the no of connected group of 1's

        vector<vector<int>> visited(N, vector<int>(M, 0));

        // mark invalid from cols
        for (int i = 0; i < N; i++)
        {
            // col 1
            if (matrix[i][0] == 1)
                markInvalid(i, 0, matrix, visited);

            // col n
            if (matrix[i][M - 1] == 1)
                markInvalid(i, M - 1, matrix, visited);
        }

        // mark invalid from rows
        for (int i = 0; i < M; i++)
        {
            // row 1
            if (matrix[0][i] == 1)
                markInvalid(0, i, matrix, visited);

            // row n
            if (matrix[N - 1][i] == 1)
                markInvalid(N - 1, i, matrix, visited);
        }

        int ans = 0;
        visited = vector<vector<int>>(N, vector<int>(M, 0)); // clear vis

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (matrix[i][j] == 1 && visited[i][j] == 0)
                {
                    ans++;
                    dfs(i, j, matrix, visited);
                }
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends