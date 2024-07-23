#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define max 10001

// precomputing large amount of primes
int isPrime[max], cnt[max];

// O(NloglogN)
void sieveOfEratosthenes()
{
    memset(isPrime, 1, sizeof(isPrime));

    isPrime[0] = isPrime[1] = 0;
    int currentPrime = 2;

    // yaha bhi same logic rootN ke baad check krne ki koi sence nahi haii
    while (currentPrime * currentPrime < max)
    {
        if (isPrime[currentPrime])
        {
            // we can start from i*i insead of 2i as they will be marked befor by previous numbers
            // say i = 5
            // 10 marked by 2
            // 15 marked by 3
            // 20 marked by 2

            // thus we have to start from i*i
            for (int j = currentPrime * currentPrime; j < max; j += currentPrime)
            {
                isPrime[j] = 0;
            }
        }

        currentPrime++;
    }

    for (int i = 2; i < max; i++)
        if(isPrime[i])
            cout << i << ",";
}

// to compute count of primes till any number
void sieveOfEratosthenesCount()
{
    memset(isPrime, 1, sizeof(isPrime));
    memset(cnt, 0, sizeof(cnt));

    isPrime[0] = isPrime[1] = 0;

    // yaha bhi same logic rootN ke baad check krne ki koi sence nahi haii
    for (int i = 2; i < max; i++)
    {
        if (isPrime[i])
        {
            cnt[i] = cnt[i - 1] + 1;

            // we can start from i*i insead of 2i as they will be marked befor by previous numbers
            // say i = 5
            // 10 marked by 2
            // 15 marked by 3
            // 20 marked by 2

            // thus we have to start from i*i
            for (int j = i * i; j < max; j += i)
            {
                isPrime[j] = 0;
            }
        }
        else
            cnt[i] = cnt[i - 1];
    }
}

int32_t main()
{
    sieveOfEratosthenes();
     // sieveOfEratosthenesCount();
    // cout << cnt[1000] << endl;

    return 0;
}