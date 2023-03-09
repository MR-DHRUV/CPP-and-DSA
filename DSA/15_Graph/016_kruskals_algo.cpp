#include <bits/stdc++.h>
using namespace std;

class disjointSet
{
    int n;

    vector<int> parent;
    vector<int> rank;

public:
    disjointSet(int num)
    {
        n = num;
        rank = vector<int>(n, 0);
        parent = vector<int>(n);

        for (int i = 0; i < n; i++)
        {
            parent[i] = i; // initially sab apne parent h
        }

    }

    int findParent(int node)
    {
        if (parent[node] == node)
        {
            return node;
        }

        // path compression , taaki next time O(1) me khooj lu
        return parent[node] = findParent(parent[node]);
    }

    // returns true if 2 disjoint sets are united
    bool unionSet(int &s1, int &s2)
    {
        int p1 = findParent(s1);
        int p2 = findParent(s2);

        bool ans = false;

        // can be only united iff they dont have same parents
        if (p1 != p2)
        {
            ans = true;

            if (rank[p1] < rank[p2])
            {
                parent[p1] = p2; // update parent
            }
            else if (rank[p1] > rank[p2])
            {
                parent[p2] = p1;
            }
            else
            {
                parent[p2] = p1;

                // update rank
                rank[p1]++;
            }
        }

        return ans;
    }
};

// sorts on the basis of weights
bool compare(vector<int> &e1, vector<int> &e2)
{
    return e1[2] < e2[2];
}

// building mst using kruskals
int minimumSpanningTree(vector<vector<int>> &edges, int n)
{
    // using kruskals we dont need adj list, we need disjoint sets
    disjointSet s(n);

    // sorting the edges on the basis of weight
    // since we'll include min weighted edge everytime such that any of vertices of this edge is not included in mst before

    sort(edges.begin(), edges.end(), compare);

    int ans = 0;

    for (auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        if (s.unionSet(u, v))
        {
            // they are already united
            ans += w;
        }
    }

    return ans;
}




int main()
{

    return 0;
}