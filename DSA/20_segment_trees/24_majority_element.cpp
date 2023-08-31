#include <bits/stdc++.h>
using namespace std;

class SegTree
{
    vector<pair<int, int>> seg;
    int size;

    // this is the main logic
    // this merge function is based on moore's voting algorithm
    // here we are finding normalised votes for majority element in each sub array
    // say 2 has 3 votes and 1 has 2 votes so the mojority element will 2 with normalised votes = 1
    // if equal then we can make anyone majority with normalised votes = 0
    // in this way if we merge nodes then each node in segment tree will represent the majority element in that range

    // Note that segment tree does not provide count of majority
    pair<int, int> merge(pair<int, int> &a, pair<int, int> &b)
    {
        if (a.first == b.first)
            return {a.first, a.second + b.second};
        else if (a.second > b.second)
            return {a.first, a.second - b.second};
        else
            return {b.first, b.second - a.second};
    }

    void build(int idx, int low, int high, vector<int> &nums)
    {
        if (low == high)
        {
            seg[idx] = {nums[low], 1};
            return;
        }

        int m = (low + high) / 2;

        build(2 * idx + 1, low, m, nums);
        build(2 * idx + 2, m + 1, high, nums);

        seg[idx] = merge(seg[idx * 2 + 1], seg[2 * idx + 2]);
    }

    pair<int, int> queryHelper(int idx, int low, int high, int &l, int &r)
    {
        if (r < low || l > high)
            return {0, 0};

        if (low >= l && high <= r)
            return seg[idx];

        int m = (low + high) / 2;

        auto left = queryHelper(2 * idx + 1, low, m, l, r);
        auto right = queryHelper(2 * idx + 2, m + 1, high, l, r);

        return merge(left, right);
    }

public:
    SegTree(vector<int> &nums)
    {
        size = nums.size() - 1;
        seg.resize(4 * nums.size());
        build(0, 0, size, nums);
    }

    int query(int l, int r)
    {
        return queryHelper(0, 0, size, l, r).first;
    }
};

class MajorityChecker
{
    SegTree *st;
    unordered_map<int, vector<int>> indices;

public:
    MajorityChecker(vector<int> &arr)
    {
        // just build a segment tree to store majority element or the maximum occuring element in any range along with its frequency
        st = new SegTree(arr);

        // store indices of element to get their count
        for (int i = 0; i < arr.size(); i++)
        {
            // yeh indices already sorted haii toh hum lower bound se range nikal skte haii
            indices[arr[i]].push_back(i);
        }
    }

    int query(int left, int right, int threshold)
    {
        int ele = st->query(left, right);

        // now we have the majority element of the range now we need its count
        auto &idx = indices[ele];

        int s = lower_bound(idx.begin(), idx.end(), left) - idx.begin();
        int e = upper_bound(idx.begin(), idx.end(), right) - idx.begin() - 1;
        int count = e - s + 1;

        if (count >= threshold)
            return ele;

        return -1;
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */

int main()
{

    return 0;
}