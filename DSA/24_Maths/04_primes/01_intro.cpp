#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define max 100000001

// O(sqrt(N))
bool isPrimeNumber(int n)
{
    // maximum divisor of a number can be rootN
    for (int i = 2; i < sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}

// O(sqrt(N))
vector<int> allDivisors(int n)
{
    // lasrgest divisor can be rootN
    // if K is a divisor then n/k is also a divisor

    vector<int> ans;

    for (int i = 1; i < sqrt(n); i++)
    {
        if (n % i == 0)
        {
            ans.push_back(i);
            ans.push_back(n / i);
        }
    }
}

int32_t main()
{

    return 0;
}