#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize('unroll-loops,O3')
#pragma GCC optimize('O3')

#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define pb push_back
#define ppb pop_back
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

void print(vector<ll> arr)
{
    for (auto &i : arr)
        cout << i << " ";
    cout << endl;
}

void print(vector<vector<int>> arr)
{
    for (auto &j : arr)
    {
        for (int &i : j)
            cout << i << " ";
        cout << endl;
    }
}

unordered_map < ll, unordered_map < ll, unordered_map < ll, unordered_map<ll,ll> >>> mp[4];

ll solve(int curr, int a, int b, int c, int d)
{
    // saare lag gaye
    int min_p = min(a, min(b, min(c, d)));
    if (min_p <= 0)
        return min_p == 0;
    
    if(mp[curr].count(a) && mp[curr][a].count(b) && mp[curr][a][b].count(c) && mp[curr][a][b][c].count(d))
        return mp[curr][a][b][c][d];

    if (curr == 0)
        return mp[curr][a][b][c][d] = (solve(1, a, b - 1, c, d) + solve(2, a, b, c - 1, d)) % MOD1;
    else if (curr == 1)
        return mp[curr][a][b][c][d] = (solve(0, a-1, b, c, d) + solve(3, a, b, c , d-1)) % MOD1;
    else if (curr == 2)
        return mp[curr][a][b][c][d] = (solve(1, a, b - 1, c, d) + solve(2, a, b, c-1, d)) % MOD1;
    else
        return mp[curr][a][b][c][d] = (solve(0, a - 1, b, c, d) + solve(3, a, b, c, d-1)) % MOD1;
}

void __main__()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        ll ans = (((solve(0, a-1, b, c, d) + solve(1, a, b-1, c, d)) % MOD1 + solve(2, a, b, c-1, d)) % MOD1 + solve(3, a, b, c, d-1))%MOD1;
        cout << ans << el;
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