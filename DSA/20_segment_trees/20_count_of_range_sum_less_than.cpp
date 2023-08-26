#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
class BIT
{
    ll *bit;
    ll size;

public:
    BIT(ll n) : size(n + 1)
    {
        bit = new ll[n + 2]{0ll};
    }

    void update(ll i, ll val)
    {
        ++i;
        for (; i <= size; i += (i & (-i)))
        {
            bit[i] += val;
        }
    }

    ll sum(ll i)
    {
        ++i;
        ll ans = 0;

        for (; i > 0; i -= (i & (-i)))
        {
            ans += bit[i];
        }

        return ans;
    }

    ll query(ll l, ll r)
    {
        return sum(r) - sum(l - 1);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, t;
    cin >> n >> t;

    vector<ll> prefix(n + 1, 0);

    BIT b(n + 3);

    for (int i = 1; i <= n; i++)
    {
        cin >> prefix[i];
        prefix[i] += prefix[i - 1];
    }

    // sum should be less than t
    // we need to find count of prefix sum that must me subtracted from current sum so that it lies in range

    vector<ll> sumToIdx(prefix.begin(), prefix.end());
    sort(sumToIdx.begin(), sumToIdx.end());

    ll ans = 0;

    for (int i = 0; i <= n; i++)
    {
        ll min = prefix[i] - t + 1;
        ll idx = lower_bound(sumToIdx.begin(), sumToIdx.end(), prefix[i]) - sumToIdx.begin();

        ll min_idx = lower_bound(sumToIdx.begin(), sumToIdx.end(), min) - sumToIdx.begin();
        ans += b.query(min_idx, sumToIdx.size() + 1);

        b.update(idx, 1);
    }

    cout << ans << endl;

    return 0;
}