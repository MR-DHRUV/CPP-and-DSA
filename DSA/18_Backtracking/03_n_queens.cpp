#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // This method to check whether the position is safe or not takes O(N) time which can be reduced to O(1)
    bool isSafe(int i, int j, vector<string> &board)
    {
        if (board[i][j] == 'Q')
            return false;

        // checking row
        for (int x = 0; x <= j; x++)
        {
            if (board[i][x] == 'Q')
                return false;
        }

        // no need to check col as we are only placing 1 queen in each column

        // checking upper-left dia
        int x = i, y = j;

        while (x >= 0 && y >= 0)
        {
            if (board[x--][y--] == 'Q')
                return false;
        }

        // checking lower-left dia
        x = i, y = j;

        while (x < board.size() && y < board.size())
        {
            if (board[x++][y--] == 'Q')
                return false;
        }

        // no need to check right diagonals as we havent placed any queen on the left

        return true;
    }

    // complexity : N!
    void solve(int i, int &n, vector<string> &board, vector<vector<string>> &ans)
    {
        if (i == n)
        {
            ans.push_back(board);
            return;
        }

        for (int nxt = 0; nxt < n; nxt++)
        {
            if (isSafe(nxt, i, board))
            {
                board[nxt][i] = 'Q'; // placing queen
                solve(i + 1, n, board, ans);
                board[nxt][i] = '.'; // backtracking
            }
        }
    }

    // optimal solution : complexity : N!
    /*
      for lower diagonal we can map at index row+col as on same diagonal row+col have equal value

         0 1 2 3

      0  0 1 2 3
      1  1 2 3 4
      2  2 3 4 5
      3  3 4 5 6

      for upper diagonal we can map at index (n-1)+col-row where n is number of columns
    */

    void solveOpt(int i, int &n, vector<string> &board, vector<vector<string>> &ans, unordered_map<int, int> &vis, unordered_map<int, int> &ld, unordered_map<int, int> &ud)
    {
        if (i == n)
        {
            ans.push_back(board);
            return;
        }

        for (int nxt = 0; nxt < n; nxt++)
        {
            if (vis[nxt] == 0 && ld[nxt + i] == 0 && ud[((n - 1) + i - nxt)] == 0)
            {
                board[nxt][i] = 'Q'; // placing queen
                vis[nxt] = 1;

                ld[nxt + i] = 1;

                ud[((n - 1) + i - nxt)] = 1;

                solveOpt(i + 1, n, board, ans, vis, ld, ud);

                board[nxt][i] = '.'; // backtracking

                vis[nxt] = 0;
                ld[nxt + i] = 0;
                ud[((n - 1) + i - nxt)] = 0;
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        // Each row mush have 1 queen
        // Each column must have 1 queen
        // No 2 queens attack each other

        // If we satisfy above 3 conditions, then only we can place n queens on n*n chessboard

        // init board
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;

        solve(0, n, board, ans);

        return ans;
    }
};

int main()
{

    return 0;
}

// ["...Q",
// "Q...",
// "..Q.",
// ".Q.."]