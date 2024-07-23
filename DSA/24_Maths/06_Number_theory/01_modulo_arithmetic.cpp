#include <bits/stdc++.h>
using namespace std;

const int mod = 13;

int addm(int a, int b)
{
    return (a + b) % mod;
}

int subtm(int a, int b)
{
    return ((a - b) % mod + mod) % mod;
}

int mulm(int a, int b)
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

// to calculate inverse under mod
int inv(int n)
{
    return powr(n, mod - 2);
}

int divm(int a, int b)
{
    // we need to find (a/b)%mod

    // Acc to fermats little thm
    // a^p = a mod p, if p is prime
    // a^p-1 = 1 mod p
    // a^p-2 = a-1 mod p

    // (a/b)%mod = (a mod p * b-1 mod p)
    // (a/b)%mod = (a mod p * b^mod-2 mod p)

    return mulm(a, inv(b));
}

int facm(int N)
{
    int res = 1;

    for (int i = 2; i <= N; i++)
        res = mulm(res, i);

    return res;
}

int nCrm(int n, int r)
{
    return mulm(mulm(facm(n), inv(facm(r))), inv(facm(n - r)));
}

int main()
{
    // cout << divm(56, 2);
    // cout << nCrm(5, 2);
    cout<<powr(3,256)<<endl;
    return 0;
}