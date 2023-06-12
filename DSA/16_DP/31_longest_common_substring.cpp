#include <bits/stdc++.h>
using namespace std;

int lcs(string &str1, string &str2)
{
    //	now we need substring

    // simmilar to tabulation of subsequence here we will fill the dp array as follows
    // if current characters match then the ans is 1+(dp[i-1][j-1]) as we need no break else 0

    vector<vector<int>> dp(str1.size() + 1, vector<int>(str2.size() + 1, 0));
    int ans = 0;

    for (int i = 0; i < str1.size(); i++)
    {
        for (int j = 0; j < str2.size(); j++)
        {
            if (str1[i] == str2[j])
            {
                dp[i][j] = 1;

                // no breaks in between
                if (i - 1 >= 0 && j - 1 >= 0)
                    dp[i][j] += dp[i - 1][j - 1];

                ans = max(ans, dp[i][j]);
            }
        }
    }

    return ans;
}

int main()
{

    return 0;
}