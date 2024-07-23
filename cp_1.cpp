#include <bits/stdc++.h>
using namespace std;

int mod = (1e9) + 7;

int beats(char a, char b)
{
    if (a == 'R' && b == 'S')
        return 1;
    if (a == 'S' && b == 'P')
        return 1;
    if (a == 'P' && b == 'R')
        return 1;
    if (a == b)
        return 0;
    return -1;
}

int solve(int i, int lastJames, int scoreDiff, string &str, vector<vector<unordered_map<int, int>>> &dp)
{
    if (i == str.size())
        return (scoreDiff > 0) ? 1 : 0;

    if (dp[i][lastJames + 1].count(scoreDiff))
        return dp[i][lastJames + 1][scoreDiff];

    int result = 0;
    for (int j = 0; j < 3; ++j)
    {
        if (j == lastJames)
            continue;

        char jamesMove = (j == 0) ? 'R' : (j == 1) ? 'P' : 'S';

        result = (result + solve(i + 1, j, scoreDiff + beats(jamesMove, str[i]), str, dp)) % mod;
    }

    return dp[i][lastJames + 1][scoreDiff] = result;
}

int solveRPS(string str)
{
    vector<vector<unordered_map<int, int>>> dp(str.size(), vector<unordered_map<int, int>>(5));
    return solve(0, -1, 0, str, dp);
}

///////////////////////////// Game string
void solveGS(int i, int m, int p, string s, string minPath, string &ans, vector<int> f)
{
    if(m == 0 && p == 0)
    {
        ans = max(ans, minPath);
        return;
    }

    if(m == 0 || i >= f.size() || p == 0)
        return;

    solveGS(i + 1, m, p, s, minPath, ans, f);

    if(f[i] > 0)
    {
        // add case
        f[i]--;
        s.push_back((char)('a' + i));
        solveGS(0, m, p - 1, s, minPath, ans, f);

        // break case
        if(!minPath.size())
            minPath = s;
        else
            minPath = min(minPath, s);

        solveGS(0, m - 1, p-1, "", minPath, ans, f);
    }
}

string solveGameS(string s, int m)
{
    string ans;
    vector<int> f(26);
    for(char &ch : s)
        f[ch - 'a']++;

    solveGS(0, m, s.size(), "", "", ans, f);
    return ans;
}


/////////////////

int main()
{

    cout << solveGameS("abacadae",4) << endl;

    return 0;
}
