#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> parent;
    vector<int> rank;

public:
    // init and make set
    DisjointSet(int n)
    {
        parent = vector<int>(n);
        rank = vector<int>(n, 0); // sabki rank 0 haii initially

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int findSet(int x)
    {
        if (parent[x] == x)
            return x;

        // path reduction
        return parent[x] = findSet(parent[x]);
    }

    bool unionSet(int x, int y)
    {
        int p1 = findSet(x);
        int p2 = findSet(y);

        if (p1 != p2)
        {
            if (rank[p1] > rank[p2])
            {
                parent[p2] = p1;
            }
            else if (rank[p1] < rank[p2])
            {
                parent[p1] = p2;
            }
            else
            {
                parent[p1] = p2;
                rank[p2]++;
            }

            return true;
        }
        return false;
    }
};

int main()
{

    return 0;
}