#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> Graph;

int dist(int u, int v, const Graph &graph)
{
    vector<bool> visited(graph.size(), false);
    queue<int> q;

    q.push(u);
    visited[u] = true;
    int distance = 0;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        if (curr == v)
        {
            return distance;
        }

        for (int neighbor : graph[curr])
        {
            if (!visited[neighbor])
            {
                q.push(neighbor);
                visited[neighbor] = true;
                distance++;
            }
        }
    }

    return -1; // No path between u and v
}

bool canWin(int player, int a, int b, int c, const Graph &graph)
{
    if (player == 1)
    { // Player A
        return dist(a, c, graph) <= 1;
    }
    else if (player == 2)
    { // Player B
        return dist(b, c, graph) <= 1;
    }
    else
    { // Player C
        return dist(a, b, graph) <= 1;
    }
}

string solveTestCase()
{
    int n;
    cin >> n;

    int a, b, c;
    cin >> a >> b >> c;

    Graph graph(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // Check if any player can win immediately
    if (canWin(1, a, b, c, graph))
    {
        return "A";
    }
    else if (canWin(2, a, b, c, graph))
    {
        return "B";
    }
    else if (canWin(3, a, b, c, graph))
    {
        return "C";
    }

    // If no player can win immediately, the game will continue forever
    return "DRAW";
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string result = solveTestCase();
        cout << result << endl;
    }

    return 0;
}