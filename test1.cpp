#include <bits/stdc++.h>
using namespace std;

#define int long long int

const int mod = 1e9 + 7;

inline int mulm(int a, int b)
{
    return (a * b) % mod;
}

int powr(int a, int b)
{
    int res = 1;

    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % mod;

        a = (a * a) % mod;
        b >>= 1;
    }

    return res;
}

inline int inv(int n)
{
    return powr(n, mod - 2);
}

inline int divm(int a, int b)
{
    return mulm(a, inv(b));
}

// n -> no of runs
// b balls left
// w wickets
vector<int> arr = {1, 2, 3, 4, 6};

int solve(int n, int x, int b, int w, bool strike, int b_over)
{
    // base case
    if (n <= 0)
        return x <= 0;

    if (b == 0 || w == 10)
        return 0;

    // out case
    int ans = 0;

    // virat should not out befor 100
    if (!strike)
    {
        ans = solve(n, x, b - 1, w + 1, (b_over % 6 == 5 ? !strike : strike), (b_over + 1) % 6);
    }

    for (auto &runs : arr)
    {
        bool new_strike = strike;

        // check for strike change
        if ((b_over % 6 == 5 && runs % 2 == 5) || (runs % 2 != 0))
            new_strike = !strike;

        int new_x = (strike) ? x - runs : x;

        ans = (ans + solve(n - runs, new_x, b - 1, w, new_strike, (b_over + 1) % 6)) % mod;
    }

    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, n, b, w, x;
    cin >> t;

    while (t--)
    {
        cin >> n >> b >> w >> x;

        // base case
        if ((100 - x) > n + 5 || (100 - x) > b * 6)
            cout << 0 << endl;
        else if (x == 100)
            cout << 1 << endl;
        else
        {
            // total probability
            int q = powr(6, n);
            int ob = 6 - (b % 6);

            if (ob == 6)
                ob = 0;

            // cout <<"ob "<< ob << endl;
            int p = solve(n, 100 - x, b, w, 1, ob);

            cout << (divm(p, q)) << endl;
        }
    }

    return 0;
}