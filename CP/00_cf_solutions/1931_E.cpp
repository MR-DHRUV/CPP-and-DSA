#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC optimize("O3")

#include <bits/stdc++.h>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define all(x) (x).begin(), (x).end()
#define el "\n"

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef pair<int, int> pii;
typedef gp_hash_table<ll, ll> HashTable;

void __main__()
{
    int t;
    cin >> t;
    ll arr[200001];

    while (t--)
    {
        ll n, m, totalDigits = 0, x, cnt;
        cin >> n >> m;
        // Anna should choose a number with the largest number of trailing zeros and remove them. Sasha should find a number with the largest number of trailing zeros and concatenate it with any other number with minimum number of trailing zeros

        // Since now we know the optimal play, we must know the number of trailing zeros in each
        // see 1'st trun will be of anna
        // so there will exist a number with no trailing zeros
        // so we just need to count no of zeros in alternate numbers sorted in decreasing order of zeros and we'll subtract it from total count of digits
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            cnt = 0;
            while (x > 0 && x % 10 == 0)
            {
                cnt++;
                x /= 10;
            }

            arr[i] = cnt;
            while (x > 0)
            {
                totalDigits++;
                x /= 10;
            }

            totalDigits += cnt;
        }

        sort(arr, arr + n, [](ll &a, ll &b)
             { return a > b; });

        for (int i = 0; i < n; i += 2)
            totalDigits -= arr[i];

        if (totalDigits - 1 >= m)
            cout << "Sasha" << el;
        else
            cout << "Anna" << el;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    __main__();

    return 0;
}