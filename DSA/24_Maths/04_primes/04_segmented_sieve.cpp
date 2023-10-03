#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define N 100001

int32_t main()
{
    // more optimised approach when we need to generate primes till 10^9 or even large
    // why we cant use standard sieve
    // standard sieve takes O(N) memory while the max limit if of 4*10^7 = 40MB
    // for N >= 10^9 we need 40*100 - 4GB memory

    // in the question we need to find primes between M and N and gap would be 10^6 at most

    // Algo
    // Using standard sieve calculate all primes upto sqrt(N)
    // so effectivly using this data we can mark further numbers

    // So max value of N is 10^9 and we'll precompute this primes array till sqrt N;
    // and will compute primes for each query [m,n]

    // this just optimizes memory complexity

    int isPrime[N + 1];
    memset(isPrime, 1, sizeof(isPrime));
    isPrime[0] = isPrime[1] = 0;

    vector<int> primes;

    for (int i = 2; i <= N; i++)
    {
        if (isPrime[i])
        {
            primes.push_back(i);
            for (int j = i * i; j < N; j += i)
            {
                isPrime[j] = 0;
            }
        }
    }

    int t, n, m;
    cin >> t;

    while (t--)
    {
        cin >> m >> n;

        // segmented sieve
        vector<int> seg(n - m + 2, 0);

        for (auto &p : primes)
        {
            if (p * p > n)
                break;

            int start = (m / p) * p;

            // if prime num is in range [m,n], then we must mark prime from 2*p
            if (p >= m && p <= n)
                start = 2 * p;

            // marking multiples of p as not prime
            for (int j = start; j <= n; j = j + p)
            {
                if (j < m)
                    continue;

                seg[j - m] = 1;
            }
        }

        for (int i = max(2ll, m); i <= n; i++)
        {
            if (seg[i - m] == 0)
                cout << i << endl;
        }

        cout << endl;
    }

    return 0;
}