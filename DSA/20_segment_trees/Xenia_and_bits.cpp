#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
    int *arr;
    int n;

public:
    SegmentTree(int n1) : n(n1)
    {
        arr = new int[4 * n1];
    }

    void buildHelper(int s, int e, int idx, vector<int> &nums, bool OR)
    {
        if (s == e)
        {
            arr[idx] = nums[s];
            return;
        }

        int mid = s + (e - s) / 2;

        buildHelper(s, mid, (2 * idx) + 1, nums, !OR);
        buildHelper(mid + 1, e, (2 * idx) + 2, nums, !OR);

        if (OR)
            arr[idx] = arr[(2 * idx) + 1] | arr[(2 * idx) + 2];
        else
            arr[idx] = arr[(2 * idx) + 1] ^ arr[(2 * idx) + 2];
    }

    void build(vector<int> &nums, int n2)
    {
        // n levels haii humare pass
        // if n is even the last operation will be xor
        // and the root of the tree will the ans that we need
        if (n2 % 2 == 0)
            buildHelper(0, nums.size() - 1, 0, nums, false);
        else
            buildHelper(0, nums.size() - 1, 0, nums, true);
    }

    int query()
    {
        return arr[0];
    }

    void updateHelper(int s, int e, int idx, int &target, int &val, bool OR)
    {
        // current interval ka koi lena dena nahi haii
        if (target < s || target > e)
            return;

        if (s == e)
        {
            arr[target] = val;
            return;
        }

        int mid = s + (e - s) / 2;

        if (target <= mid)
            return updateHelper(s, mid, (2 * idx) + 1, target, val, !OR);
        else
            return updateHelper(mid + 1, e, (2 * idx) + 2, target, val, !OR);

        // now update current node
        if (OR)
            arr[idx] = arr[(2 * idx) + 1] | arr[(2 * idx) + 2];
        else
            arr[idx] = arr[(2 * idx) + 1] ^ arr[(2 * idx) + 2];
    }

    void update(int target, int val, int n2)
    {
        if (n2 % 2 == 0)
            updateHelper(0, n - 1, 0, target, val, false);
        else
            updateHelper(0, n - 1, 0, target, val, true);
    }
};

void solve()
{
    // dekho pahle segment tree banalo for initial data then update it and print root
    int n, m;
    cin >> n >> m;
    int ele = pow(2, n);
    vector<int> arr(ele);
    for (int i = 0; i < ele; i++)
    {
        cin >> arr[i];
    }

    SegmentTree st(ele);
    st.build(arr, n);

    while (m--)
    {
        int i, val;
        cin >> i >> val;
        i--; // 1 based indexing
        st.update(i, val, n);

        cout << st.query() << endl;
    }
}

signed main()
{

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

#ifndef IO_FROM_FILE
    freopen("C:\\Users\\Dhruv\\OneDrive\\Documents\\CPP + DSA\\input.txt", "r", stdin);
    freopen("C:\\Users\\Dhruv\\OneDrive\\Documents\\CPP + DSA\\output.txt", "w", stdout);
#endif

    solve();

    return 0;
}