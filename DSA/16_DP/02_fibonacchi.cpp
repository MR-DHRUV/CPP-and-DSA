#include <bits/stdc++.h>
using namespace std;

// standard reccursive solution
// complexity : 2^n
int fib(int n)
{
    if (n <= 1)
        return n;

    return fib(n - 1) + fib(n - 2);
}

// in this solution we are evaluting many terms again and again, thus if we remember the past we will not repeat that calculation
// this problem is of type overlapping subproblems

// When this technique is to be applied
// 1 when optimal solution of a problem can be evaluted using its subproblems
// 2 overlapping subproblems

// using memoization
// Complexity : linear (O(n))
long long fibMemo(long long n, vector<long long> &dp)
{
    // yaad krwa dia
    if (dp[n] != -1)
        return dp[n];

    return dp[n] = fibMemo(n - 1, dp) + fibMemo(n - 2, dp);
}

// using tabulation + space optimization
long long fibTab(long long n)
{
    // base case
    if (n <= 1)
        return n;

    long long p1 = 0;
    long long p2 = 1;

    // here we dont need dp array as we need to rememeber only last two values

    for (int i = 2; i <= n; i++)
    {
        long long nxt = p1 + p2;
        p1 = p2;
        p2 = nxt;
    }

    return p2;
}

int main()
{
    vector<long long> dp(5001, -1);
    dp[0] = 0;
    dp[1] = 1;
    cout << fibMemo(5000, dp) << endl;
    cout << fibTab(5000) << endl;

    return 0;
}