#include <bits/stdc++.h>
using namespace std;

using mat = vector<vector<int>>;

mat multiply(mat &a, mat &b)
{
    mat res(a.size(), vector<int>(a.size(), 0));

    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a.size(); j++)
        {
            for (int k = 0; k < a.size(); k++)
            {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    return res;
}

mat matExpo(mat a, int b)
{
    // make identity matrix
    mat res(a.size(), vector<int>(a.size(), 0));
    for (int i = 0; i < a.size(); i++)
    {
        res[i][i] = 1;
    }

    while (b > 0)
    {
        if (b & 1)
            res = multiply(res, a);

        a = multiply(a, a);
        b >>= 1;
    }

    return res;
}

int main()
{
    // used to calculate powers of matrix on logarithmic time
    // used in high-fi dp problems
    // used to find fibonacchi number on logN time

    mat a = {{1, 1}, {1, 0}};
    mat res = matExpo(a, 23);

    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res.size(); j++)
        {
            cout << res[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}