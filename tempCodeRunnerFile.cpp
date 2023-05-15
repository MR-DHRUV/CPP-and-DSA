#include <bits/stdc++.h>
using namespace std;

class Solution
{
    string solve(int s, int e, string &str, vector<vector<string>> &dp)
    {
        if (s > e)
            return "";

        if (s == e)
            return {str[s]};

        if (dp[s][e] != "-1")
            return dp[s][e];

        // chek if we can include or not
        if (str[s] == str[e])
        {
            return dp[s][e] = (str[s] + solve(s + 1, e - 1, str, dp) + str[e]);
        }

        string ans1 = solve(s + 1, e, str, dp);
        string ans2 = solve(s, e - 1, str, dp);

        return ans1.length() > ans2.length() ? dp[s][e] = ans1 : dp[s][e] = ans2;
    }

public:
    string longestPalindrome(string s)
    {
        vector<vector<string>> dp(s.length() + 1, vector<string>(s.length() + 1, "-1"));
        return solve(0, s.length() - 1, s, dp);
    }
};

int main()
{

    return 0;
}