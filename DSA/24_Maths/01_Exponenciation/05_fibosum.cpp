#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
using mat = vector<vector<ll>>;
const int mod = 1000000007;

mat multiply(mat &a, mat &b)
{
    mat res(a.size(), vector<ll>(a.size(), 0));

    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a.size(); j++)
        {
            for (int k = 0; k < a.size(); k++)
            {
                res[i][j] = (res[i][j] + (a[i][k] * b[k][j])) % mod;
            }
        }
    }

    return res;
}

mat matExpo(mat a, int b)
{
    // make identity matrix
    mat res(a.size(), vector<ll>(a.size(), 0));
    for (int i = 0; i < a.size(); i++)
    {
        res[i][i] = 1;
    }

    while (b > 0)
    {
        if (b & 1)
            res = multiply(res, a);

        a = multiply(a, a);
        b >>= 1;
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);

    // we will use matrix exponenciation to calculate fibo sum

    // Concider the below property of fibbonacchi numbers
    // Fn = Fn-1 + Fn-2

    // Fn-2 = Fn - Fn-1
    // Fn-3 = Fn-1 - Fn-2
    // Fn-4 = Fn-2 - Fn-3
    // .
    // .
    // .
    // F0 = F2 - F1

    // -------------------------- sum lhs and rhs
    // F0 + F1 + .... + Fn-2 = Fn-F1
    // F0 + F1 + .... + Fn = Fn+2 - F1

    // S(n) = Fn+2 - F1 = Fn+2 -1

    ll n, e, s;
    cin >> n;

    while (n--)
    {
        cin >> s >> e;

        mat fib = {{1, 1}, {1, 0}};
        mat e_sum = matExpo(fib, e + 1);
        mat s_sum = matExpo(fib, s);

        cout << (e_sum[0][0] - s_sum[0][0] + mod) % mod << endl;
    }

    return 0;
}

// we can also have a second approach where we can use a 3*3 matrix
/*
    t * fn = fn+1

    fn = Sn
         Fn
         Fn+1

    fn+1 = Sn+1
           Fn+1
           Fn

    Sn+1 = Sn + Fn+1
    Fn+1 = Fn + Fn-1
    Fn = Fn-1 + Fn-2

    we can equate to get a 3*3 matrix t which we will exponenciate to calculate the sum
*/