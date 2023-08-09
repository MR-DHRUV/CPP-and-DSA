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

    void buildHelper(int s, int e, int idx, vector<int> nums)
    {
        if (s == e)
        {
            seg[idx] = nums[s];
            return;
        }

        int mid = s + (e - s) / 2;

        buildHelper(s, mid, (2 * idx) + 1, nums);
        buildHelper(mid + 1, e, (2 * idx) + 2, nums);
        seg[idx] = seg[(2 * idx) + 1] + seg[(2 * idx) + 2];
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

    void updateHelper(int s, int e, int idx, int &target, int &val)
    {
        if (target < s || target > e)
            return;

        if (s == e)
        {
            seg[idx] += val;
            return;
        }

        int mid = s + (e - s) / 2;

        if (target <= mid)
            updateHelper(s, mid, (2 * idx) + 1, target, val);
        else
            updateHelper(mid + 1, e, (2 * idx) + 2, target, val);

        seg[idx] = seg[(2 * idx) + 1] + seg[(2 * idx) + 2];
    }
};

void solve()
{
    // to count inversions we need pairs such that i < j and arr[i] > arr[j]
    // so we take a frequency array with frequency of each element
    // say array is 6,5,2,3,1
    // so we take 6 and remove it from freq array and now from segment tree of freq array we need sum of count of elements in range [1,5]

    int n;
    cin >> n;
    int arr[n], maxi = -1;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        maxi = max(arr[i], maxi);
    }

    vector<int>freq(maxi + 1,0);
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }

    SegTree st(maxi + 1);
    st.buildHelper(0, maxi, 0, freq);

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        // remove the element
        freq[arr[i]]--;
        int val = -1;
        st.updateHelper(0, maxi, 0,arr[i],val);

        ans += st.queryHelper(0, 0, maxi, 1, arr[i]-1);
    }

    cout << ans << endl;
}

signed main()
{
#ifndef IO_FROM_FILE
    freopen("C:\\Users\\Dhruv\\OneDrive\\Documents\\CPP + DSA\\input.txt", "r", stdin);
    freopen("C:\\Users\\Dhruv\\OneDrive\\Documents\\CPP + DSA\\output.txt", "w", stdout);
#endif

    solve();

    return 0;
}