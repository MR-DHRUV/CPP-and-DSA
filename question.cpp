#include <bits/stdc++.h>
using namespace std;

class Solution
{
    unordered_map<string, unordered_map<string, int>> hd;

    int hammingDist(string &a, string &b)
    {
        if (a.length() != b.length())
            return 2;

        if (hd.count(a) && hd[a].count(b))
            return hd[a][b];

        int ans = 0;

        for (int i = 0; i < a.length(); i++)
        {
            if (a[i] != b[i])
            {
                if (++ans > 1)
                    return hd[a][b] = 2;
            }
        }

        return hd[a][b] = ans;
    }

    vector<string> solve(int i, int len, vector<string> &words, vector<int> &groups, unordered_map<int, unordered_map<int, vector<string>>> &dp)
    {
        if (i >= words.size() || (len != -1 && words[i].length() != len))
            return {};

        if (len != -1 && dp.count(i) && dp[i].count(len))
            return dp[i][len];

        auto a1 = solve(i + 1, len, words, groups, dp);
        int j = i + 1;

        while (j < groups.size())
        {
            if (groups[j] != groups[i] && (len == -1 || words[j].length() == len) && hammingDist(words[i], words[j]) == 1)
                break;

            j++;
        }

        auto a2 = solve(j, words[i].length(), words, groups, dp);
        a2.push_back(words[i]);

        if (a2.size() > a1.size())
            return dp[i][len] = a2;

        return dp[i][len] = a1;
    }

public:
    vector<string> getWordsInLongestSubsequence(int n, vector<string> &words, vector<int> &groups)
    {
        unordered_map<int, unordered_map<int, vector<string>>> dp;
        auto ans = solve(0, -1, words, groups, dp);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
}
