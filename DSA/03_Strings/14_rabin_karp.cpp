#include <bits/stdc++.h>
using namespace std;

void find(string text, string pattern)
{
    if (text.length() <= pattern.length())
    {
        if (text == pattern)
            cout << "0" << endl;

        return;
    }

    int i = 0, j = pattern.size() - 1;

    string s = text;
    s.substr(0, pattern.length());

    // calculate hash value
    int hp = 0, ht = 0, h = 0;
    int d = 256, q = INT_MAX; // d is no of distinct characters so in ascii we have 256

    for (i = 0; i < pattern.length() - 1; i++)
        h = (h * d) % q;

    // initial hash values of pattern and text
    for (int i = 0; i < pattern.size(); i++)
    {
        hp = (d * hp + pattern[i]) % q;
        ht = (d * ht + text[i]) % q;
    }

    for (int i = 0; i <= text.length() - pattern.length(); i++)
    {
        if (hp == ht)
        {
            int j = 0;
            for (; j < pattern.length(); j++)
            {
                if (pattern[j] != text[j + i])
                    break;
            }

            if (j == pattern.size())
                cout << i << endl;
        }

        // new hash values
        if (i < text.length() - pattern.length())
        {
            ht = (d * (ht - text[i] * h) + text[i + pattern.size()]) % q;

            // negitive mod covervsion
            if (ht < 0)
                ht = (ht + q);
        }
    }
}

int main()
{
    find("geeksforgeeks", "geek");

    return 0;
}