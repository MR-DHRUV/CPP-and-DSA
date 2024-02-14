#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll ncr(ll n, ll r)
{
    if (n < r)
        return 0;

    long double ans = 1;

    for (ll i = r; i > 0; i--)
        ans = (ans * (n--)) / i;

    return ll(ans);
}

int main()
{

    cout << ncr(5, 2) << endl;

    return 0;
}