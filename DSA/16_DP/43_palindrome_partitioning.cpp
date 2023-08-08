#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int i, int j, string &str)
{
    while (i < j)
    {
        if (str[i++] != str[j--])
            return false;
    }

    return true;
}

int solve(int s, string &str, vector<int> &dp)
{
    if (s >= str.length())
        return 0;

    if (dp[s] != -1)
        return dp[s];

    int ans = 1e9 + 7;

    // create partitions
    for (int part = s; part < str.length(); part++)
    {
        if (isPalindrome(s, part, str))
        {
            ans = min(ans, (1 + solve(part + 1, str, dp)));
        }
    }

    return dp[s] = ans;
}

// O(n3)
int solveTab(string &str)
{
    vector<int> dp(str.length() + 1, 0);

    for (int s = str.length() - 1; s >= 0; s--)
    {
        dp[s] = 1e9 + 7;

        for (int part = s; part < str.length(); part++)
        {
            if (isPalindrome(s, part, str))
            {
                dp[s] = min(dp[s], 1 + dp[part + 1]);
            }
        }
    }

    return dp[0] - 1;
}

// O(n2)
int solveTabFast(string str)
{

    int dp[2001] = {0};
    bool isPalindrome[2001][2001] = {0};

    // marking all palindromic substrings using diagonal traversal stratagy
    for (int gap = 0; gap < str.length(); gap++)
    {
        for (int i = 0, j = i + gap; i < str.length() && j < str.length(); i++, j++)
        {
            if (gap < 2)
            {
                if (str[i] == str[j])
                    isPalindrome[i][j] = true;
            }
            else
            {
                if (str[i] == str[j] && isPalindrome[i + 1][j - 1])
                    isPalindrome[i][j] = true;
            }
        }
    }

    for (int s = str.length() - 1; s >= 0; s--)
    {
        dp[s] = 1e9 + 7;

        for (int part = s; part < str.length(); part++)
        {
            if (isPalindrome[s][part])
                dp[s] = min(dp[s], 1 + dp[part + 1]);
        }
    }

    return dp[0] - 1;
}

int palindromePartitioning(string str)
{
    // Write your code here
    // max partitions = str.length()
    vector<int> dp(str.length() + 1, -1);

    return solve(0, str, dp) - 1;
}

int main()
{

    return 0;
}