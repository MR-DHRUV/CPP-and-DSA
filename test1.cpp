#include <bits/stdc++.h>
using namespace std;

int butterflies(int n, vector<int> &a)
{
    // monster kill 1 or 2 atttack
    // n monsters

    // 1 monster mara then 1 extra milega

    int n1 = 0, n2 = 0;

    for (int &i : a)
    {
        if (i == 1)
            n1++;
        else
            n2++;
    }

    if (n1 >= n2)
    {
        int ans = n2;

        return n2 + ceil((float)n1 / 2.00);
    }

    int ans = n1;
    ans += n1 / 2;

    int new2 = n2 - n1; // itne 2 bacche haii
    ans += new2 / 2;

    if (new2 % 2 != 0)
    {
        if (n1 % 2 != 0)
        {
            ans++; // nullify ho skta haii 1
        }
        else
        {
            ans += 2;
        }
    }

    return ans;
}

int main()
{

    return 0;
}