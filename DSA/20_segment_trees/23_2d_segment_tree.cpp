#include <bits/stdc++.h>
using namespace std;

class RangeFreqQuery
{
    vector<unordered_map<int, int>> seg;
    unordered_map<int, int> eleToIdx;
    int n;

    void build(int idx, int low, int high, vector<int> &arr)
    {
        if (low == high)
        {
            seg[idx][arr[low]]++;
            return;
        }

        int m = low + (high - low) / 2;
        build(2 * idx + 1, low, m, arr);
        build(2 * idx + 2, m + 1, high, arr);

        for (auto &e : seg[2 * idx + 1])
            seg[idx][e.first] += e.second;

        for (auto &e : seg[2 * idx + 2])
            seg[idx][e.first] += e.second;
    }

    int queryHelper(int idx, int low, int high, int &l, int &r, int &val)
    {
        if (r < low || l > high)
            return 0;

        if (low >= l && high <= r)
            return seg[idx][val];

        int m = low + (high - low) / 2;

        return queryHelper(2 * idx + 1, low, m, l, r, val) + queryHelper(2 * idx + 2, m + 1, high, l, r, val);
    }

public:
    RangeFreqQuery(vector<int> &arr)
    {
        // 2*d segment tree bnana padega
        // map elements
        n = arr.size();
        seg.resize(4 * n);
        build(0, 0, n - 1, arr);
    }

    int query(int left, int right, int value)
    {
        return queryHelper(0, 0, n - 1, left, right, value);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */

int main()
{

    return 0;
}