#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC optimize("O3")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define MOD 1000000007
// #define MOD 998244353
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
void print(vector<T> &v)
{
    cout << "{";
    for (auto &x : v)
        cout << x << " ";
    cout << "}\n";
}

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

/*
Little Elephant and his friends are going to a party. Each person has his own collection of T-Shirts. There are 100 different kind of T-Shirts. Each T-Shirt has a unique id between 1 and 100. No person has two T-Shirts of the same ID.

They want to know how many arrangements are there in which no two persons wear same T-Shirt. One arrangement is considered different from another arrangement if there is at least one person wearing a different kind of T-Shirt in another arrangement.

1 ≤ No of persons ≤ 10
*/

/*
    Brute fore try all the combinations
    super super reccursive solution

    How to apply dp to this reccursion

    total->100 tshirts
    N -> 10

    so the main way to track the 100 tshirts in to create a int having 100 bits
    so that we can have states like i,mask
    but that is crazy and impossible

    also its complexity is 2^100 * n, which is really poor

    Intuition:
    We have 100 tshirts and a tshirt can belong to multiple people or 1 or 0
    a t shirt will either be won by exactly 1 or 0 people
    so idea is to reverse the dp
    we will mask people ans iterate over tshirts
    dp -> i , mask -> 100 * 2^10
*/

long long dp[101][(1 << 10)];

long long rec(int i, int mask, int &n, vector<vector<int>> &t)
{
    // everyone is assigned a tshirt
    if (mask == 0)
        return 1ll;

    if (i >= 101)
        return 0ll;

    if (dp[i][mask] != -1)
        return dp[i][mask];

    long long ans = rec(i + 1, mask, n, t);

    for (int j = 0; j < t[i].size(); j++)
    {
        // if this person is not assigned any tshirt
        if ((mask >> t[i][j]) & 1)
            ans = (ans + rec(i + 1, mask ^ (1 << t[i][j]), n, t)) % MOD;
    }

    return dp[i][mask] = ans;
}

void __main__()
{
    int t, n;
    cin >> t;
    string tees, temp;

    while (t--)
    {
        vector<vector<int>> t(101);
        memset(dp, -1, sizeof(dp));
        cin >> n;
        getchar();

        for (int i = 0; i < n; i++)
        {
            getline(cin, tees);
            stringstream ss(tees);

            while (ss >> temp)
            {
                t[stoi(temp)].push_back(i);
            }
        }

        cout << rec(1, (1 << n) - 1, n, t) << endl;
    }
}

int main()
{
    // ios_base::sync_with_stdio(false);
    __main__();

    return 0;
}