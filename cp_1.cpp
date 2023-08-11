#include <bits/stdc++.h>
#define ll long long int
using namespace std;

class SegTree
{
    ll seg[400010]{0}, lazy[400010]{0};
    ll size;

    // range update
    void updateHelper(ll idx, ll low, ll high, ll &l, ll &r, ll &val)
    {
        // check for previous update
        if (lazy[idx] != 0)
        {
            seg[idx] += (high - low + 1) * lazy[idx];

            // propagate down
            if (low != high)
            {
                lazy[2 * idx + 1] += lazy[idx];
                lazy[2 * idx + 2] += lazy[idx];
            }

            lazy[idx] = 0;
        }

        if (r < low || l > high)
            return;

        if (low >= l && high <= r)
        {
            seg[idx] += (high - low + 1) * val;

            // propagate down
            if (low != high)
            {
                lazy[2 * idx + 1] += val;
                lazy[2 * idx + 2] += val;
            }

            return;
        }

        ll m = (low + high) / 2;

        updateHelper(2 * idx + 1, low, m, l, r, val);
        updateHelper(2 * idx + 2, m + 1, high, l, r, val);

        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    ll query(ll idx, ll low, ll high, ll &i)
    {
        if (lazy[idx] != 0)
        {
            seg[idx] += (high - low + 1) * lazy[idx];

            // check if there are children
            if (low != high)
            {
                // propagate down
                lazy[2 * idx + 1] += lazy[idx];
                lazy[2 * idx + 2] += lazy[idx];
            }

            lazy[idx] = 0;
        }

        if (low == high)
            return seg[idx];

        ll m = (low + high) / 2;

        if (i <= m)
            return query(2 * idx + 1, low, m, i);
        else
            return query(2 * idx + 2, m + 1, high, i);
    }

public:
    SegTree(int n)
    {
        size = n;
    }

    void update(ll l, ll r, ll val)
    {
        updateHelper(0, 0, size, l, r, val);
    }

    ll value(ll i)
    {
        return query(0, 0, size, i);
    }
};

int main()
{
    // #ifndef IO_FROM_FILE
    //     freopen("C:\\Users\\Dhruv\\OneDrive\\Documents\\CPP + DSA\\input.txt", "r", stdin);
    //     freopen("C:\\Users\\Dhruv\\OneDrive\\Documents\\CPP + DSA\\output.txt", "w", stdout);
    // #endif

    ll n, m;
    cin >> n >> m;
    SegTree st(n);

    ll t, a, b, c;
    while (m--)
    {
        cin >> t;
        if (t == 1)
        {
            cin >> a >> b >> c;
            st.update(a, b - 1, c);
        }
        else
        {
            cin >> a;
            cout << st.value(a) << endl;
        }
    }

    return 0;
}