//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// we have to find the count of numbers that will have exactly 3 divisors, less than or equal to a given no x
// when any no x will have 3 divisors

// 1 , x and root x

// thus we have to find the count of prime numbers whoose squares are less than or equal to a given number 'N'
// x^2 <= N
// x <= root(N)

// thus we have to find the count of prime numbers less than equal to x

// maximum no is 10^12
// so we have to evaluate primes till 10^6
class Solution
{
public:
    int max = 10000001;

    void sieve_of_erato(vector<long long> &isPrime, vector<long long> &noOfPrimes)
    {
        // 0 and 1 cannot contribute to ans, so we are concidering them as non prime
        isPrime[0] = 0;
        isPrime[1] = 0;

        // square of every number is non prime
        for (int i = 2; i <= sqrt(max); i++)
        {
            if (isPrime[i])
            {
                // to set all the multiples of a number as non prime
                for (int j = 2; j * i <= max; j++)
                {
                    // setting multiples false
                    isPrime[j * i] = 0;
                }
            }
        }

        int count = 0;

        // setting count of no of primes till a given number
        for (int i = 0; i <= max; i++)
        {
            // counting prime numbers
            if (isPrime[i])
            {
                count++;
            }

            noOfPrimes[i] = count;
        }
    }

    vector<int> threeDivisors(vector<long long> query, int q)
    {
        // initiallty all no are assumed to be prime
        vector<long long> isPrime(max, 1);
        // for storing count
        vector<long long> noOfPrimes(max, 0);

        sieve_of_erato(isPrime, noOfPrimes);

        vector<int> ans;

        for (int i = 0; i < q; i++)
        {
            ans.push_back(noOfPrimes[(int)sqrt(query[i])]);
        }

        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int q;
        cin >> q;
        vector<long long> query(q);
        for (int i = 0; i < q; i++)
        {
            cin >> query[i];
        }
        Solution ob;

        vector<int> ans = ob.threeDivisors(query, q);
        for (auto cnt : ans)
        {
            cout << cnt << endl;
        }
    }
    return 0;
}
// } Driver Code Ends