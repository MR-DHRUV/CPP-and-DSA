#include <bits/stdc++.h>
#define ll long long int
using namespace std;

class SegTree
{
    // Now we need to count inversions for each index i such that i > j and arr[i] < arr[j]
    // So initially we'll have a frequency array initialised to 0, thus we dont need to build the tree all the elements are 0
    // as we visit elements we find ans for them and update the segment tree
    // segment tree is made up of frequency array
    // we will be given with 1-n elements all unique
    // we just need to build the sum segment tree that will tell the sum of count of elements in a given range or just need a segmentt tree for frequency array
    ll seg[400010]{0};
    ll size;

    void updateHelper(ll idx, ll low, ll high, ll &i)
    {
        if (low == high)
        {
            seg[idx] = 1; // element visited
            return;
        }

        ll m = (low + high) / 2;

        if (i <= m)
            updateHelper(2 * idx + 1, low, m, i);
        else
            updateHelper(2 * idx + 2, m + 1, high, i);

        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    // we just need the sum in range l,r
    ll queryHelper(ll idx, ll low, ll high, ll &l, ll &r)
    {
        if (r < low || l > high)
            return 0;

        if (low >= l && high <= r)
            return seg[idx];

        ll mid = (low + high) / 2;

        ll left = queryHelper(2 * idx + 1, low, mid, l, r);
        ll right = queryHelper(2 * idx + 2, mid + 1, high, l, r);

        return left + right;
    }

public:
    SegTree(int n)
    {
        size = n;
    }

    void update(ll index)
    {
        updateHelper(0, 0, size, index);
    }

    ll query(ll l, ll r)
    {
        return queryHelper(0, 0, size, l, r);
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
    ll mx = -1;
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
        mx = max(mx, arr[i]);
    }

    SegTree st(mx);

    // for first element
    cout << 0 << " ";
    st.update(arr[0]);

    for (int i = 1; i < n; i++)
    {
        cout << st.query(arr[i] + 1, mx) << " ";
        st.update(arr[i]);
    }

    return 0;
}