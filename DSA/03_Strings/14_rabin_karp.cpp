#include <bits/stdc++.h>
using namespace std;

//  Avg : O(n+m), worst : O(n * m)
// By using a rolling hash, the algorithm can compute the hash value of each window in the text in constant time,
void find(string text, string pattern)
{
    // calculate hash value
    int hp = 0, ht = 0, h = 1;
    int d = 256, q = INT_MAX; // d is no of distinct characters so in ascii we have 256

    for (int i = 0; i < pattern.length() - 1; i++)
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
    find("batmanandrobinarebat", "bat");

    return 0;
}