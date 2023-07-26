#include <bits/stdc++.h>
using namespace std;

void find(string text, string pattern)
{
    for (int i = 0; i < text.length()-pattern.length(); i++)
    {
        int j = 0;
        for (; j < pattern.length(); j++)
        {
            if(text[i+j] != pattern[j])
                break;;
        }

        if(j == pattern.size())
            cout<<i<<endl;
    }
}

int main()
{
    find("geeksforgeeks", "geek");

    return 0;
}