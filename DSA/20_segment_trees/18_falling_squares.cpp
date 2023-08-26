#include <bits/stdc++.h>
using namespace std;

class SegTree
{
    vector<int> seg, lazy;
    int size;

    void updateHelper(int idx, int low, int high, int &l, int &r, int &val)
    {
        if (lazy[idx] != 0)
        {
            seg[idx] = max(seg[idx], lazy[idx]);

            if (low != high)
            {
                lazy[2 * idx + 1] = max(lazy[idx], lazy[2 * idx + 1]);
                lazy[2 * idx + 2] = max(lazy[idx], lazy[2 * idx + 2]);
            }

            lazy[idx] = 0;
        }

        // no overlap
        if (r < low || l > high)
            return;

        // complete overlap
        if (low >= l && high <= r)
        {
            seg[idx] = max(val, seg[idx]);

            if (low != high)
            {
                // propagate down
                lazy[2 * idx + 1] = max(val, lazy[2 * idx + 1]);
                lazy[2 * idx + 2] = max(val, lazy[2 * idx + 2]);
            }

            return;
        }

        int m = low + (high - low) / 2;
        updateHelper(2 * idx + 1, low, m, l, r, val);
        updateHelper(2 * idx + 2, m + 1, high, l, r, val);

        seg[idx] = max(seg[2 * idx + 1], seg[2 * idx + 2]);
    }

    int queryHelper(int idx, int low, int high, int &l, int &r)
    {
        if (lazy[idx] != 0)
        {
            seg[idx] = max(seg[idx], lazy[idx]);

            if (low != high)
            {
                lazy[2 * idx + 1] = max(lazy[idx], lazy[2 * idx + 1]);
                lazy[2 * idx + 2] = max(lazy[idx], lazy[2 * idx + 2]);
            }

            lazy[idx] = 0;
        }

        if (r < low || l > high)
            return 0;

        if (low >= l && high <= r)
            return seg[idx];

        int m = low + (high - low) / 2;

        int left = queryHelper(2 * idx + 1, low, m, l, r);
        int right = queryHelper(2 * idx + 2, m + 1, high, l, r);

        return max(left, right);
    }

public:
    SegTree(int n)
    {
        seg.resize(n * 4, 0);
        lazy.resize(n * 4, 0);
        size = n - 1;
    }

    void updateRange(int l, int r, int val)
    {
        updateHelper(0, 0, size, l, r, val);
    }

    int query(int left, int right)
    {
        return queryHelper(0, 0, size, left, right);
    }
};

class Solution
{
public:
    vector<int> fallingSquares(vector<vector<int>> &positions)
    {
        // all possible x co-ordinates are pushed here so that we can index x co-ordinates
        set<int> x;

        for (auto &box : positions)
        {
            // start
            x.insert(box[0]);
            // end - 1 to avoid co-incide with adjacent square
            x.insert(box[0] + box[1] - 1);
        }

        unordered_map<int, int> co_ordinate;

        int i = 0;
        for (auto &xc : x)
        {
            co_ordinate[xc] = i++;
        }

        vector<int> ans;
        SegTree st(x.size() + 2);
        int prevMax = 0;

        for (auto &box : positions)
        {
            int sIdx = co_ordinate[box[0]];
            int eIdx = co_ordinate[box[0] + box[1] - 1];

            int newH = st.query(sIdx, eIdx) + box[1];

            prevMax = max(prevMax, newH);
            ans.push_back(prevMax);

            st.updateRange(sIdx, eIdx, newH);
        }

        return ans;
    }
};

int main()
{

    return 0;
}