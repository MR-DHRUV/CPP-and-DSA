// #pragma GCC target("avx,avx2,fma")
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

// To efficiently resolve subtree quesries we use a method called as euler tour
// This helps us in building segment tree's for tress :)
// and hence, we can efficently resolve any query in just logN time instead of N

// Euler tour is just a simple DFS in which we store start and end time of every node, this helps us in determing the sub tree of every node

/*
        1
      2   3
    4  5 6  7

    Node : 1  2  3  4  5  6  7
    Start: 01 02 08 03 05 09 11
    End  : 14 07 13 04 06 10 12

    Order: 1 2 4 4 5 5 2 3 6 6 7 7 3 1
    one for start and one for end

    Subtree of node 3 is fro, index 8 to 13 i.e 3 6 6 7 7 3
    ans hence we can use this data to build segment trees

    A more optimal approach is to just do a simple dFS and store size of subtree of each node
*/

/*
    Question:
    You are given a rooted tree consisting of n nodes. The nodes are numbered 1,2,..,n, and node 1 is the root. Each node has a value.

    Your task is to process following types of queries:
        change the value of node s to x
        calculate the sum of values in the subtree of node s

*/

ll subtreeSize[200001], start[200001], values[200001];
vector<ll> order;

/**
 * @brief Segment Tree for tree sum
 * @details The tree is being build from order array which contains the dfs traversal of the tree, when we are querying, the start[i] provides the index of node i in the order array and hence to relsolve the query for any node, we simple use start[i] as left and start[i] + subtreeSize[i] - 1 as right index, to locate the last node in that pirticular subtree. 
 */
class SegTree
{
public:
    ll seg[800001]{}, N;

    SegTree(int n) : N(n)
    {
        buildHelper(0, N - 1, 0);
    }

    inline int Compare(ll &a, ll &b)
    {
        return a + b;
    }

    void buildHelper(int s, int e, int idx)
    {
        if (s == e)
        {
            seg[idx] = values[order[s]];
            // cout << "build: " << s << " " << e << " " << idx << " " << seg[idx] << endl;
            return;
        }

        int mid = s + (e - s) / 2;
        buildHelper(s, mid, (2 * idx) + 1);
        buildHelper(mid + 1, e, (2 * idx) + 2);

        seg[idx] = Compare(seg[(2 * idx) + 1], seg[(2 * idx) + 2]);
        // cout << "build: " << s << " " << e << " " << idx << " " << seg[idx] << endl;
    }

    ll queryHelper(int idx, int s, int e, int l, int r)
    {
        if (r < s || l > e)
            return 0;

        if (s >= l && e <= r)
        {
            // cout << "Query: " << idx << " " << seg[idx] << endl;
            return seg[idx];
        }

        int mid = s + (e - s) / 2;
        ll left = queryHelper((idx * 2) + 1, s, mid, l, r);
        ll right = queryHelper((idx * 2) + 2, mid + 1, e, l, r);

        return Compare(left, right);
    }

    void updateHelper(int s, int e, int idx, int &target, int &val)
    {
        if (target < s || target > e)
            return;

        if (s == e)
        {
            seg[idx] = val;
            return;
        }

        int mid = s + (e - s) / 2;
        if (target <= mid)
            updateHelper(s, mid, (2 * idx) + 1, target, val);
        else
            updateHelper(mid + 1, e, (2 * idx) + 2, target, val);

        seg[idx] = Compare(seg[(2 * idx) + 1], seg[(2 * idx) + 2]);
    }

    void update(int target, int &val)
    {
        updateHelper(0, N - 1, 0, target, val);
    }

    ll query(int l, int r)
    {
        return queryHelper(0, 0, N - 1, l, r);
    }
};

// DFS
int dfs(int node, int p, int &t, vector<vector<int>> &adj)
{
    subtreeSize[node]++;
    start[node] = t++;
    order.push_back(node);

    for (auto &nbr : adj[node])
    {
        if (nbr == p)
            continue;
        subtreeSize[node] += dfs(nbr, node, t, adj);
    }

    return subtreeSize[node];
}

void __main__()
{
    int N, Q, u, v, a, b, c;
    cin >> N >> Q;

    vector<vector<int>> adj(N + 1);
    memset(subtreeSize, 0, sizeof(subtreeSize));
    int timer = 0;

    for (int i = 1; i <= N; i++)
        cin >> values[i];

    for (int i = 1; i < N; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 1. DFS
    dfs(1, -1, timer, adj);

    // 2. Building Tree
    SegTree st(N);

    // 3. Serve queries
    while (Q--)
    {
        cin >> a;
        if (a == 1)
        {
            cin >> b >> c;
            values[b] = c;
            st.update(start[b], c);
        }
        else
        {
            cin >> b;
            cout << st.query(start[b], start[b] + subtreeSize[b] - 1) << endl;
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