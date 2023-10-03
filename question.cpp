#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, c;
    cin >> a >> b >> c;

    int g = __gcd(a, b);

    if (c % g == 0)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}