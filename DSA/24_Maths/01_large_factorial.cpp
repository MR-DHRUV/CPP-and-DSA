#include <bits/stdc++.h>
using namespace std;

void mul(vector<int> &res, int n, int &size)
{
    int carry = 0;

    for (int i = 0; i < size; i++)
    {
        int p = res[i] * n + carry;
        res[i] = p % 10;
        carry = p / 10;
    }

    while (carry)
    {
        res[size++] = carry % 10;
        carry /= 10;
    }
}

void facN(int n)
{
    vector<int> ans(100000000, 0);
    ans[0] = 1; // 1 factorial
    int size = 1;

    for (int i = 2; i <= n; i++)
        mul(ans, i, size);

    for (int i = size - 1; i >= 0; i--)
        cout << ans[i] << " ";
}

int main()
{
    // to store large factorials se will use arrays
    facN(1000);

    return 0;
}