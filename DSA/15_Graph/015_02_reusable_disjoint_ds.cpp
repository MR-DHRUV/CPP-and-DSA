#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> rank, parent, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findSet(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findSet(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int p1 = findSet(u);
        int p2 = findSet(v);

        if (p1 == p2)
            return;
        if (rank[p1] < rank[p2])
        {
            parent[p1] = p2;
        }
        else if (rank[p2] < rank[p1])
        {
            parent[p2] = p1;
        }
        else
        {
            parent[p2] = p1;
            rank[p1]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int p1 = findSet(u);
        int p2 = findSet(v);

        if (p1 == p2)
            return;
        if (size[p1] < size[p2])
        {
            parent[p1] = p2;
            size[p2] += size[p1];
        }
        else
        {
            parent[p2] = p1;
            size[p1] += size[p2];
        }
    }
};

int main()
{

    return 0;
}