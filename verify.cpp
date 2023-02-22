#include <bits/stdc++.h>
using namespace std;

void BFS(int V, vector<int> adj[])
{
    queue<int> qt;
    bool visited[V] = {false};

    // starting from 0
    qt.push(0);
    cout << "0 ";
    visited[0] = true;

    while (!qt.empty())
    {
        int t = qt.front();
        qt.pop();

        for (int i = 0; i < V; i++)
        {
            if (adj[t][i] == 1 && visited[i] == false)
            {
                visited[i] == true;
                cout << i << " ";
                qt.push(i);
            }
        }
    }
}

void DFSRec(bool *visited, vector<int> adj[], int src, int V)
{
    if (visited[src] == false)
    {
        cout << src << " ";
        visited[src] = true;

        for (int i = 0; i < V; i++)
        {
            if (adj[src][i] == 1 && visited[i] == false)
            {
                DFSRec(visited, adj, i, V);
            }
        }
    }
}

void DFS(vector<int> adj[], int V)
{
    bool visited[V] = {false};

    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
        {
            DFSRec(visited, adj, i, V);
        }
    }
}

int main()
{

    return 0;
}