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
    for (auto x : v)
        cout << x << " ";
    cout << "}\n";
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

bool isValidTopo(int V, vector<vector<int>> &adj, vector<int> &indeg)
{
    queue<int> qt;
    vector<int> ans;

    for (int i = 1; i <= V; i++)
    {
        if (indeg[i] == 0)
            qt.push(i);
    }

    while (!qt.empty())
    {
        int f = qt.front();
        qt.pop();
        ans.push_back(f);

        for (auto i : adj[f])
        {
            if (--indeg[i] == 0)
                qt.push(i);
        }
    }

    return ans.size() == V;
}

void __main__()
{
    int t;
    cin >> t;
    unordered_map<int, unordered_map<int, bool>> isEdgePresent;

    while (t--)
    {
        isEdgePresent.clear();

        ll n, k, i, j, x, last;
        cin >> n >> k;

        vector<vector<int>> adj(n + 1);
        vector<int> inDeg(n + 1, 0);

        // Any 2 orders will give me a order of all n people
        // construct graph
        // ans = valid toposort
        f(i, 0, k)
        {
            // first is invalid
            // 2 to 3 will be the first edge
            if (n == 1)
                cin >> x;
            else
                cin >> x >> last;
            f(j, 2, n)
            {
                cin >> x;
                if (!isEdgePresent[last][x])
                {
                    isEdgePresent[last][x] = 1;
                    adj[last].push_back(x);

                    inDeg[x]++;
                }

                last = x;
            }
        }

        if (isValidTopo(n, adj, inDeg))
            yes();
        else
            no();
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