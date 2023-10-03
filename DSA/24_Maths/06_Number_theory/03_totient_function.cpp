#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define N 100000

void totient()
{
    vector<int> isPrime(N + 1, 1);
    vector<int> t(N + 1, 1);

    // fills array with incresing values, 1 2 3 4 ...
    // iota(t.begin(),t.end(),0);

    for (int i = 2; i <= N; i++)
    {
        if (isPrime[i])
        {
            t[i] = i - 1;

            for (int j = i+i; j <= N; j += i)
            {
                isPrime[j] = 0; // non prime
                t[j] *= t[i];
            }
        }
    }

    for (int i = 0; i <= 100; i++)
    {
        cout << i << " " << t[i] << endl;
    }
}

int32_t main()
{
    // totient function returns the no of integers that are co-prime to a given number
    // t(n) = n-1  // for prime number
    // else t(n) = t(p1) * t(p2) * ...
    // where p1, p2 .. pn are distinct primes in factorization of n

    // find number of integers x such that gcd(x,n) = g
    // gcd(x,n) = g

    // gcd(x/g,n/g) = 1
    // if n does not divide g then 0
    totient();

    return 0;
}