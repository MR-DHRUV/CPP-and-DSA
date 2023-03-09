#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t)
{
    // shortest path from src to target in an undirected graph can be determined as follows

    /*
        4--5--6
           | \|
           7--8
    */

    // do bfs and create the parent array

    //-1 4 5 5 5
    // 4 5 6 7 8

    // shortest path from 5 to 8
    // arr[8] = 5 = src , else keep on moving like this until src is found, and in each move incriment ans by 1

    // here we have matrix instead of graph but we'll treat is as a graph only

    s--;
    t--;

    vector<vector<int>> adj(n);
    for (auto i : edges)
    {
        adj[i.first - 1].push_back(i.second - 1);
        adj[i.second - 1].push_back(i.first - 1);
    }

    // printMat(adj);

    unordered_map<int, bool> visited;
    vector<int> parent(n, -1);

    queue<int> qt;
    qt.push(s); // start bfs from source
    visited[s] = true;

    while (!qt.empty())
    {
        int f = qt.front();
        qt.pop();

        for (auto i : adj[f])
        {
            if (!visited[i])
            {
                visited[i] = true;
                parent[i] = f; // set parent
                qt.push(i);
            }
        }
    }

    // determining the path
    vector<int> path;

    int curr = t;

    while (curr != s && curr != -1)
    {
        path.push_back(curr + 1);
        curr = parent[curr];
    }

    // we dont have any path
    if (curr == -1)
    {
        return {-1};
    }

    path.push_back(s + 1);
    reverse(path.begin(), path.end());

    return path;
}

int main()
{

    return 0;
}