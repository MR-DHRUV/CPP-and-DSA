#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
using ll = long long;

ll solve(int s, int e, bool isTrue, string &exp, vector<vector<vector<int>>> &dp)
{
    if (s > e)
        return 0;

    // for a unit partition
    if (s == e)
    {
        if (exp[s] == 'T' && isTrue)
            return 1;

        else if (exp[s] == 'F' && !isTrue)
            return 1;

        return 0;
    }

    if (dp[s][e][isTrue] != -1)
        return dp[s][e][isTrue];

    ll ans = 0;

    // creating partitions
    for (int i = s + 1; i < e; i += 2)
    {
        ll leftTrue = solve(s, i - 1, 1, exp, dp);
        ll leftFalse = solve(s, i - 1, 0, exp, dp);

        ll rightTrue = solve(i + 1, e, 1, exp, dp);
        ll rightFalse = solve(i + 1, e, 0, exp, dp);

        if (exp[i] == '&')
        {
            if (isTrue)
                ans = (ans + (leftTrue * rightTrue % mod)) % mod;
            else
            {
                ans = (ans + (leftTrue * rightFalse % mod)) % mod;
                ans = (ans + (leftFalse * rightTrue % mod)) % mod;
                ans = (ans + (leftFalse * rightFalse % mod)) % mod;
            }
        }
        else if (exp[i] == '|')
        {
            if (isTrue)
            {
                ans = (ans + (leftTrue * rightTrue % mod)) % mod;
                ans = (ans + (leftTrue * rightFalse % mod)) % mod;
                ans = (ans + (leftFalse * rightTrue % mod)) % mod;
            }
            else
                ans = (ans + (leftFalse * rightFalse % mod)) % mod;
        }
        else
        {
            if (isTrue)
            {
                ans = (ans + (leftTrue * rightFalse % mod)) % mod;
                ans = (ans + (leftFalse * rightTrue % mod)) % mod;
            }
            else
            {
                ans = (ans + (leftFalse * rightFalse % mod)) % mod;
                ans = (ans + (leftTrue * rightTrue % mod)) % mod;
            }
        }
    }

    return dp[s][e][isTrue] = ans;
}

int solveTab(string &exp)
{
    int n = exp.length();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, 0)));

    for (int s = n - 1; s >= 0; s--)
    {
        for (int e = 0; e < n; e++)
        {
            if (s == e)
            {
                dp[s][e][0] = exp[s] == 'F';
                dp[s][e][1] = exp[s] == 'T';
            }
            else
            {
                // creating partitions
                for (int i = s + 1; i < e; i += 2)
                {
                    ll leftTrue = dp[s][i - 1][1];
                    ll leftFalse = dp[s][i - 1][0];

                    ll rightTrue = dp[i + 1][e][1];
                    ll rightFalse = dp[i + 1][e][0];

                    if (exp[i] == '&')
                    {
                        dp[s][e][1] = (dp[s][e][1] + (leftTrue * rightTrue % mod)) % mod;

                        dp[s][e][0] = (dp[s][e][0] + (leftTrue * rightFalse % mod)) % mod;
                        dp[s][e][0] = (dp[s][e][0] + (leftFalse * rightTrue % mod)) % mod;
                        dp[s][e][0] = (dp[s][e][0] + (leftFalse * rightFalse % mod)) % mod;
                    }
                    else if (exp[i] == '|')
                    {

                        dp[s][e][1] = (dp[s][e][1] + (leftTrue * rightTrue % mod)) % mod;
                        dp[s][e][1] = (dp[s][e][1] + (leftTrue * rightFalse % mod)) % mod;
                        dp[s][e][1] = (dp[s][e][1] + (leftFalse * rightTrue % mod)) % mod;

                        dp[s][e][0] = (dp[s][e][0] + (leftFalse * rightFalse % mod)) % mod;
                    }
                    else
                    {

                        dp[s][e][1] = (dp[s][e][1] + (leftTrue * rightFalse % mod)) % mod;
                        dp[s][e][1] = (dp[s][e][1] + (leftFalse * rightTrue % mod)) % mod;

                        dp[s][e][0] = (dp[s][e][0] + (leftFalse * rightFalse % mod)) % mod;
                        dp[s][e][0] = (dp[s][e][0] + (leftTrue * rightTrue % mod)) % mod;
                    }
                }
            }
        }
    }

    return dp[0][n - 1][1];
}

int evaluateExp(string &exp)
{
    // based on partition dp
    // we will be creating partitions around operators
    // for every partition we are trying to find the no of ways we can make it true or false
    // false as T | F = T, so we need false also

    vector<vector<vector<int>>> dp(exp.size() + 1, vector<vector<int>>(exp.size() + 1, vector<int>(2, -1)));
    return solve(0, exp.size() - 1, true, exp, dp);
}

int main()
{

    return 0;
}