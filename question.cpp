#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<int> getOcc(string text, string pattern)
    {
        int n = text.size(), m = pattern.size();
        vector<int> lps(m, 0), ans;

        int i = 1;
        int len = 0; 

        while (i < m)
        {
            if (pattern[i] == pattern[len])
                lps[i++] = ++len;
            else
            {
                if (len != 0)
                    len = lps[len - 1];
                else
                {
                    lps[i] = len;
                    i++;
                }
            }
        }

        i = 0;
        int j = 0;

        while (n - i >= m - j)
        {
            if (text[i] == pattern[j])
            {
                i++;
                j++;
            }

            if (j == m)
            {
                ans.push_back(i - j);
                j = lps[j - 1]; 
            }
            else if (i < n && text[i] != pattern[j])
            {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i++;
            }
        }
    }

public:
    vector<int> beautifulIndices(string s, string a, string b, int k)
    {
        vector<int> c1 = getOcc(s, a), c2 = getOcc(s, b), ans;

        for(int &i : c1)
        {
            int low = i - k, high = i + k;
            int l1 = lower_bound(c2.begin(), c2.end(), low)- c2.begin();

            if(l1 < c2.size() && abs(i-c2[l1]) <= k)
                ans.push_back(i);
            else
            {
                int l2 = upper_bound(c2.begin(), c2.end(), high) - c2.begin();
                if(l2-1 >= 0 && l2-1 < c2.size() && abs(i-c2[l2-1]) <= k)
                    ans.push_back(i);
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}