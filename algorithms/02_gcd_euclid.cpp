#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// euclids algo
//  gcd(a,b) = gcd(a-b,b) = gcd(a%b,b)

// lcm(a,b) * gcd(a,b) = a*b
// lcm = a*b/gcd

int gcd(int a, int b)
{
    a = abs(a);
    b = abs(b);

    if (a == 1 || b == 1)
    {
        return 1;
    }

    if (a == 0)
    {
        return b;
    }
    if (b == 0)
    {
        return a;
    }

    while (a != b)
    {
        if (a > b)
        {
            a -= b;
        }
        else
        {
            b -= a;
        }
    }

    return b;
}

ll lcm(int a, int b)
{
    ll ans = a * b / gcd(a, b);
    return ans;
}

int main()
{
    // int a = 30 , b = 40;
    // long long int gd = gcd(a,b);
    // cout<<gd<<endl;
    // cout<<"LCM : "<<(a*b/gd)<<endl;

    ll a = lcm(20, 19);
    ll b = lcm(13, 17);
    ll c = lcm(a, b);

    cout << a << " " << b << " " << c << " ";
    cout << gcd(-5, -15);

    return 0;
}