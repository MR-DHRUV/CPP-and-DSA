#include <bits/stdc++.h>
using namespace std;



int main()
{
    // chinese remainder theoram 
    //  x%3 = 2
    //  x%5 = 3
    //  x%7 = 4

    // From above 3 values, I need to find x

    // x = A + B + C
    // x = a*3*5 + b*3*7 + c*5*7

    // x%3 = 0 + 0 + c*5*7%3 = 2
    //  35c%3 = 2 => 2c%3 = 2 => c%3 = 1
    // we can calculate c = (1^-1 mod 3)

    // x%5 = 0 + b*3*7 + 0 = 3
    // x%7 = a*3*5 + 0 + 0 = 4


    
    return 0;
}