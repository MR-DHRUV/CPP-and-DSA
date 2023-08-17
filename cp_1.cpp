#include <bits/stdc++.h>
#define ll long long int
using namespace std;

class SegTree
{
    vector<ll> seg, ans;
    ll size = 40;

    void update(ll idx, ll low, ll high, int target)
    {
        if (low == high)
        {
            seg[idx]++; // one more occurance of this element is found
            return;
        }

        ll m = (low + high) >> 1;

        if (target <= m)
            update(2 * idx + 1, low, m, target);
        else
            update(2 * idx + 2, m + 1, high, target);

        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    ll queryHelper(ll idx, ll low, ll high, ll l, ll r)
    {
        if (r < low || l > high)
            return 0;

        if (low >= l && high <= r)
            return seg[idx];

        ll mid = (low + high) >> 1;
        ll left = queryHelper(2 * idx + 1, low, mid, l, r);
        ll right = queryHelper(2 * idx + 2, mid + 1, high, l, r);

        return left + right;
    }

public:
    void construct(vector<ll> &nums)
    {
        seg = vector<ll>(180, 0);
        ans = vector<ll>(nums.size(), 0); // stores inversion count for any index i

        for (int i = 0; i < nums.size(); i++)
        {
            // prefix sum ans to answer queries in O(1)
            ans[i] = queryHelper(0, 0, size, nums[i] + 1, 40);
            update(0, 0, size, nums[i]);
        }
    }

    ll query(ll &l, ll &r)
    {
        ll sum = 0;
        for (int i = l; i <= r; i++)
        {
            sum += ans[i];
        }

        return sum;
    }
};

int main()
{
#ifndef IO_FROM_FILE
    freopen("C:\\Users\\Dhruv\\OneDrive\\Documents\\CPP + DSA\\input.txt", "r", stdin);
    freopen("C:\\Users\\Dhruv\\OneDrive\\Documents\\CPP + DSA\\output.txt", "w", stdout);
#endif

    // increases speed by prventing the overhead
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, q, t, a, b;
    cin >> n >> q;
    vector<ll> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    SegTree st;
    st.construct(arr);

    while (q--)
    {
        cin >> t >> a >> b;

        if (t == 1)
        {
            // t1 query
            cout << st.query(--a, --b) << endl;
        }
        else
        {
            // 1 based indexing
            a--;
            arr[a] = b;

            // rebuild the tree for t2 query
            st.construct(arr);
        }
    }

    return 0;
}
