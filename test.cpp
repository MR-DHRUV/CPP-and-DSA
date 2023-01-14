#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string smallestEquivalentString(string s1, string s2, string baseStr)
    {

        unordered_map<char, char> mp;
        // init : O(1)
        // initially a=a, b=b and so on.....
        for (char i = 'a'; i <= 'z'; i++)
        {
            mp[i] = i;
        }

        // plot the given values
        for (int i = 0; i < s1.length(); i++)
        {
            char smallest = min(s1[i], s2[i]);

            if (mp[s1[i]] > smallest)
            {
                mp[s1[i]] = smallest;
            }

            if (mp[s2[i]] > smallest)
            {
                mp[s2[i]] = smallest;
            }
        }

        // minimize the values
        // we cant minimize a 🤣
        for (char i = 'b'; i <= 'z'; i++)
        {
            char min = i;
            while (mp[min] < min)
            {
                min = mp[min];
            }
            mp[i] = min;
            cout<<i<<" "<<min<<endl;
        }

        // minimize and return
        for (int i = 0; i < baseStr.length(); i++)
        {
            baseStr[i] = mp[baseStr[i]];
        }

        return baseStr;
    }
};

int main()
{
    Solution s;
    cout<<s.smallestEquivalentString("leetcode","programs","sourcecode");
    return 0;
}