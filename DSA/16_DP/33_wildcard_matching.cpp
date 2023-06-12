#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool solve(int i, int j, string &s, string &p, vector<vector<int>> &dp)
    {
        // ans case
        if (i < 0 && j < 0)
            return true;

        // base case 1: pattern is exhausted but string is remaining
        if (i >= 0 && j < 0)
            return false;

        // base case 2: pattern is remaining but string is exhausted
        if (i < 0 && j >= 0)
        {
            /*
                This case is to handle patterns of the form
                s :  bac
                p:  *bac

                ans is true as * can be replaced by a null string
            */

            while (j >= 0)
            {
                if (p[j--] != '*')
                    return false;
            }

            return true;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        // match case
        // 1: s[i] == p[j]
        // 2: p[j] == ?
        if (s[i] == p[j] || p[j] == '?')
            return dp[i][j] = solve(i - 1, j - 1, s, p, dp);

        // * case
        else if (p[j] == '*')
        {
            // we can either replace * with a null string or a sequence of characaters
            return dp[i][j] = (solve(i, j - 1, s, p, dp) || solve(i - 1, j, s, p, dp));

            // in second case, we'havent moved j so that we can reccursively construct sequential characters from *
        }

        // unmatch case
        return false;
    }

    bool solveTab(string &s, string &p)
    {
        vector<vector<int>> dp(s.length() + 1, vector<int>(p.length() + 1, 0));

        // base cases
        dp[0][0] = true;

        for (int i = -1; i < s.length(); i++)
        {
            for (int j = -1; j < p.length(); j++)
            {
                if (i < 0 && j >= 0)
                {
                    dp[i + 1][j + 1] = true;

                    while (j >= 0)
                    {
                        if (p[j--] != '*')
                        {
                            dp[i + 1][j + 1] = false;
                            break;
                        }
                    }
                }
                else if ((i >= 0 && j >= 0) && (s[i] == p[j] || p[j] == '?'))
                    dp[i + 1][j + 1] = dp[i][j];

                else if ((i >= 0 && j >= 0) && (p[j] == '*'))
                    dp[i + 1][j + 1] = (dp[i + 1][j] || dp[i][j + 1]);
            }
        }

        return dp[1][1];
    }

public:
    bool isMatch(string s, string p)
    {
        // * -> any sequence of characters
        // ? -> any single character
        vector<vector<int>> dp(s.length(), vector<int>(p.length(), -1));
        return solve(s.length() - 1, p.length() - 1, s, p, dp);
    }
};

int main()
{
    return 0;
}