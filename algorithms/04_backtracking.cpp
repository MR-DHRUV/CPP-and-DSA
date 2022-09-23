#include <bits/stdc++.h>
using namespace std;

// phone keypad problem

class Solution
{
    void solve(string digits, string output, int index, vector<string> &ans, string mapping[])
    {
        // base case
        if (index >= digits.length())
        {
            ans.push_back(output);
            return;
        }

        // subtracting '0' returns exact no in int type
        int number = digits[index] - '0';

        string value = mapping[number];

        for (int i = 0; i < value.length(); i++)
        {
            output.push_back(value[i]);
            solve(digits, output, index + 1, ans, mapping);
            // returning from every call value[i] needs to be removed so that for next iteration of loop output will be a empty string, and this process is called backtracking

            output.pop_back();
        }

        return;
    }

public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> ans;

        if (digits.length() == 0)
        {
            return ans;
        }

        string output;

        int index = 0;

        // mapping
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        // since 0 aur 1 out of range hain

        solve(digits, output, index, ans, mapping);
    }
};

int main()
{

    return 0;
}