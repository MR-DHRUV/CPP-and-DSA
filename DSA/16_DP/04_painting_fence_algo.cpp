#include<bits/stdc++.h>
using namespace std;

int mod = 1e9+7;

int solve(int n, int &k, vector<int> &dp)
{
    if (n == 1)
        return k;

    if(n == 2)
        return (k*k)%mod;    

    if (dp[n] != -1)
        return dp[n];

    // ya toh next wale ko k se paint krunga ya current wale se
    return dp[n] = ((k-1)*1ll*(solve(n-1,k,dp)%mod + solve(n-2,k,dp)%mod)%mod )%mod;
}

// find no of ways to paint n fences with k colors such that no more than 2 adjacent fences have same color
int numberOfWays(int n, int k)
{
    vector<int> dp(n + 1, -1);
    return solve(n, k, dp);
}

int main()
{
    
    return 0;
}