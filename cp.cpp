#include <iostream>
#include <cmath>
#include <limits.h>
#define ll long long int
using namespace std;

signed main()
{
    // increases speed by prventing the overhead
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll *sq , *arr, blkSize;
    ll n, q, l, r;
    cin >> n;
    blkSize = (sqrtl(n) + 1);

    arr = new ll[n];
    sq = new ll[blkSize]{INT_MAX};

    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
        sq[i / blkSize] = min(sq[i / blkSize], arr[i]);
    }

    cin >> q;

    while (q--)
    {
        cin >> l >> r;
        ll ans = INT_MAX;

        for (ll i = l; i <= r;)
        {
            if (i % blkSize == 0 && i + blkSize - 1 <= r)
            {
                ans = min(ans, sq[i / blkSize]);
                i += blkSize;
            }
            else
            {
                ans = min(ans, arr[i++]);
            }
        }

        cout<<ans<<endl;
    }

    return 0;
}