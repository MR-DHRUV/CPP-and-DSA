#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
    int *arr;
    int n;

public:
    // for n sized array we need 4n nodes appx (kam bhi ho skti haii par kabahi jhyada ni hongi)
    SegmentTree(int n1) : n(n1)
    {
        arr = new int[4 * n1];
    }

    // time complexity = no of nodes created
    // so worst case is O(4*n) so O(n)
    void buildHelper(int s, int e, int idx, vector<int> &nums)
    {
        if (s == e)
        {
            arr[idx] = nums[s];
            return;
        }

        int mid = s + (e - s) / 2;

        // left half
        buildHelper(s, mid, (2 * idx) + 1, nums);
        // right half
        buildHelper(mid + 1, e, (2 * idx) + 2, nums);

        // curr
        arr[idx] = min(arr[(2 * idx) + 1], arr[(2 * idx) + 2]);
    }

    void build(vector<int> &nums)
    {
        buildHelper(0, nums.size() - 1, 0, nums);
    }

    // time complexity = O(logN), since we are traversing in depth of the tree
    int queryHelper(int idx, int s, int e, int &l, int &r)
    {
        // no overlap
        if (r < s || l > e)
            return 1e9 + 7;

        // complete overlap
        if (s >= l && e <= r)
            return arr[idx];

        // partial overlap
        int mid = s + (e - s) / 2;

        int left = queryHelper((idx * 2) + 1, s, mid, l, r);
        int right = queryHelper((idx * 2) + 2, mid + 1, e, l, r);

        return min(left, right);
    }

    int query(int l, int r)
    {
        // there are 3 types of queries
        // 1 partial overlap
        // like node has a data of range 0-5 and we need data from 2-4 so that range 2-4 partially overlaps the range 0-5
        // so here we compute 0 to mid and mid+1 to end i.e
        // 0-2 and 3-4

        // 2 no over with range (l,r), so we return int max

        // 3 complete overlap with range i.e
        // I am looking for [2,5] and node has a data of [3-4] then the range of node completely overlaps the query range
        // return arr[index]

        return queryHelper(0, 0, n - 1, l, r);
    }

    // time complexity = O(logN), since we are traversing in depth of the tree
    int updateHelper(int s, int e, int idx, int &target, int &val)
    {
        // current interval ka koi lena dena nahi haii
        if (target < s || target > e)
            return 1e9;

        if (s == e)
        {
            arr[s] = val;
            return val;
        }

        int mid = s + (e - s) / 2;

        if (target <= mid)
            return updateHelper(s, mid, (2 * idx) + 1, target, val);
        else
            return updateHelper(mid + 1, e, (2 * idx) + 2, target, val);

        // now update current node
        arr[idx] = min(arr[(2 * idx) + 1], arr[(2 * idx) + 2]);
    }

    void update(int target, int val)
    {
        // point updates or update queries
        // we are now given an index and a value and we have to update the array[idx] to val
        // wohi same postorder style me values update krdo target se
        updateHelper(0, n - 1, 0, target, val);
    }
};

int main()
{
    // segement tree's are required for problems like
    // A Segment Tree is a data structure that stores information about array intervals as a tree.
    // 1 Finding minimum element in range [l,r] for q queries
    // range-query update problems in logarithmic time

    // segement tree for this minimum range based element

    // Initially we have a node that keeps the min element of range 0 to n and it is stored in an array at 0th index

    // Now it will be segemented into 2 parts (0,n/2) and (n/2+1, n)
    // storing of these segemented nodes will be same as that of heaps, left child (2*index) +1 and right child at left+1

    // Now, each node will have minimum of that range

    // we will compute in postorder fashion
    // int l = func(s,e/2)
    // int r = func(e/2 + 1 , e)
    // int mini = min(l,r)


    return 0;
}