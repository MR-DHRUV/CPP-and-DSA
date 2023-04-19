#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int dp[501][501]; // memo

    int solve(int i, int j, string &word1, string &word2)
    {
        if (i == word1.length())
        {
            // now we have to add some characters

            // j-1 tak string matched haii
            return word2.length() - j; // +1 added haii as j is in index
        }

        if (j == word2.length())
        {
            // now we have to delete some characters
            return word1.length() - i;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;

        // case 1 : same
        if (word1[i] == word2[j])
        {
            ans = solve(i + 1, j + 1, word1, word2);
        }
        // case 2 : not same
        else
        {
            // option1 : replace
            ans = 1 + solve(i + 1, j + 1, word1, word2);

            // option2 : delete
            /*
                abaxcs
                fdjjs

                curr index points to x

                x delete krdia str1 me se
                abacs

                now curr index points to c i.e i+1 and j is as it is
            */
            ans = min(ans, 1 + solve(i + 1, j, word1, word2));

            // option3 : insert
            /*
                abaxcs
                fdjjs

                curr index points to x

                j insert krdia before x
                abajxcs

                now curr index points to x only no change but we have matched j so j will become j+1
            */
            ans = min(ans, 1 + solve(i, j + 1, word1, word2));
        }

        return dp[i][j] = ans;
    }

    int solveTab(string &word1, string &word2)
    {
        vector<vector<int>> dp(2, vector<int>(word2.length() + 1, 0));

        for (int i = word1.length(); i >= 0; i--)
        {
            for (int j = word2.length(); j >= 0; j--)
            {
                // base case
                if (i == word1.length())
                {
                    dp[0][j] = word2.length() - j;
                }
                else if (j == word2.length())
                {
                    dp[0][j] = word1.length() - i;
                }

                // case 1 : same
                else if (word1[i] == word2[j])
                {
                    dp[0][j] = dp[1][j + 1];
                }
                // case 2 : not same
                else
                {
                    // option1 : replace
                    dp[0][j] = 1 + dp[1][j + 1];

                    dp[0][j] = min(dp[0][j], 1 + dp[1][j]);

                    dp[0][j] = min(dp[0][j], 1 + dp[0][j + 1]);
                }
            }

            dp[1] = dp[0];
        }

        return dp[0][0];
    }

public:
    int minDistance(string word1, string word2)
    {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, word1, word2);
    }
};

int main()
{

    return 0;
}