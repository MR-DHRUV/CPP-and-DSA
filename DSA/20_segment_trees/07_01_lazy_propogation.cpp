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
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    void updateHelper(int idx, int low, int high, int &l, int &r, int &val)
    {
        // update the previous remaning updates and propagate them
        if (lazy[idx] != 0)
        {
            seg[idx] += (high - low + 1) * lazy[idx];

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
            seg[idx] += (high - low + 1) * val;

            if (low != high)
            {
                // propagate down
                lazy[2 * idx + 1] += val;
                lazy[2 * idx + 2] += val;
            }

            return;
        }

        // partial overlap
        int m = (low + high )/ 2;
        updateHelper(2 * idx + 1, low, m, l, r, val);
        updateHelper(2 * idx + 2, m + 1, high, l, r, val);

        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    int query(int idx, int low, int high, int &l, int &r)
    {
        // if there is previous update remaining do it and propagate down
        if (lazy[idx] != 0)
        {
            seg[idx] += (high - low + 1) * lazy[idx];

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
    // lazy propogation is used when we want to update all values in a range (l,r) by say +1

    // so for every node we create a corresponding lazy node initialised to 0, which is used to store updates which can be applied later on, when that node is being computed.

    // we only update the segement tree as neccessary, and rest updation is lazy updation that is propagated down

    // so again we will have 3 cases
    // 1 complete overlap
    // update the node with previous updates and current updates, lazy progagate down and return

    // 2 partially overlap
    // left, right
    // curr = left + right

    // no overlap
    // return

    vector<int> nums = {1,2,3,4,5};

    SegTree st(nums);
    cout << st.rangeSum(0,4) << endl;
    st.updateRange(1,3,2);
    cout << st.rangeSum(0,4) << endl;

    return 0;
}