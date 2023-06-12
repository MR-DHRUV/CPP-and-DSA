#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool solve(int i, int j, string &s, string &p, vector<vector<int>> &dp)
    {
        if (i < 0 && j < 0)
            return true;

        if (i >= 0 && j < 0)
            return false;

        if (i < 0 && j >= 0)
        {
            while (j >= 0)
            {
                if (p[j--] == '*')
                {
                    j--; // previous character o baar include krlia h
                }
                else
                {
                    return false;
                }
            }

            return true;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        // match case
        if (s[i] == p[j] || p[j] == '.')
            return dp[i][j] = solve(i - 1, j - 1, s, p, dp);

        else if (p[j] == '*')
        {
            // either we can have preceeding character or null
            bool exclude = solve(i, j - 1, s, p, dp) || solve(i, j - 2, s, p, dp);
            // -2 as we have used 0 no of precedding character i.e we have ignored the previos character

            if (exclude)
                return dp[i][j] = exclude;

            return dp[i][j] = (s[i] == p[j - 1] || p[j - 1] == '.') ? solve(i - 1, j, s, p, dp) : false;

            // summerize in 1 line
        }

        return dp[i][j] = false;
    }

public:
    bool isMatch(string s, string p)
    {
        // * -> any number of previous character
        // . -> any single character
        vector<vector<int>> dp(s.length() + 1, vector<int>(p.length() + 1, -1));
        return solve(s.length() - 1, p.length() - 1, s, p, dp);
    }
};

int main()
{

    return 0;
}