#include <bits/stdc++.h>
using namespace std;

class SegTree
{
    vector<int> seg, lazy;
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
        seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
    }

    void updateHelper(int idx, int low, int high, int &l, int &r, int &val)
    {
        // update the previous remaning updates and propagate them
        if (lazy[idx] != 0)
        {
            seg[idx] += lazy[idx]; // minimum will be changed by this factor only as all the nodes below it will be changed by same factor and so will be the minimum

            // check if there are children
            if (low != high)
            {
                // propagate down
                lazy[2 * idx + 1] += lazy[idx];
                lazy[2 * idx + 2] += lazy[idx];
            }

            lazy[idx] = 0;
        }

        // no overlap
        if (r < low || l > high)
            return;

        // complete overlap
        if (low >= l && high <= r)
        {
            seg[idx] += val;

            if (low != high)
            {
                // propagate down
                lazy[2 * idx + 1] += val;
                lazy[2 * idx + 2] += val;
            }

            return;
        }

        // partial overlap
        int m = (low + high) / 2;
        updateHelper(2 * idx + 1, low, m, l, r, val);
        updateHelper(2 * idx + 2, m + 1, high, l, r, val);

        seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
    }

    int query(int idx, int low, int high, int &l, int &r)
    {
        // if there is previous update remaining do it and propagate down
        if (lazy[idx] != 0)
        {
            seg[idx] += lazy[idx];

            // check if there are children
            if (low != high)
            {
                // propagate down
                lazy[2 * idx + 1] += lazy[idx];
                lazy[2 * idx + 2] += lazy[idx];
            }

            lazy[idx] = 0;
        }

        if (r < low || l > high)
            return 1e9;

        if (low >= l && high <= r)
            return seg[idx];

        int m = (low + high) / 2;

        int left = query(2 * idx + 1, low, m, l, r);
        int right = query(2 * idx + 2, m + 1, high, l, r);

        return min(left, right);
    }

public:
    SegTree(vector<int> &nums)
    {
        seg.resize(nums.size() * 4);
        lazy.resize(nums.size() * 4, 0);

        size = nums.size() - 1;
        
        build(0, 0, nums.size() - 1, nums);
    }

    void updateRange(int l, int r, int val)
    {
        updateHelper(0, 0, size, l, r, val);
    }

    int rangeSum(int left, int right)
    {
        return query(0, 0, size, left, right);
    }
};

int main()
{
    // this is for range minimum

    vector<int> nums = {1, 2, 3, 4, 5};

    SegTree st(nums);
    cout << st.rangeSum(0, 4) << endl;
    st.updateRange(0, 3, 2);
    cout << st.rangeSum(0, 4) << endl;

    return 0;
}