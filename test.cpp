#include <bits/stdc++.h>
using namespace std;

void dfsR(vector<vector<int>> &edges,unordered_map<int, bool> &visited,vector<int> &ans, int v)
{
    if(!visited[v])
    {
        visited[v] = true;
        ans.push_back(v);

        for(auto i : edges[v])
        {
            if(!visited[i])
            {
                dfsR(edges,visited,ans,i);
            }
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{

    vector<vector<int>> ans;
    unordered_map<int, bool> visited;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            vector<int> temp;
            dfsR(edges, visited, temp, i);
            ans.push_back(temp);
        }
    }

    return ans;
}

int main()
{

    return 0;
}