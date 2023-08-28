#include <bits/stdc++.h>
using namespace std;

// segment tree for finding max
class SegTree
{
    int *seg;
    int size;

    void updateHelper(int idx, int low, int high, int &i, int &val)
    {
        if (low == high)
        {
            seg[idx] = max(seg[idx], val);
            return;
        }

        int m = low + (high - low) / 2;

        if (i <= m)
            updateHelper(2 * idx + 1, low, m, i, val);
        else
            updateHelper(2 * idx + 2, m + 1, high, i, val);

        seg[idx] = max(seg[2 * idx + 1], seg[2 * idx + 2]);
    }

    int queryHelper(int idx, int low, int high, int &l, int &r)
    {
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
        size = n - 1;
        seg = new int[4 * n]{0};
    }

    void update(int i, int val)
    {
        updateHelper(0, 0, size, i, val);
    }

    int query(int left, int right)
    {
        return queryHelper(0, 0, size, left, right);
    }
};

class Solution
{
public:
    vector<int> maximumSumQueries(vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &queries)
    {
        // we need max sum from pair nums1[j]+nums2[j] such that
        // nums1[j] >= x and nums2[j] >= y for each query [x,y]

        // intuition
        // we'int create an array of pairs (nums1[i],nums2[i]) and we'int sort it according to nums1
        // now if we find lower_bound of x on this sorted array we can have the indices that we need to concider in nums1
        // now we need to find max sum such that nums2[j] > y
        // now to tackle this y constraint we'int do the following
        // we'int sort the queries in decreasing order of x, i.e the one with max value of x will be our first query
        // this will help us in only processing the pairs with nums1 value >= x and no redundant pairs
        // now for every query we will first add pairs in range lower_bound(x) and prevMin (maii pahle kaha tk add krchuka hu) in our segement tree
        // we'int add in segment tree such that at index nums2[i] we'int update nums1[i]+nums2[i] in segment tree
        // now this will help us to find the max sum with y constarint as we are only having pairs with nums1 values >= x as we have sorted the queries

        // To summerize
        // 1 we'int create an array of pairs (nums1[i],nums2[i]) and we'int sort it according to nums1
        // 2 sort queries in dec order of x
        // 3 for any query Q, we will find lower_bound(x) and add new pairs in our segment tree
        // and ans = st.query(y,n-1)
        // 4 we have to normalize y indices i.e elements of nums2

        // 4 normalization of nums2
        vector<int> nums2Elements(nums2.begin(), nums2.end());
        sort(nums2Elements.begin(), nums2Elements.end());
        nums2Elements.erase(unique(nums2Elements.begin(), nums2Elements.end()), nums2Elements.end());

        // 2 sorting queries
        // maintaining original indices
        int count = 0;
        for (auto &q : queries)
            q.push_back(count++);

        sort(queries.begin(), queries.end(), [](vector<int> &a, vector<int> &b)
             { return a[0] > b[0]; });

        // 1 array of pairs (nums1[i],nums2[i])
        int n = nums1.size();
        vector<pair<int, int>> nums;

        for (int i = 0; i < n; i++)
            nums.push_back({nums1[i], nums2[i]});

        sort(nums.begin(), nums.end());

        // init
        SegTree st(n + 1);
        vector<int> ans(queries.size(), -1);
        int addTill = n;

        for (auto q : queries)
        {
            int x_start = lower_bound(nums.begin(), nums.end(), make_pair(q[0], 0)) - nums.begin();

            // adding pairs to segTree
            for (int i = x_start; i < addTill; i++)
            {
                // update value at nums2[i] index with sum
                int idx = lower_bound(nums2Elements.begin(), nums2Elements.end(), nums[i].second) - nums2Elements.begin();
                int sum = nums[i].second + nums[i].first;

                st.update(idx, sum);
            }

            addTill = x_start;

            // limit is on min, so the maximum value can be max in array
            int y_start = lower_bound(nums2Elements.begin(), nums2Elements.end(), q[1]) - nums2Elements.begin();
            int max_sum = st.query(y_start, n - 1);
            ans[q[2]] = (max_sum == 0 ? -1 : max_sum);
            // aaa
        }

        return ans;
    }
};

int main()
{
    return 0;
}