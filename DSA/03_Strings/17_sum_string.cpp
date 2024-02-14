//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    string add(string s1, string s2)
    {
        string res;
        int i = s1.length() - 1, j = s2.length() - 1, carry = 0;

        while (i >= 0 && j >= 0)
        {
            int d1 = s1[i--] - '0', d2 = s2[j--] - '0';

            res.push_back(((d1 + d2 + carry) % 10) + '0');
            carry = (d1 + d2 + carry) / 10;
        }

        while (i >= 0)
        {
            int d1 = s1[i--] - '0';

            res.push_back(((d1 + carry) % 10) + '0');
            carry = (d1 + carry) / 10;
        }

        while (j >= 0)
        {
            int d2 = s2[j--] - '0';

            res.push_back(((d2 + carry) % 10) + '0');
            carry = (d2 + carry) / 10;
        }

        while (carry > 0)
        {
            res.push_back((carry % 10) + '0');
            carry /= 10;
        }

        reverse(res.begin(), res.end());
        return res;
    }

    bool checkStr(int s, int len1, int len2, string &str)
    {
        string s1 = str.substr(s, len1);
        string s2 = str.substr(s + len1, len2);
        string sum = add(s1, s2);

        // cout<<s1<<" "<<s2<<" "<<sum<<endl;

        // if length of this sum is more than remaining string
        if (sum.length() > str.length() - s - len1 - len2)
            return false;

        // we have calculated the sum, now this should exisit after num2
        if (sum == str.substr(s + len1 + len2, sum.length()))
        {
            if (sum.length() + s + len1 + len2 == str.length())
                return 1;

            // now num1 -> num2 ban jayga and num2 -> sum
            return checkStr(s + len1, len2, sum.size(), str);
        }

        return false;
    }

public:
    int isSumString(string S)
    {
        // make first two partitions
        for (int i = 0; i < S.size(); i++)
        {
            for (int j = i + 1; j < S.size(); j++)
            {
                if (checkStr(0, i + 1, j - i, S))
                    return 1;
            }
        }

        return 0;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.isSumString(S) << endl;
    }
    return 0;
}

// } Driver Code Ends