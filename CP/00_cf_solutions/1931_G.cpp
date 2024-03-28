#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC optimize("O3")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

// #define MOD 1000000007
#define MOD 998244353
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
#define f(i, s, e) for (long long int i = s; i < e; i++)
#define ef(i, s, e) for (long long int i = s; i <= e; i++)
#define rf(i, e, s) for (long long int i = e - 1; i >= s; i--)

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef pair<int, int> pii;
typedef gp_hash_table<ll, ll> HashTable;

/* PRINTS */
template <class T>
void print(vector<T> v)
{
    cout << "{";
    for (auto &x : v)
        cout << x << " ";
    cout << "}\n";
}

template <class T>
void printMat(vector<vector<T>> &v)
{
    for (auto &x : v)
        print(x);
}

bool prime(ll a)
{
    if (a == 1)
        return 0;
    for (int i = 2; i <= round(sqrt(a)); ++i)
        if (a % i == 0)
            return 0;
    return 1;
}
void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }

ll addm(ll a, ll b) { return (a + b) % MOD; }
ll subtm(ll a, ll b) { return ((a - b) % MOD + MOD) % MOD; }
ll mulm(ll a, ll b) { return (a * b) % MOD; }

ll powr(ll a, ll b)
{
    ll res = 1;

    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % MOD;

        a = (a * a) % MOD;
        b >>= 1;
    }

    return res;
}

ll inv(ll n) { return powr(n, MOD - 2); }
ll divm(ll a, ll b) { return mulm(a, inv(b)); }

ll factorial[int(4e6 + 1)];
void _precompute_()
{
    factorial[0] = 1;
    for (ll i = 1; i <= 4e6; i++)
        factorial[i] = (i * factorial[i - 1]) % MOD;
}

ll nCr(ll n, ll r)
{
    return divm(divm(factorial[n], factorial[r]), factorial[n - r]);
}

void __main__()
{
    int t;
    cin >> t;
    _precompute_();

    while (t--)
    {
        // cout << t << el;
        // yes();
        ll c1, c2, c3, c4, res = 0;
        cin >> c1 >> c2 >> c3 >> c4;

        /*
            The main observation needed is to notice that 1 + 3 = 1 and 2 + 4 = 2, so we can condense all 3 and 4 pieces. However, it is possible to start the sequence with a 3 or 4 piece, so for this reason we can imagine having an "extra" 1 or 2, respectively. Now there are a few cases:

            No correct puzzle sequence can have consecutive 1's or 2's, so if |c1−c2|>1, the answer is 0.

            If c1=c2=0, the answer is 1 if c3 = 0 and/or c4=0 and 0 otherwise. This is true because 3 cannot mesh with 4.

            If c1=c2 and c1,c2>0 ,either 1 or 2 can be used to start the puzzle sequence, so we can fix the first number and calculate the rest of the sequence. Counting the # of ways to condense c3 3 pieces into c1+1 1 pieces is the same as counting the # of ways put c3 indistinguishable balls into c1+1 boxes, which is (c1+c3c1) (this can be visualized with the stars and bars technique). Note that 1 is added to c1 for that "extra" piece, if we fix 1 to be the first puzzle. As such, the answer is =(c1+c3−1Cc1−1)⋅(c2+c4Cc2)+(c1+c3Cc1)⋅(c2+c4−1Cc2−1)

            If c1=c2+1 or c1+1=c2, then we are required to fix either 1 or 2 to be the first piece, respectively. Then it's the same exact idea as the previous case
        */

        if (abs(c1 - c2) > 1)
            cout << 0 << el;
        else if (c1 + c2 == 0)
            cout << (c3 == 0 || c4 == 0 ? 1 : 0) << el;
        else
        {
            if (c1 <= c2)
                res = (nCr(c1 + c3, c3) * nCr(c2 + c4 - 1, c4)) % MOD;

            if (c2 <= c1)
                res = (res + ((nCr(c1 + c3 - 1, c3) * nCr(c2 + c4, c4)) % MOD)) % MOD;

            cout << res << el;
        }
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