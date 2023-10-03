#include <bits/stdc++.h>
using namespace std;
#define int long long int


vector<int> extendedEuclid(int a, int b)
{
    if (b == 0)
        return {1, 0};

    auto res = extendedEuclid(b, a % b);

    int x = res[1];
    int y = res[0] - ((a / b) * res[1]);

    return {x, y};
}

int32_t main()
{
    // Extended euclid's algo is usefull for solving equations of the form
    // Ax + By = gcd(A,B)

    // Bx1 + (A%B)y1 = gcd(B,A%B)
    // Bx1 + (A- (|A/B|B)y1 = gcd(B,A%B)

    // B[x1 - (|A/B|)y1] + Ay1 = gcd(B,A%B)
    // B[x1 - (|A/B|)y1] + Ay1 = Ax + By

    // x = y1
    // y = x1 - (|A/B|)y1

    // we have to keep finding x y till B becomes 0 as
    // Axn + 0yn = gcd(A,B) = gcd(A,0) = A
    // xn = 1 and yn = 0
    // and we can return this value to parent equation to compute its solutions

    auto res = extendedEuclid(18,12);
    cout<<res[0]<<" "<<res[1]<<endl;

    return 0;
}