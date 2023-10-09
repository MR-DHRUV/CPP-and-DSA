#include <bits/stdc++.h>
using namespace std;

int main()
{
    // min no of people such that there is a 50% chance that two have same birthday

    // total days = 365
    // if we have 366 people, then 2 will have same bday with 100% chance

    // 1-p = all people have diff birthday

    // we can observe that as no of people increase the probability that they have differnt birthday will decreace
    // 1 365/365 = 100%
    // 2 365/365 * 364/365 = 99.72%
    // and so on

    // we need to see when this value is just below 50 as then p will become >= 50

    double p = 1;

    double OneMinusP = 1 - p, n = 1, nc = 1;

    while (nc >= OneMinusP && nc > 0)
    {
        nc *= (365 - n++) / 365;
    }

    cout << n << endl;

    return 0;
}