#include <bits/stdc++.h>
using namespace std;

vector<int> extendedEuclid(int a, int b)
{
    if (b == 0)
        return {1, 0};

    auto res = extendedEuclid(b, a % b);

    int x = res[1];
    int y = res[0] - ((a / b) * res[1]);

    return {x, y};
}

vector<int> solve(int a, int b, int c)
{
    int g = __gcd(a, b);

    if (c % g != 0)
        return {-1};

    int k = c / g;

    auto ans = extendedEuclid(a, b);

    return {ans[0] * k, ans[1] * k};
}

int main()
{
    // to compute solution of linear diophantine equation
    // 25x + 15y = 400
    // ax + by = v
    // we only have this one equation

    // gcd(A,B) = g
    // a = gK1, b = gK2

    // gK1.x + gK2.y = c
    // K1.x + K2.y = c/g

    // solutions will exist iff c%g == 0 as LHS is linear
    // if C is divible by gcd of a and b, the eqn will have a solution

    // ax + by = g*K3  (since c is divisible by g)

    // from extended eucluid, we can compute x1,y1 when eqn is of the form
    // ax1 + by1 = g
    // a x1.k + b y1.k = g.k
    // a x2 + b y2 = G
    // x2 = x1.k = x
    // y2 = y1.k = y

    // Now, one thing, if such an eqn has one solution, then it will have infinitly many solutions

    // say x0, yo is a solution

    // ax0 + byo = c
    // a[x0 + b*t/g] + b[y0 - a*t/g] = c

    int a = 25, b = 15, c = 400;

    auto ans = solve(a, b, c);

    for (auto &i : ans)
        cout << i << endl;

    return 0;
}