#include <bits/stdc++.h>
#define ll long long int
using namespace std;

class SegTree
{
    // now we have this inversion count array and we are required to build the original permutation from it
    // arr : 0 1 1 0 3
    // we'll start from right so the count at last index is 3 and all the elements are unused till now, no the elemnt in range 1 to 5 that will have exactly 3 elements greater from it will be 2
    // so the last element s 2
    // no we'll mark 2 as used
    // now we need to find element that is greater than 0 elments excluding 2
    // and so on

    // Now, in terms of segment tree, we initially have all indices from 0-4 as 1 and we have created a sum segment tree
    // now starting from 3 we need to know the position of kth one where k = 3 from right , so originaly we need index of n-k'th one

    // now we'll mark this index as 0

    // now in next iteration if we need index of j'th one we'll make it j-1 as one element is already used and we are left with n-1 elements and so on

    ll seg[400010]{};
    ll size;

    void build(ll idx, ll low, ll high)
    {
        if (low == high)
        {
            seg[idx] = 1;
            return;
        }

        ll m = (low + high) / 2;

        build(2 * idx + 1, low, m);
        build(2 * idx + 2, m + 1, high);

        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    void updateHelper(ll idx, ll low, ll high, ll &i)
    {
        if (low == high)
        {
            seg[idx] = 0; // element visited
            return;
        }

        ll m = (low + high) / 2;

        if (i <= m)
            updateHelper(2 * idx + 1, low, m, i);
        else
            updateHelper(2 * idx + 2, m + 1, high, i);

        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    // we just need the index of k'th one
    ll queryHelper(ll idx, ll low, ll high, ll k)
    {
        if (low == high)
            return low;

        int m = (low + high) / 2;

        if (k <= seg[2 * idx + 1])
            return queryHelper(2 * idx + 1, low, m, k);
        else
            return queryHelper(2 * idx + 2, m + 1, high, k - seg[2 * idx + 1]);
    }

public:
    SegTree(int n)
    {
        size = n;
        build(0, 0, n);
    }

    void update(ll index)
    {
        updateHelper(0, 0, size, index);
    }

    ll query(ll k)
    {
        return queryHelper(0, 0, size, k);
    }
};

signed main()
{
    // #ifndef IO_FROM_FILE
    //     freopen("C:\\Users\\Dhruv\\OneDrive\\Documents\\CPP + DSA\\input.txt", "r", stdin);
    //     freopen("C:\\Users\\Dhruv\\OneDrive\\Documents\\CPP + DSA\\output.txt", "w", stdout);
    // #endif
    ll n;
    cin >> n;

    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    SegTree st(n - 1);
    vector<int> ans(n);

    // for first element
    for (int i = n - 1; i >= 0; i--)
    {
        // K = N-arr[i] - no of elements used 
        //   = i+1 - arr[i]
        ll k = i + 1 - arr[i];
        ll idx = st.query(k);

        ans[i] = idx + 1; // +1 as 0 indexed segment tree haii
        st.update(idx);
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}