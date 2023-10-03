#include <bits/stdc++.h>
using namespace std;
#define int long long int

// gcd(a,b) = gcd(a-b,b) = gcd(a%b,b)
// lcm = a*b/gcd

// Complexity
// gdc(a,b) = gcd(a%b,b)
// gdc(a,b) = gcd(x,b)

// 0 <= x <= b-1
// x = a%b = a - |a/b|*b

// x <= a - b (when a > b)

// x <= a-b
// x <= b-1
// 2x < a-1
// x < a/2

// Now in every succesive iteration x will be reduced to a/2 
// gcd(x,b)
// gcd(b%x,x)
// gcd(x%y,y)
// ... 

// So O(log2A)
int gcd(int a, int b)
{
    a = abs(a);
    b = abs(b);

    while (b > 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int32_t main()
{
    cout<<gcd(12,20)<<endl;

    return 0;
}