#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<long long> sum, parent;
    vector<bool> isPresent;
    long long ans = 0;

public:
    DisjointSet(int n)
    {
        sum.resize(n + 1, 0ll);
        isPresent.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findSet(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findSet(parent[node]);
    }

    void unite(int idx, long long val)
    {
        sum[idx] = val;
        isPresent[idx] = 1;
        ans = max(ans, val);

        // check if we can unite something
        if (idx - 1 >= 0 && isPresent[idx - 1])
        {
            int p1 = findSet(idx - 1), p2 = findSet(idx);
            if (sum[p1] > sum[p2])
            {
                sum[p1] += sum[p2];
                parent[p2] = p1;
            }
            else
            {
                sum[p2] += sum[p1];
                parent[p1] = p2;
            }

            ans = max(ans, max(sum[p1], sum[p2]));
        }

        if (idx + 1 < sum.size() && isPresent[idx + 1])
        {
            int p1 = findSet(idx + 1), p2 = findSet(idx);

            if (sum[p1] > sum[p2])
            {
                sum[p1] += sum[p2];
                parent[p2] = p1;
            }
            else
            {
                sum[p2] += sum[p1];
                parent[p1] = p2;
            }

            ans = max(ans, max(sum[p1], sum[p2]));
        }
    }

    long long getAns() { return ans; }
};

class Solution
{
public:
    vector<long long> maximumSegmentSum(vector<int> &nums, vector<int> &removeQueries)
    {
        int n = nums.size();
        DisjointSet st(n);
        vector<long long> ans(n);

        for (int i = n - 1; i >= 0; i--)
        {
            ans[i] = st.getAns();
            st.unite(removeQueries[i], nums[removeQueries[i]]);
        }

        return ans;
    }
};

int main()
{
  
  
    return 0;
}