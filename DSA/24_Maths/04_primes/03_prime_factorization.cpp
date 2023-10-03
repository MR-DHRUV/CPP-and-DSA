#include <bits/stdc++.h>
using namespace std;
#define int long long int

// O(N)
vector<int> primeFactorization(int n)
{
    // is a number is prime itself, the worst case is O(N)
    vector<int> ans;

    // we dont have to check if i is prime or not, as if a num is divisible by 2, then we have divided it by 2 till we can so, all factors that have 2 are removed any we will be left with prime factors only
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            ans.push_back(i);

            while (n % i == 0)
            {
                n /= i;
            }
        }
    }

    return ans;
}

// O(sqrt(N))
vector<int> primeFactorizationFast(int n)
{
    vector<int> ans;

    // We cannot have a prime factor greater than rootN
    for (int i = 2; i < sqrt(n); i++)
    {
        if (n % i == 0)
        {
            ans.push_back(i);

            while (n % i == 0)
            {
                n /= i;
            }
        }
    }

    // After rootN, iterations n would be either 1 or a prime number
    // Eg: 11, rootN = 3. = 3
    // 11%2 != 0
    // 11%3 != 0
    // Exit loop
    // n = 11, prime add it to ans

    if (n > 1)
        ans.push_back(n);

    return ans;
}

// when you have a lot of queries to get prime factorization 
// Precompute a prime array using sieve and maintain another array which will contain the smallest prime factor of anyy number 

// Now to get prime factor of any number n, we start from smallestPrime[n] and divide it with that number, now say we are left with k so we divide with smallestPrime[k] and so on.... 
// For each number it will take O(logN) time

int32_t main()
{
    auto ans = primeFactorizationFast(99);
    for (auto &i : ans)
        cout << i << " ";

    return 0;
}