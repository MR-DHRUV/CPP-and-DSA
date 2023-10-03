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
        return {-1,-1};

    int k = c / g;

    auto ans = extendedEuclid(a, b);

    return {ans[0] * k, ans[1] * k};
}

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, c;
    cin >> a >> b >> c;

    auto res = solve(a, b, c);
    cout<<res[0]<<" "<<res[1]<<endl;

    if (res[0] >= 0 && res[1] >= 0)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}