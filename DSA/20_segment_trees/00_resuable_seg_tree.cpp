#include <bits/stdc++.h>
using namespace std;

static int speedup = []()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

#pragma GCC optimize("O3")

class SegTree
{
public:
    int seg[400001]{};

    SegTree(vector<int> &nums)
    {
        buildHelper(0, nums.size() - 1, 0, nums);
    }

    inline int Compare(int a, int b)
    {
        return a + b;
    }

    inline bool isPeak(int idx, vector<int> &nums)
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

        seg[idx] = Compare(seg[(2 * idx) + 1], seg[(2 * idx) + 2]);
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

        return Compare(left, right);
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

        seg[idx] = Compare(seg[(2 * idx) + 1], seg[(2 * idx) + 2]);
    }

    void update(int target, vector<int> &nums)
    {
        updateHelper(0, nums.size() - 1, 0, target, nums);
    }

    int query(int l, int r, vector<int> &nums)
    {
        return queryHelper(0, 0, nums.size() - 1, l, r);
    }
};

int main()
{

    return 0;
}