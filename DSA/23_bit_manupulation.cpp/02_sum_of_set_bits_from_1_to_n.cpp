#include <bits/stdc++.h>
using namespace std;

int countSetBits(int n)
{
    int ans = 0, grpSize = 1;

    // n++ as we are counting the count of number till current number, so it includes 0 also
    n++;

    /*
        binary is like
        0000
        0001
        0010
        0011
        0100
        0101
        0110

        we have groups of 2^(i+1) in which first 2^i numbers are 0 then 1
        so for each index we calculate complete and partial groups and add set bits in our sum
    */

    for (int i = 0; i <= log2(n) + 1; i++)
    {
        grpSize = 1 << i;
        int completeGrp = n / grpSize;
        int partialGrp = n % grpSize;

        ans += (completeGrp * (grpSize / 2));

        // if partial grp has ones
        ans += max(partialGrp - (grpSize / 2), 0);
    }

    return ans;
}

int main()
{

    return 0;
}