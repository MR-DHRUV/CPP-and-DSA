#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // Memoization : Memory limit exceeded
    string minStr(string s1, string s2)
    {
        if (s1.length() <= s2.length())
            return s1;

        return s2;
    }

    string solve(int i, int j, string &str1, string &str2, vector<vector<string>> &dp)
    {
        // if any one string is exhausted then we have to add the second string as complete
        if (i >= str1.length() || j >= str2.length())
        {
            if (i < 0 && j < 0)
                return "";
            else if (i >= str1.length())
                return str2.substr(j);
            else
                return str1.substr(i);
        }

        if (dp[i][j] != "#")
            return dp[i][j];

        if (str1[i] == str2[j])
        {
            return dp[i][j] = str1[i] + solve(i + 1, j + 1, str1, str2, dp);
        }

        // include s1
        string s1 = str1[i] + solve(i + 1, j, str1, str2, dp);
        // include s2
        string s2 = str2[j] + solve(i, j + 1, str1, str2, dp);

        return dp[i][j] = minStr(s1, s2);
    }

    string solveTab(string &str1, string &str2)
    {
        vector<vector<int>> dp(str1.length() + 2, vector<int>(str2.length() + 2, 0));

        // for reverse eng questions always use 1 based indexing
        for (int i = 1; i <= str1.length(); i++)
        {
            for (int j = 1; j <= str2.length(); j++)
            {
                if (str1[i - 1] == str2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    // no match: I have 2 options either i will move i or j
                    dp[i][j] = dp[i - 1][j];
                    dp[i][j] = max(dp[i][j], dp[i][j - 1]);
                }
            }
        }

        // simmilar to reverse engineering seen in printing lcs
        /*
            "abcde" "bdgek"

              b d g e k
            a 3 2 1 1 0
            b 3 2 1 1 0
            c 2 2 1 1 0
            d 2 2 1 1 0
            e 1 1 1 1 0

            here we can see that dp[0][0] is from dp[1][0] so the character a is not matching as we have moved in columnn so a must be present in the super sequence

            No on moving to dp[1][0] we can see that s1[1] == s2[0] so we'll include it only once and incriment both i and j and so on we will build the supersequence

            This illutration of of top-down but the code is of bottom-up
        */

        // This pattern is like finding a path by brute force and then lazer guiding a missile to achieve success

        string ans;
        int j = str2.length(), i = str1.length();

        while (i > 0 && j > 0)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                ans.push_back(str1[i - 1]);
                i--;
                j--;
            }
            else
            {
                // moving to greater position
                if (dp[i - 1][j] > dp[i][j - 1])
                {
                    // now i is left behiend so we have to add it in string
                    ans.push_back(str1[i - 1]);
                    i--;
                }
                else
                {
                    ans.push_back(str2[j - 1]);
                    j--;
                }
            }
        }

        // if any string is left
        while (i > 0)
        {
            ans.push_back(str1[i - 1]);
            i--;
        }
        while (j > 0)
        {
            ans.push_back(str2[j - 1]);
            j--;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }

public:
    string
    shortestCommonSupersequence(string str1, string str2)
    {
        vector<vector<string>> dp(str1.length() + 1, vector<string>(str2.length() + 1, "#"));
        return solve(0, 0, str1, str2, dp);
    }
};

int main()
{

    return 0;
}