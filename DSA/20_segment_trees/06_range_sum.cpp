#include <bits/stdc++.h>
using namespace std;

class SegTree
{
    vector<int> seg;
    int size;

    void build(int idx, int low, int high, vector<int> &nums)
    {
        if (low == high)
        {
            seg[idx] = nums[low];
            return;
        }

        int m = (low + high) / 2;

        build(2 * idx + 1, low, m, nums);
        build(2 * idx + 2, m + 1, high, nums);
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    void updateHelper(int idx, int low, int high, int &i, int &val)
    {
        if (low == high)
        {
            seg[idx] = val;
            return;
        }

        int m = (low + high) / 2;

        if (i <= m)
            updateHelper(2 * idx + 1, low, m, i, val);
        else
            updateHelper(2 * idx + 2, m + 1, high, i, val);

        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    int query(int idx, int low, int high, int &l, int &r)
    {
        if (r < low || l > high)
            return 0;

        if (low >= l && high <= r)
            return seg[idx];

        int m = (low + high) / 2;

        int left = query(2 * idx + 1, low, m, l, r);
        int right = query(2 * idx + 2, m + 1, high, l, r);

        return left + right;
    }

public:
    SegTree(vector<int> &nums)
    {
        seg.resize(nums.size() * 4);
        size = nums.size() - 1;
        build(0, 0, nums.size() - 1, nums);
    }

    void update(int index, int val)
    {
        updateHelper(0, 0, size, index, val);
    }

    int sumRange(int left, int right)
    {
        return query(0, 0, size, left, right);
    }
};

int main()
{
    return 0;
}