#include <bits/stdc++.h>
using namespace std;

class SegTree
{
public:
    int *seg;

    SegTree(int n)
    {
        seg = new int[4 * n];
    }

    bool isPeak(int idx, vector<int> &nums)
    {
        if (idx > 0 && idx < nums.size() - 1 && nums[idx] > nums[idx + 1] && nums[idx] > nums[idx - 1])
            return 1;

        return 0;
    }

    void buildHelper(int s, int e, int idx, vector<int> &nums)
    {
        if (s == e)
        {
            seg[idx] = isPeak(s, nums);
            return;
        }

        int mid = s + (e - s) / 2;
        buildHelper(s, mid, (2 * idx) + 1, nums);
        buildHelper(mid + 1, e, (2 * idx) + 2, nums);

        seg[idx] = seg[(2 * idx) + 1] + seg[(2 * idx) + 2];
    }

    void build(vector<int> &nums)
    {
        buildHelper(0, nums.size() - 1, 0, nums);
    }

    int queryHelper(int idx, int s, int e, int l, int r)
    {
        if (r < s || l > e)
            return 0;

        if (s >= l && e <= r)
            return seg[idx];

        int mid = s + (e - s) / 2;

        int left = queryHelper((idx * 2) + 1, s, mid, l, r);
        int right = queryHelper((idx * 2) + 2, mid + 1, e, l, r);

        return left + right;
    }

    int query(int l, int r, vector<int> &nums)
    {
        return queryHelper(0, 0, nums.size() - 1, l, r);
    }

    void updateHelper(int s, int e, int idx, int &target, vector<int> &nums)
    {
        if (target < s || target > e)
            return;

        if (s == e)
        {
            seg[idx] = isPeak(s, nums);
            return;
        }

        int mid = s + (e - s) / 2;
        if (target <= mid)
            updateHelper(s, mid, (2 * idx) + 1, target, nums);
        else
            updateHelper(mid + 1, e, (2 * idx) + 2, target, nums);

        seg[idx] = seg[(2 * idx) + 1] + seg[(2 * idx) + 2];
    }

    void update(int target, vector<int> &nums)
    {
        updateHelper(0, nums.size() - 1, 0, target, nums);
    }
};

class Solution
{
public:
    vector<int> countOfPeaks(vector<int> &nums, vector<vector<int>> &queries)
    {
        SegTree st(nums.size());
        vector<int> ans;
        st.build(nums);

        for (auto &q : queries)
        {
            if (q[0] == 1)
                ans.push_back(st.query(q[1] + 1, q[2] - 1, nums));
            else
            {
                nums[q[1]] = q[2];
                if (q[1] > 0)
                    st.update(q[1] - 1, nums);

                st.update(q[1], nums);
                if (q[1] < nums.size() - 1)
                    st.update(q[1] + 1, nums);
            }
        }

        return ans;
    }
};