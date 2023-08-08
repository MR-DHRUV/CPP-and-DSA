#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countSubstrings(string str)
    {
        // format of a general palindrome
        // x(str)x

        // if str is palindrome then we can say that the string is palindrome
        // that is for palindrome the condition is s[i] == s[j] and isPalindrome(i+1,j-1) == true

        // To count all pallindromic substrings
        // we will create a 2D array where dp[i][j] represents whether string starting from i and ending at j is palindrome or not

        // Trivial cases : each string of lengh 1 and 2 can be judged in 0(1) time

        vector<vector<bool>> dp(str.length(), vector<bool>(str.length(), false));
        int ans = 0;

        // upper diagonal traversal in a 2-d array

        // gap : length of string in terms of index (o to n-1)
        for (int gap = 0; gap < str.length(); gap++)
        {
            // int i = 0; // starting row of each upper diagonal is 0
            // int j = i+gap; // starting col of each upper diagonal is row+gap
            for (int i = 0, j = i + gap; i < str.length() && j < str.length(); i++, j++)
            {
                // Trivial Case or Base Case
                if (gap < 2)
                {
                    if (str[i] == str[j])
                    {
                        dp[i][j] = true;
                        ans++;
                    }
                }
                else
                {
                    if (str[i] == str[j] && dp[i + 1][j - 1])
                    {
                        dp[i][j] = true;
                        ans++;
                    }
                }
            }
        }

        return ans;
    }

    string longestPalin(string s)
    {
        // same as counting palindromic substrings in a string
        vector<vector<bool>> dp(s.length(), vector<bool>(s.length(), false));
        int start = 0;
        int len = 1;

        for (int gap = 0; gap < s.length(); gap++)
        {
            for (int i = 0, j = i + gap; j < s.length(); i++, j++)
            {
                // base case
                if (gap < 2 && s[i] == s[j])
                {
                    dp[i][j] = true;

                    // update ans case
                    if (gap + 1 > len)
                    {
                        len = gap + 1;
                        start = i;
                    }
                }
                else if (s[i] == s[j] && dp[i + 1][j - 1])
                {
                    dp[i][j] = true;

                    // update ans case
                    if (gap + 1 > len)
                    {
                        len = gap + 1;
                        start = i;
                    }
                }
            }
        }

        return s.substr(start, len);
    }
};

int main()
{

    return 0;
}