#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool check(vector<vector<char>> &board, int i, int j, char val)
    {
        // row
        for (int x = 0; x < 9; x++)
        {
            if (board[x][j] == val)
                return false;
        }

        // col
        for (int y = 0; y < 9; y++)
        {
            if (board[i][y] == val)
                return false;
        }

        // calculating box
        int row = i - i % 3;
        int column = j - j % 3;

        // checking box
        for (int x = 0; x < 3; x++)
        {
            for (int y = 0; y < 3; y++)
            {
                if (board[row + x][column + y] == val)
                    return false;
            }
        }
        return true;
    }

    bool solve(int i, int j, vector<vector<char>> &board)
    {
        // ans case
        if (i == board.size() && j == 0)
            return true;

        // base case
        if (i >= board.size() || j >= board.size())
            return false;

        // next index to be solved
        int nxtR = j == board.size() - 1 ? i + 1 : i;
        int nxtC = j == board.size() - 1 ? 0 : j + 1;

        if (board[i][j] != '.')
            return solve(nxtR, nxtC, board);

        // options at current index = 1-9
        for (char num = '1'; num <= '9'; num++)
        {
            if (check(board, i, j, num))
            {
                // putting num
                board[i][j] = num;

                if (solve(nxtR, nxtC, board))
                    return true;

                // backtracking
                board[i][j] = '.';
            }
        }

        return false;
    }

public:
    void solveSudoku(vector<vector<char>> &board)
    {
        solve(0, 0, board);
    }
};

/// using map is taking more time //////////////////////////////////////////////////////////////////

// class Solution
// {
//     vector<vector<char>> ans;
//     unordered_map<int, unordered_map<char, bool>> row, col, box;

//     int getBox(int i, int j)
//     {
//         if (i < 3)
//         {
//             if (j < 3)
//                 return 0;
//             else if (j < 6)
//                 return 1;
//             else
//                 return 2;
//         }
//         if (i < 6)
//         {
//             if (j < 3)
//                 return 3;
//             else if (j < 6)
//                 return 4;
//             else
//                 return 5;
//         }
//         else
//         {
//             if (j < 3)
//                 return 6;
//             else if (j < 6)
//                 return 7;
//             else
//                 return 8;
//         }
//     }

//     bool solve(int i, int j, vector<vector<char>> &board)
//     {
//         // ans case
//         if (i == board.size() && j == 0)
//         {
//             ans = board;
//             return true;
//         }

//         // base case
//         if (i >= board.size() || j >= board.size())
//             return false;

//         // next index to be solved
//         int nxtR = j == board.size() - 1 ? i + 1 : i;
//         int nxtC = j == board.size() - 1 ? 0 : j + 1;

//         if (board[i][j] != '.')
//             return solve(nxtR, nxtC, board);

//         // options at current index = 1-9
//         for (char num = '1'; num <= '9'; num++)
//         {
//             if (!row[i][num] && !col[j][num] && !box[getBox(i, j)][num])
//             {
//                 // putting num
//                 board[i][j] = num;

//                 // vis
//                 row[i][num] = true;
//                 col[j][num] = true;
//                 box[getBox(i, j)][num] = true;

//                 if (solve(nxtR, nxtC, board))
//                     return true;

//                 // backtracking
//                 board[i][j] = '.';
//                 row[i][num] = false;
//                 col[j][num] = false;
//                 box[getBox(i, j)][num] = false;
//             }
//         }

//         return false;
//     }

// public:
//     void solveSudoku(vector<vector<char>> &board)
//     {
//         ans = vector<vector<char>>(0);

//         // row[i][j] means ith row have jthe element

//         // mapping used elements
//         for (int i = 0; i < board.size(); i++)
//         {
//             for (int j = 0; j < board.size(); j++)
//             {
//                 if (board[i][j] != '.')
//                 {
//                     row[i][board[i][j]] = true;
//                     col[j][board[i][j]] = true;
//                     box[getBox(i, j)][board[i][j]] = true;
//                 }
//             }
//         }

//         solve(0, 0, board);
//         board = ans;
//     }
// };

int main()
{

    return 0;
}

// ["5","3","1","2","7","6","4","9","8"]
// ["6","2","3","1","9","5","8","4","7"]
// ["1","9","8","3","4","7","5","6","2"]
// ["8","1","2","7","6","4","9","5","3"]
// ["4","7","9","8","5","3","6","2","1"]
// ["7","4","5","9","2","8","3","1","6"]
// ["9","6","7","5","3","1","2","8","4"]
// ["2","8","6","4","1","9","7","3","5"]
// ["3","5","4","6","8","2","1","7","9"]