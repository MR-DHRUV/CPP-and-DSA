//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
    bool DFS(vector<vector<int>> &mat, vector<vector<int>> &ul, int i, int j, int N, int M)
    {
        // base case : index out of range
        if (i < 0 || j < 0 || i >= N || j >= M)
        {
            return false;
        }

        // base case : cycle
        if (ul[i][j] == 2)
        {
            return false;
        }

        // base case : already determined
        if (ul[i][j] != -1)
        {
            return ul[i][j];
        }

        // 1 try to move left
        if (j - 1 >= 0 && ul[i][j] < 2 && mat[i][j - 1] <= mat[i][j])
        {
            // inhibit infinite looping
            ul[i][j] = 2;

            bool canImove = DFS(mat, ul, i, j - 1, N, M);
            if (canImove)
            {
                ul[i][j] = 1;
                return true;
            }
            else
            {
                ul[i][j] = -1;
            }
        }

        // 1 try to move up
        if (i - 1 >= 0 && ul[i][j] < 2 && mat[i - 1][j] <= mat[i][j])
        {
            // inhibit infinite looping
            ul[i][j] = 2;

            bool canImove = DFS(mat, ul, i - 1, j, N, M);
            if (canImove)
            {
                ul[i][j] = 1;
                return true;
            }
            else
            {
                ul[i][j] = -1;
            }
        }

        // 1 try to move right
        if (j + 1 < M && ul[i][j] < 2 && mat[i][j + 1] <= mat[i][j])
        {
            // inhibit infinite looping
            ul[i][j] = 2;

            bool canImove = DFS(mat, ul, i, j + 1, N, M);
            if (canImove)
            {
                ul[i][j] = 1;
                return true;
            }
            else
            {
                ul[i][j] = -1;
            }
        }

        // 1 try to move down
        if (i + 1 < N && ul[i][j] < 2 && mat[i + 1][j] <= mat[i][j])
        {
            // inhibit infinite looping
            ul[i][j] = 2;

            bool canImove = DFS(mat, ul, i + 1, j, N, M);
            if (canImove)
            {
                ul[i][j] = 1;
                return true;
            }
            else
            {
                ul[i][j] = -1;
            }
        }

        // ni ja skte
        ul[i][j] = 0;
        return false;
    }
public:
    int water_flow(vector<vector<int>> &mat, int N, int M)
    {
        // init
        vector<vector<int>> ul(N, vector<int>(M, -1));
        vector<vector<int>> dr(N, vector<int>(M, -1));

        // base cases
        ul[0] = vector<int>(M, 1);
        dr[N - 1] = vector<int>(M, 1);

        for (int i = 0; i < N; i++)
        {
            ul[i][0] = 1;
            dr[i][M - 1] = 1;
        }

        // processing
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                // for any node i, j determine if we can go or not

                // top or left
                if (ul[i][j] == -1)
                {
                    // cout<<i<<" in call "<<j<<endl;
                    DFS(mat, ul, i, j, N, M);
                }

                // down or right
                if (dr[i][j] == -1)
                {
                    DFS(mat, dr, i, j, N, M);
                }
            }
        }
        
        // gen ans
        int ans = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (ul[i][j] == 1 && dr[i][j] == 1)
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        cout << ob.water_flow(mat, n, m) << endl;
    }
}

// } Driver Code Ends