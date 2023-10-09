#include <bits/stdc++.h>
using namespace std;

int main()
{
    // we can compute a table of binomial coefficients using pascal's triangle method
    // n r->
    // 1
    // 1 1
    // 1 2 1
    // 1 3 3 1
    // ....

    int n = 5, k = 4; // max till we need

    vector<vector<int>> b(n + 1, vector<int>(k + 1, 0));
    b[0][0] = 1;

    if (n >= 1)
        b[1][0] = b[1][1] = 1;

    for (int i = 2; i <= n; i++)
    {
        b[i][0] = 1; // nc0 = ncn = 1

        if (i <= k)
            b[i][i] = 1;

        for (int j = 1; j <= min(i, k); j++)
        {
            b[i][j] = b[i - 1][j - 1] + b[i - 1][j];
        }
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= min(i, k); j++)
        {
            cout << b[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}