#include <bits/stdc++.h>
using namespace std;

// bridge : its an critical edge on the removal of which a connected component is divided into 2 disjoint connected components

/*
    5--6
    |\
    3--9

    5--6 is an bridge
*/

// brute force approch
// remove each edge and using dfs check no of connected components

// optimised Algo -> tarjan's algo
// we need 4 data structures 1 to record discovery time , 1 to record lowest discovery time , parent and visited
// we are determing the no of ways to reach each node and nodes that have only one way, their corresponding edges are bridges

// we are traversing the graph in dfs style with some additions
// 1 we are incrimenting time in each move
// if we are at any node, first we'll check for back edges
// back edges are edges to a node that help in reching current node faster
// condition to check back edges : let current edge be u,visited [v] = true
// update the low[u]
// while returning from a dfs call , if neibghour is updated then there may exist a shorter path to reach current node, so we'll update low of current node also

// if for any edge u,v , low[v] > disc[u] that means u is the only edge through which we can reach v , thus its a bridge

void DFS(int node, int parent, int &time, vector<bool> &visited, vector<int> &disc, vector<int> &low, vector<vector<int>> &result, vector<vector<int>> &adj)
{
    if (!visited[node])
    {
        visited[node] = true;
        disc[node] = low[node] = time++;

        for (auto nbr : adj[node])
        {
            // same edge
            if (nbr == parent)
            {
                continue;
            }

            // new edge
            if (!visited[nbr])
            {
                DFS(nbr, node, time, visited, disc, low, result, adj);

                // on returning update low of current node
                low[node] = min(low[node], low[nbr]);

                // check for bridge
                if (low[nbr] > disc[node])
                {
                    result.push_back({node, nbr});
                }
            }

            // back edge
            else
            {
                // update low
                low[node] = min(low[node], disc[nbr]);
            }
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e)
{
    // Write your code here
    vector<vector<int>> adj(v);

    // making adjacency list
    for (int i = 0; i < edges.size(); i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }

    int time = 0;
    int parent = -1;

    vector<int> disc(v, INT_MAX);
    vector<int> low(v, INT_MAX);
    vector<bool> visited(v, false);

    vector<vector<int>> result;

    // start dfs
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            DFS(i, parent, time, visited, disc, low, result, adj);
        }
    }

    return result;
}

int main()
{

    return 0;
}