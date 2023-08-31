#include <bits/stdc++.h>
using namespace std;

class SegTree
{
    vector<int> seg;
    vector<bool> lazy;
    int size;
    long long int sum = 0;

    void build(int idx, int low, int high, vector<int> &nums)
    {
        if (low == high)
        {
            seg[idx] = nums[low];
            return;
        }

        int m = low + (high - low) / 2;

        build(2 * idx + 1, low, m, nums);
        build(2 * idx + 2, m + 1, high, nums);
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    void merge(int idx, int low, int high)
    {
        if (lazy[idx])
        {
            seg[idx] = (high - low + 1) - seg[idx];

            // check if there are children
            if (low != high)
            {
                // propagate down
                lazy[2 * idx + 1] = !lazy[2 * idx + 1];
                lazy[2 * idx + 2] = !lazy[2 * idx + 2];
            }

            lazy[idx] = false;
        }
    }

    void updateHelper(int idx, int low, int high, int &l, int &r)
    {
        merge(idx, low, high);

        // no overlap
        if (r < low || l > high)
            return;

        // complete overlap
        if (low >= l && high <= r)
        {
            lazy[idx] = true;
            merge(idx, low, high);
            return;
        }

        // partial overlap
        int m = low + (high - low) / 2;
        updateHelper(2 * idx + 1, low, m, l, r);
        updateHelper(2 * idx + 2, m + 1, high, l, r);

        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

public:
    SegTree(vector<int> &nums, long long int s) : sum(s)
    {
        seg.resize(nums.size() * 4, 0);
        lazy.resize(nums.size() * 4, 0);
        size = nums.size() - 1;
        build(0, 0, nums.size() - 1, nums);
    }

    void updateRange(int l, int r)
    {
        updateHelper(0, 0, size, l, r);
    }

    void updateSum(int p)
    {
        long long int diff = 1ll * p * seg[0];
        sum += diff;
    }

    long long int query()
    {
        return sum;
    }
};

class Solution
{
public:
    vector<long long> handleQuery(vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &queries)
    {
        vector<long long> ans;

        long long int sum = 0;
        for (int &i : nums2)
            sum += i;

        SegTree st(nums1, sum);

        for (auto &q : queries)
        {
            if (q[0] == 1)
                st.updateRange(q[1], q[2]);
            else if (q[0] == 2)
                st.updateSum(q[1]);
            else
                ans.push_back(st.query());
        }

        return ans;
    }
};

int main()
{

    return 0;
}