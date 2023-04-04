#include <bits/stdc++.h>
using namespace std;

void printArr(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

long long int mod = 1e9 + 7;

int solve(int n, int k, vector<int> &dp)
{
    if (n <= 0)
        return 0;

    if (n == 1)
        return k;

    if (dp[n] != -1)
        return dp[n];

    // ya toh next wale ko k se paint krunga ya current wale se
    return dp[n] = (k * (solve(n - 1, k, dp) + solve(n - 2, k, dp)-1)) % mod;
}

int numberOfWays(int n, int k)
{
    // Write your code here.
    // max 2 ka color same ho skta haii

    vector<int> dp(n + 1, -1);
    return solve(n, k, dp);
}

int main()
{

    return 0;
}