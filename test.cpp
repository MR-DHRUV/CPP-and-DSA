#include <bits/stdc++.h>
using namespace std;

void dfs(int k, string current, unordered_set<string> &visited, vector<int> &path)
{
    for (int i = 0; i < k; i++)
    {
        string next = current + static_cast<char>('0' + i);
        if (visited.find(next) == visited.end())
        {
            visited.insert(next);
            dfs(k, next.substr(1), visited, path);
            path.push_back(i);
        }
    }
}

string findString(int n, int k)
{
    // code here
    unordered_set<string> visited;
    string startingNode(n - 1, '0');
    vector<int> path;

    dfs(k, startingNode, visited, path);

    stringstream result;
    int totalPaths = pow(k, n);

    for (int i = 0; i < totalPaths; i++)
    {
        result << path[i];
    }

    result << startingNode;

    return result.str();
}



int main()
{
    cout << findString(3, 5) << endl;

    return 0;
}