#include <bits/stdc++.h>
using namespace std;

void reverseStr(string &str, int e, int s)
{
    if (s == e)
    {
        return;
    }

    swap(str[s], str[e]);

    return reverseStr(str, e - 1, s + 1);
}



int main()
{
    string str = "dhruv";
    reverseStr(str, 4, 0);
    cout << str;

    return 0;
}