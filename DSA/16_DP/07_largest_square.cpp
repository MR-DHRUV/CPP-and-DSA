//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
    // brute force: O(N^4)
    int solve(int i, int j, vector<vector<int>> &mat)
    {
        if (i >= mat.size() || j >= mat[0].size() || i < 0 || j < 0)
            return 0;

        /*
            1  1 1 1 1 1

            1  1 1 1 1 1
            1  1 1 1 1 1
            1  1 1 1 0 1
            1  1 1 1 1 1
            1  1 1 1 1 1

            to make a big square we need that
            1. lower diagonal must be a square
            2. right part must be a square
            3. bottom part must be square


            // then only we can combign these 3 pieces to make a big square like this

            1 1  1 1 1 1
            1 1  1 1 1 1

            1    1 1 1 1 1
            1    1 1 1 0 1
            1    1 1 1 1 1
            1    1 1 1 1 1

        */

        int right = solve(i, j + 1, mat);
        int diagonal = solve(i + 1, j + 1, mat);
        int down = solve(i + 1, j, mat);

        if (mat[i][j] == 1)
        {
            return 1 + min(right, min(diagonal, down));
        }

        // element is 0
        return 0;
    }

    // O(N*M), O(N*M) space
    int solveMem(int i, int j, int &ans, vector<vector<int>> &mat, vector<vector<int>> &dp)
    {
        if (i >= mat.size() || j >= mat[0].size())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int right = solveMem(i, j + 1, ans, mat, dp);
        int diagonal = solveMem(i + 1, j + 1, ans, mat, dp);
        int down = solveMem(i + 1, j, ans, mat, dp);

        if (mat[i][j] == 1)
        {
            dp[i][j] = 1 + min(right, min(diagonal, down));

            // update ans
            ans = max(ans, dp[i][j]);

            return dp[i][j];
        }

        // element is 0
        return dp[i][j] = 0;
    }

    // O(N*M), O(N*M) space
    int solveTab(const int &n, const int &m, vector<vector<int>> &mat)
    {
        // base case is already covered
        // +1 isilie kara taaki out of bound na jaye
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        int ans = 0;

        // bottom up haii reverse krdo
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                int right = dp[i][j + 1];
                int diagonal = dp[i + 1][j + 1];
                int down = dp[i + 1][j];

                if (mat[i][j] == 1)
                {
                    dp[i][j] = 1 + min(right, min(diagonal, down));

                    // update ans
                    ans = max(ans, dp[i][j]);
                }
                else
                {
                    // element is 0
                    dp[i][j] = 0;
                }
            }
        }

        return ans;
    }

    // O(M) space : True optimization
    int solveTabSpaceOpt0(const int &n, const int &m, vector<vector<int>> &mat)
    {
        // base case is already covered
        // +1 isilie kara taaki out of bound na jaye
        int ans = 0;
        vector<vector<int>> dp(2, vector<int>(m + 1, 0));

        // bottom up haii reverse krdo
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                int right = dp[0][j + 1];
                int diagonal = dp[1][j + 1];
                int down = dp[1][j];

                if (mat[i][j] == 1)
                {
                    dp[0][j] = 1 + min(right, min(diagonal, down));

                    // update ans
                    ans = max(ans, dp[0][j]);
                }
                else
                {
                    // element is 0
                    dp[0][j] = 0;
                }
            }

            // updating next row
            dp[1] = dp[0];
        }

        return ans;
    }

    // O(1) space : since matrix given is not by refernce in original question, just update it
    int solveTabSpaceOpt1(const int &n, const int &m, vector<vector<int>> &mat)
    {
        int ans = 0;

        // bottom up haii reverse krdo
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                int right = j + 1 < m ? mat[i][j + 1] : 0;
                int diagonal = (i + 1 < n && j + 1 < m) ? mat[i + 1][j + 1] : 0;
                int down = i + 1 < n ? mat[i + 1][j] : 0;

                if (mat[i][j] == 1)
                {
                    mat[i][j] = 1 + min(right, min(diagonal, down));

                    // update ans
                    ans = max(ans, mat[i][j]);
                }
                else
                {
                    // element is 0
                    mat[i][j] = 0;
                }
            }
        }

        return ans;
    }

public:
    int maxSquare(int n, int m, vector<vector<int>> mat)
    {
        // int ans = 0;
        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // solveMem(0, 0, ans, mat, dp);
        return solveTabSpaceOpt1(n, m, mat);
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
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for (int i = 0; i < n * m; i++)
            cin >> mat[i / m][i % m];

        Solution ob;
        cout << ob.maxSquare(n, m, mat) << "\n";
    }
    return 0;
}
// } Driver Code Ends