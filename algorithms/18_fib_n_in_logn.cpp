#include <bits/stdc++.h>
using namespace std;

void print(vector<int> arr)
{
    for (int &i : arr)
        cout << i << " ";
    cout << endl;
}

void print(vector<vector<int>> arr)
{
    for (auto &j : arr)
    {
        for (int &i : j)
            cout << i << " ";
       cout << endl;
    }
}

vector<vector<int>> multiply(vector<vector<int>> &mat1, vector<vector<int>> &mat2)
{
    vector<vector<int>> ans(2, vector<int>(2, 0));

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                ans[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    return ans;
}

vector<vector<int>> matrixExpo(vector<vector<int>> &a, int n)
{
    if (n == 0)
    {
        // return identity matrix
        return {{1, 0}, {0, 1}};
    }
    if (n == 1)
        return a;

    vector<vector<int>> temp = matrixExpo(a, n / 2);
    vector<vector<int>> ans = multiply(temp, temp); // O(1) as 2*2 matrix haii

    if ((n & 1) == 1)
        ans = multiply(ans, a);

    return ans;
}

int fib(int n)
{
    // representing fibonacci series in matrix
    /*
        Fn      =   a b    Fn-1
        Fn-1        c d    Fn-2

        Fn      =   aFn-1 + bFn-2
        Fn-1        cFn-1 + dFn-2

        Fn = aFn-1 + bFn-2
        Fn = Fn-1 + Fn-2

        a = 1 and b = 1

        Fn-1 = cFn-1 + dFn-2
        Fn-1 = Fn-1

        c = 1 and d = 0

        Matrix Exponenciation
        Fn      =   1 1    Fn-1
        Fn-1        1 0    Fn-2

        Fn      =   1 1  1 1  Fn-2
        Fn-1        1 0  1 0  Fn-3
        .
        .
        .
        breaking till

        Fn      =   1 1  1 1 ...... F2
        Fn-1        1 0  1 0 ...... F1

        // no of multiplications : n-2

        Fn      =  M^n-2 F2
        Fn-1             F1

        M = 1 1
            1 0
    */

    vector<vector<int>> M = {{1, 1}, {1, 0}};
    vector<vector<int>> ans = matrixExpo(M, n-1);
    vector<pair<int, int>> p;

    for(auto [_,o] : p)
    {

    }

    return ans[0][0];
}


int main()
{

    fib(5);

    return 0;
}