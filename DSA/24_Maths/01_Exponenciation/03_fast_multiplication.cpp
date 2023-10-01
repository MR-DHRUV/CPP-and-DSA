#include <bits/stdc++.h>
using namespace std;

// O(log2b)
long long binMul(long long a, long long b, long long mod)
{
    long long res = 0;

    while (b > 0)
    {
        if (b & 1)
            res = (res + a) % mod;

        a = (a + a) % mod;
        b >>= 1;
    }

    return res;
}

int main()
{
    // say I have to multiply large numbers of range a,b,c <= 10^15
    // (a*b)%c nikalna haii
    // if I directly multiply, even unsigned ll can't store it

    // brute force
    // while(b--) a = (a+a)%c;

    // Now here comes fast multiplication which can be called as binary multiplication
    cout << binMul(220000112, 739292, 1e9 + 7);

    return 0;
}