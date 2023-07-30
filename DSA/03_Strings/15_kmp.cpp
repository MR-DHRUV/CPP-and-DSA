#include <bits/stdc++.h>
using namespace std;

// O(n+m)
void solve(string text, string pattern)
{
    // lps : longest prefix which is same as suffix
    // lps[i] denotes the length of longest prefix which is also a suffix of the string till index i.
    // this means if we backtrack to lps[i] we will be at next character that has to be matched as we take length of this prefix.

    // In the naive algorithm we have to backtrack everytime we find a mismatch to i+1th location so to avoid this will contruct a lps array for pattern and using which we will only backtrack as much need

    // Pattern : ababd
    //     lps : 00120

    // text:  ababcabcabababd
    // when we will reach ababc , at c we will have a mismatch so now instead of backtracking to first b we will see the lps

    // we will start the indicing of pattern from -1 and wil compare text[i] to pattern[j+1]

    // now in pattern we are at abab and the lps at b is 2 , so we backtrack to index 2 in pattern (1-based indexing)

    // this means we are at the first index where that prefix occurs in the pattern.

    // conputing lps array
    int n = text.size(), m = pattern.size();

    vector<int> lps(m, 0);

    int i = 1; // pointer 
    int len = 0; // length of prefix

    while (i < m)
    {
        if (pattern[i] == pattern[len])
        {
            lps[i++] = ++len;
        }

        else
        {
            // Now there is is mismatch
            // if len = 0, then its ok as we are starting prefix from index 0
            // but if len != 0 and there is a mis match then we have lost the continuity so, we have to backtrack to such a position that can serve as a match thus we backtrack to last prefix  

            if (len != 0)
            {
                len = lps[len - 1];
                // here we have not incrimented i, we are here backtracking to last prefix
            }
            else
            {
                // len = 0 means there is no prefix for given characters so move ahead and make its lps 0
                lps[i] = len;
                i++;
            }
        }
    }

    for(int i : lps)
        cout<<i<<" ";

    // start kmp search
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
            cout << "Pattern found at " << i - j << endl;
            j = lps[j-1]; // now backtrack to place in pattern where this is this ptrfix
        }
        else if (i < n && text[i] != pattern[j])
        {
            // mismatch

            if (j != 0)
                j = lps[j-1]; // backtrack
            else
                i++;
        }
    }
}

int main()
{
    solve("oonoonions", "oonions");
    return 0;
}