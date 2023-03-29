#include <bits/stdc++.h>
using namespace std;

// dijkstra's algo can't handle -ve weighted edges, thus if a graph contains -ve weighted edges then we use bellman ford's algo to determine shortest path

// it can also detect -ve edge cycles

int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges)
{
    // Algo
    // we'll relax any vertex n-1 times
    // why n-1, as in n-1 times we can travell to all other edges and determine shortest path till ant point by travelling through different paths
    // then in nth relaxation if a distance is reduced further then there exists a -ve edge cycle

    vector<int> dist(n + 1, INT_MAX);
    dist[src] = 0;

    // n-1 times
    for (int i = 0; i < n - 1; i++)
    {
        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            // relax
            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    // check for -ve edge cycle
    bool flag = false;
    for (auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        // relax
        if (dist[u] != INT_MAX && dist[u] + w < dist[v])
        {
            // current edge is a part of -ve edge cycle
            flag = true;
        }
    }

    // since it is given as a constraint that -ve cycles will not be present , so no need to check
    return dist[dest];
}

int main()
{

    return 0;
}