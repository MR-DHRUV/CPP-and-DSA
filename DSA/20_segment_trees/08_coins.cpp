#include <bits/stdc++.h>
using namespace std;

class SegTree
{
    vector<int> seg;
    vector<bool> lazy;
    int size;

    void build(int idx, int low, int high, vector<int> &nums)
    {
        if (low == high)
        {
            seg[idx] = nums[low] == 1;
            return;
        }

        int m = (low + high) / 2;

        build(2 * idx + 1, low, m, nums);
        build(2 * idx + 2, m + 1, high, nums);

        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    void updateHelper(int idx, int low, int high, int &l, int &r)
    {
        // update the previous remaning updates and propagate them
        if (lazy[idx] != 0)
        {
            // now I am flipping in rangle low, high
            // total coins = high-low+1
            // total heads = seg[idx]
            // new heads will be
            seg[idx] = (high - low + 1) - seg[idx];

            // check if there are children
            if (low != high)
            {
                // propagate down
                // not as multiple swaps aagye toh same hi rahnege
                // 2 flips is range will not cause any change
                lazy[2 * idx + 1] = !lazy[2 * idx + 1];
                lazy[2 * idx + 2] = !lazy[2 * idx + 2];
            }

            lazy[idx] = 0;
        }

        // no overlap
        if (r < low || l > high)
            return;

        // complete overlap
        if (low >= l && high <= r)
        {
            seg[idx] = (high - low + 1) - seg[idx];

            if (low != high)
            {
                // propagate down
                lazy[2 * idx + 1] = !lazy[2 * idx + 1];
                lazy[2 * idx + 2] = !lazy[2 * idx + 2];
            }

            return;
        }

        // partial overlap
        int m = (low + high) / 2;
        updateHelper(2 * idx + 1, low, m, l, r);
        updateHelper(2 * idx + 2, m + 1, high, l, r);

        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    int query(int idx, int low, int high, int &l, int &r)
    {
        // if there is previous update remaining do it and propagate down
        if (lazy[idx] != 0)
        {
            // lazy == 1 i.e flip
            seg[idx] = (high - low + 1) - seg[idx];

            // check if there are children
            if (low != high)
            {
                // propagate down
                // not as multiple swaps aagye toh same hi rahnege
                // 2 flips is range will not cause any change
                lazy[2 * idx + 1] = !lazy[2 * idx + 1];
                lazy[2 * idx + 2] = !lazy[2 * idx + 2];
            }

            lazy[idx] = 0;
        }

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
        size = nums.size() - 1;
        seg.resize(4 * size);
        lazy.resize(4 * size, false);
        build(0, 0, nums.size() - 1, nums);
    }

    void updateRange(int l, int r)
    {
        updateHelper(0, 0, size, l, r);
    }

    int heads(int left, int right)
    {
        return query(0, 0, size, left, right);
    }
};

int main()
{
    // 1 -> head
    // 0 -> tail
    // T1 query l,r  how many heads
    // T2 query flip coins in the range l,r

    vector<int> nums = {1, 1, 0, 0, 1, 0, 1};

    SegTree st(nums);
    cout << st.heads(1, 5) << endl;
    st.updateRange(1, 4);
    st.updateRange(2, 4);
    cout << st.heads(1, 5) << endl;

    return 0;
}