#include <bits/stdc++.h>
using namespace std;

pair<int,int> extendedEuclid(int a, int b)
{
    if (b == 0)
        return {1, 0};

    auto res = extendedEuclid(b, a % b);

    int x = res.second;
    int y = res.first - ((a / b) * res.second);

    return {x, y};
}

int moduloInverse(int a, int m)
{
    if (__gcd(a, m) != 1)
        return -1;

    int ans = extendedEuclid(a, m).first;
    ans = (ans + m) % m; // as it can be -ve... so to make it in a range 1 to m

    return ans;
}

int main()
{
    // to find multiplicative modulo inverse of a under mod m
    // a a-1 == 1 mod m
    // a x == 1 mod m

    // we need to find such a number x
    // (a*x)%m = 1
    // 1 <= x <= m-1
    // this x exists iff a and m are co prime , thus gcd(a,m) = 1

    // Brutre force: check all numbers from 1 to m
    // Optimal : Extended euclid algorithm

    // Ax + By = gcd(A,B)
    // Ax + My = gcd(A,M) = 1
    // Ax + My =  1
    // taking mod both sides
    // Ax%M + My%M =  1%M
    // Ax%M + 0 =  1%M
    // we just need to find x

    int a = 14, m = 7;
    cout<<moduloInverse(a,m);

    return 0;
}