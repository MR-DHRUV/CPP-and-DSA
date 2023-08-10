#include <bits/stdc++.h>
#define ll long long int
using namespace std;

class SegTree
{
    // this is a question of desending the segment tree pattern
    ll seg[400010];
    ll size;

    void build(ll idx, ll low, ll high, vector<ll> &nums)
    {
        if (low == high)
        {
            seg[idx] = nums[low];
            return;
        }

        ll m = (low + high) / 2;

        build(2 * idx + 1, low, m, nums);
        build(2 * idx + 2, m + 1, high, nums);

        seg[idx] = max(seg[2 * idx + 1], seg[2 * idx + 2]);
    }

    void updateHelper(ll idx, ll low, ll high, ll &i, ll &val)
    {
        if (low == high)
        {
            seg[idx] = val;
            return;
        }

        ll m = (low + high) / 2;

        if (i <= m)
            updateHelper(2 * idx + 1, low, m, i, val);
        else
            updateHelper(2 * idx + 2, m + 1, high, i, val);

        seg[idx] = max(seg[2 * idx + 1], seg[2 * idx + 2]);
    }

    // here is how we will find index j such that value at that index is >= k and J >= i
    ll queryHelper(ll idx, ll low, ll high, ll &k, ll &i)
    {
        if (high < i)
            return 2e9 + 7;

        if (seg[idx] < k)
            return 2e9 + 7;

        if (low == high)
        {
            if (seg[idx] >= k)
                return low;

            return 2e9 + 7;
        }

        ll mid = (low + high) / 2;

        ll ans = queryHelper(2 * idx + 1, low, mid, k, i);
        if (ans >= 2e9 + 7)
            ans = queryHelper(2 * idx + 2, mid + 1, high, k, i);

        return ans;
    }

public:
    SegTree(vector<ll> &nums)
    {
        size = nums.size() - 1;
        build(0, 0, nums.size() - 1, nums);
    }

    void update(ll index, ll val)
    {
        updateHelper(0, 0, size, index, val);
    }

    ll query(ll k, ll i)
    {
        ll ans = queryHelper(0, 0, size, k, i);
        return ans >= 2e9 + 7 ? -1 : ans;
    }
};

signed main()
{
    // #ifndef IO_FROM_FILE
    //     freopen("C:\\Users\\Dhruv\\OneDrive\\Documents\\CPP + DSA\\input.txt", "r", stdin);
    //     freopen("C:\\Users\\Dhruv\\OneDrive\\Documents\\CPP + DSA\\output.txt", "w", stdout);
    // #endif

    ll n, m;
    cin >> n >> m;

    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    SegTree st(arr);
    ll a, b, c;

    while (m--)
    {
        cin >> a;
        cin >> b >> c;

        if (a == 1)
        {
            st.update(b, c);
        }
        else
        {
            cout << st.query(b, c) << endl;
        }
    }

    return 0;
}