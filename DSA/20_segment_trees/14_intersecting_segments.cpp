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
            seg[idx] = !seg[idx]; // element visited
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
    vector<int> leftEnd(n / 2 + 1, -1), rightEnd(n / 2 + 1, -1);

    // now here is all the magic that calculates intersecting segments
    // we are just having a reqular sum segment tree

    // now to calculate intersecting segment for any element ai we will update the segment tree as follows

    // when we visit the left end of any number ai we'll mark it as 1 in segment tree and we'll query noramally based on sum in range left+1, right-1 to get intersecting segments

    // now to mark any segment as not intersected, we'll mark left index as 0 when we visit its right index

    // this is to calculate intersections from left and we can reverse the logic to calculate intersections from right

    // left intersections
    for (int i = 0; i < n; i++)
    {

        // check if left is visited
        if (leftEnd[arr[i]] != -1)
        {
            // update segment tree by marking 0 at index of left end
            st.update(leftEnd[arr[i]]);

            // calculate ans for current element
            ans[arr[i]] = st.query(leftEnd[arr[i]] + 1, i - 1);
        }
        else
        {
            leftEnd[arr[i]] = i; // mark left index

            // update segment tree by marking 1 at index of left end
            st.update(i);
        }
    }

    // right intersections
    // we can use same segment tree as saare updates ke baad wo 0 hi ho jayga
    for (int i = n - 1; i >= 0; i--)
    {
        // check if right is visited
        if (rightEnd[arr[i]] != -1)
        {
            // update segment tree by marking 0 at index of left end
            st.update(rightEnd[arr[i]]);

            // calculate ans for current element
            ans[arr[i]] += st.query(i + 1, rightEnd[arr[i]] - 1);
        }
        else
        {
            // visit right edge
            rightEnd[arr[i]] = i; // mark right index

            // update segment tree by marking 1 at index of right end
            st.update(i);
        }
    }

    for (int i = 1; i <= n / 2; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}