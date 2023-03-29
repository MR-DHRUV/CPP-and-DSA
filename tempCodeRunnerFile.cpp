#include <bits/stdc++.h>
using namespace std;

int minColour(int N, int M, vector<int> mat[])
{
    vector<int> in(N + 1, 0);
    vector<vector<int>> ad(N + 1);

    for (int i = 0; i < M; i++)
    {
        in[mat[i][0]]++;
        ad[mat[i][1]].push_back(mat[i][0]);
    }

    queue<int> qt;

    for (int i = 1; i <= N; i++)
    {
        if (in[i] == 0)
        {
            qt.push(i);
        }
    }

    int ans = 0;

    while (qt.size() != 0)
    {
        int k = qt.size();
        for (int i = 0; i < k; i++)
        {
            int node = qt.front();
            qt.pop();
            for (int j = 0; j < ad[node].size(); j++)
            {
                if (in[ad[node][j]] >= 1)
                {
                    in[ad[node][j]]--;
                    if (in[ad[node][j]] == 0)
                    {
                        qt.push(ad[node][j]);
                    }
                }
            }
        }
        ans++;
    }

    return ans;
}

int main()
{

    return 0;
}