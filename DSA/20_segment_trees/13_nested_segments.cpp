#include <bits/stdc++.h>
#define ll long long int
using namespace std;

class SegTree
{
    ll seg[800010]{0};
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

    // we need the sum of 1's
    ll queryHelper(ll idx, ll low, ll high, ll &l, ll &r)
    {
        if (r < low || l > high)
            return 0;

        if (low >= l && high <= r)
            return seg[idx];

        int m = (low + high) / 2;

        ll left = queryHelper(2 * idx + 1, low, m, l, r);
        ll right = queryHelper(2 * idx + 2, m + 1, high, l, r);

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
    n *= 2;
    vector<ll> arr(n);

    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    SegTree st(n - 1);
    vector<int> ans(n / 2 + 1);
    vector<int> leftEnd(n / 2 + 1, -1);

    for (int i = 0; i < n; i++)
    {
        // now here is all the magic that calculates nested segments
        // we are just having a reqular sum segment tree

        // now to calculate nested segment for any element ai we will update the segment tree as follows

        // when we visit right end of any segment we'll mark its left as 1 in segment tree
        // now for any element after this index we can query sum from segment tree as its right boundary is ahead from the right of previous index and we just need to check the left boundary
        // so we'll calculate the sum in range left+1,right-1 to get nested segments for current index

        // check if left is visited
        if (leftEnd[arr[i]] != -1)
        {
            // calculate ans for current element
            ans[arr[i]] = st.query(leftEnd[arr[i]] + 1, i - 1);

            // update segment tree by marking 1 at index of left end
            st.update(leftEnd[arr[i]]);
        }
        else
        {
            leftEnd[arr[i]] = i; // mark left index
        }
    }

    for (int i = 1; i <= n / 2; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}