#include <bits/stdc++.h>
#define ll long long int
using namespace std;


class BIT
{
    // to support range updates in O(logN) we need 2 arrays 
    ll *bit1, *bit2;
    int size;

public:
    BIT(int n) : size(n)
    {
        bit = new ll[n + 1]{0};
    }

    void update(int i, int val)
    {
        for (; i <= size; i += (i & (-i)))
        {
            bit[i] += val;
        }
    }

    ll sum(int i)
    {
        ll ans = 0;

        for (; i > 0; i -= (i & (-i)))
        {
            ans += bit[i];
        }

        return ans;
    }

    ll query(int l, int r)
    {
        return sum(r) - sum(l - 1);
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

    int n, q, t, l, r;
    cin >> n >> q;
    vector<ll> arr(n);
    BIT b(n + 1);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        b.update(i + 1, arr[i]);
    };

    while (q--)
    {
        cin >> t >> l >> r;

        if (t == 1)
        {
            // t1 query
            cout << b.query(l, r) << endl;
        }
        else
        {
            // calculate differnce from actual value so that we can update our BIT
            b.update(l,r-arr[l-1]);

            // update original array
            arr[l-1] = r;
        }
    }

    return 0;
}