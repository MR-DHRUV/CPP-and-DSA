#include <bits/stdc++.h>
using namespace std;

string decodeAtIndex(string s, int k)
{

    string ans;

    for (int i = 0; i < s.length() && ans.size() < k; i++)
    {
        if (!(s[i] >= '0' && s[i] <= '9'))
            ans.push_back(s[i]);
        else
        {
            // build number
            int n = 0;
            while (s[i] >= '0' && s[i] <= '9')
                n = n * 10 + (s[i++] - '0');

            i--;
            n--;

            string temp = ans;
            while (n-- && ans.size() < k)
                ans.append(temp.begin(), temp.end());
        }
    }

    cout<<ans;
    return {ans[k - 1]};
}

int main()
{
    cout << decodeAtIndex("vzpp636m8y",2920);

    return 0;
}