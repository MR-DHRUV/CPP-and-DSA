#include <bits/stdc++.h>
using namespace std;

// complexity of log2b
long long binExpo(long long a, long long b)
{
    long long res = 1;

    while (b > 0)
    {
        if (b & 1)
            res *= a;

        a *= a;
        b >>= 1;
    }

    return res;
}

int main()
{
    // we have to find a^b in optimal time
    // say we have to find 2^10
    // writing exponent in binary -> 1010
    // a = 2, b = 1010 (binary me), res = 1

    // if last bit of b is set we will multiply res with a
    // and in every iteration we right shift b and a = a*a

    // how it works
    // a b res
    // 002 1010 1
    // 004 0101 4
    // 016 0010 4
    // 256 0001 4*254 = 1024

    // we are expresing exponent in binary to calculate power 
    // to calc 2^8 we dont have to multiply 2 8 times, we can calculate 2^4 and multiply it 2 times like this ... 
    
    // this works in O(log2B)

    cout<<binExpo(5,13)<<endl;

    return 0;
}