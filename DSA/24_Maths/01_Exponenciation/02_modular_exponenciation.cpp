#include <bits/stdc++.h>
using namespace std;

int modExpo(long long a, long long b, int mod)
{
    // we are using long long to avoid overflow during multiplications
    long long res = 1;

    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % mod;

        a = (a * a) % mod;
        b >>= 1;
    }

    return res;
}

int main()
{
    // modular exponenciation is binary exponenciation under mod conditions
    // used to calculate large powers with some mod value

    return 0;
}