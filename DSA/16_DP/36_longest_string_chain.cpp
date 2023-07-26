#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool chk_string(string &a, string &b)
    {
        if (a.length() != b.length() - 1)
        {
            return false;
        }

        int i = 0, j = 0;

        int cnt = 0;

        while (i < a.size() && j < b.size() && cnt < 2)
        {
            if (a[i] != b[j])
            {
                cnt++;
                j++;
            }
            else
            {
                i++;
                j++;
            }
        }

        if (cnt >= 2)
        {
            return false;
        }

        return true;
    }

public:
    int longestStrChain(vector<string> &words)
    {
        // based on lis approach

        // sorting in increasing order of length
        sort(words.begin(), words.end(), [](string &a, string &b)
             { return a.length() < b.length(); });

        vector<int> dp(words.size(), 1);
        ;

        int len = 1, lastIndex = 0;

        for (int i = 0; i < words.size(); i++)
        {
            for (int prev = 0; prev < i; prev++)
            {
                if (chk_string(words[prev], words[i]) && dp[prev] + 1 > dp[i])
                {
                    dp[i] = 1 + dp[prev];
                }
            }

            // tracking lis start and length
            if (dp[i] > len)
            {
                len = dp[i];
                lastIndex = i;
            }
        }

        return len;
    }
};

int main()
{

    return 0;
}