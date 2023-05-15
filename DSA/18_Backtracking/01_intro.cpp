#include <bits/stdc++.h>
using namespace std;

// Rat in a maze

inline bool chk_coordinates(int x, int y, vector<vector<int>> &arr)
{
    if (max(x, y) >= arr.size() || min(x, y) < 0)
        return false;

    return arr[x][y] == 1;
}

void solve(int x, int y, vector<vector<int>> &arr, vector<vector<int>> &vis, string path, vector<string> &ans)
{
    // base case
    if (x == arr.size() - 1 && y == arr.size() - 1)
    {
        ans.push_back(path);
        return;
    }

    vis[x][y] = 1;

    // move down
    if (chk_coordinates(x + 1, y, arr) && vis[x + 1][y] == 0)
    {
        solve(x + 1, y, arr, vis, path + 'D', ans);
    }

    // move left
    if (chk_coordinates(x, y - 1, arr) && vis[x][y - 1] == 0)
    {
        solve(x, y - 1, arr, vis, path + 'L', ans);
    }

    // move right
    if (chk_coordinates(x, y + 1, arr) && vis[x][y + 1] == 0)
    {
        solve(x, y + 1, arr, vis, path + 'R', ans);
    }

    // move up
    if (chk_coordinates(x - 1, y, arr) && vis[x - 1][y] == 0)
    {
        solve(x - 1, y, arr, vis, path + 'U', ans);
    }

    vis[x][y] = 0; // backtrack
}

vector<string> searchMaze(vector<vector<int>> &arr, int n)
{
    string path;
    vector<string> ans;

    // base case
    if (arr[0][0] == 0)
        return ans;

    vector<vector<int>> vis(arr.size(), vector<int>(arr.size(), 0));
    vis[0][0] = 1;

    solve(0, 0, arr, vis, path, ans);

    return ans;
}

int main()
{
    // we do something and if we fail in dowing that something then we backtrack
    
    int i;
    cin>>i;
    cout<<i<<endl;

    return 0;
}