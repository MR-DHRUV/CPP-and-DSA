#include <bits/stdc++.h>
using namespace std;

int getIthbit(int n, int i)
{
    int mask = 1 << i;
    return (n & mask) > 0 ? 1 : 0;
}

int setIthBit(int n, int i)
{
    int mask = 1 << i;
    return n | mask; // or
}

int clearIthBit(int n, int i)
{
    int mask = ~(1 << i);
    return n & mask;
}

int toggleIthBit(int n, int i)
{
    int mask = (1 << i);
    return n ^ mask; // xoring with 1 toggles the bit
}

int updateIthBit(int n, int i, int v)
{
    // we have to put v at ith bit

    // step 1: clear ith bit
    n = clearIthBit(n, i);

    // step 2: put ith bit
    int mask = v << i;

    return n | mask;
}

int clearLastIbits(int n, int i)
{
    // if we left shift by i+1 times and then subtract 1 from it, we get last i bits as set
    // then nor it to get last i 0 and others as 1
    int mask = ~((1 << (i + 1)) - 1);

    return n & mask;
}

int setLastIbits(int n, int i)
{
    int mask = ((1 << (i + 1)) - 1);

    return n | mask;
}

int clearRange(int n, int l, int r)
{
    // we have to create a mask such that its all 0 from lth to rth bit and rest all 1
    // so we'll simply create 2 masks, 1 with all 1 from 0th to lth bit and other from rth bit to last bit
    // we can simply or them to obtain our final mask

    int mask1 = (~0) << (l + 1); // not of 0 all 1's, then we have left shift bits by i+1 times so that all bits from (i to 0) are 0
    int mask2 = (1 << r) - 1;    // 1<<r sets 1 at r'th bit, subt 1 from it make all all bits before t as 1

    int mask = mask1 | mask2;

    return n & mask;
}

int setRange(int n, int l, int r)
{
    int mask1 = (~0) << (l + 1);
    int mask2 = (1 << r) - 1;

    //  nor makes all bits in [l,r] as 1 and other 0
    int mask = ~(mask1 | mask2);

    return n | mask;
}

// function to set bits between l and r in n same as in m, or we can say that m becomes a substring in binary of n starting from l
int setBitsInNasM(int n, int m, int l, int r)
{
    // first I need to clear bits from j to i in n
    n = clearRange(n, l, r);

    // now we to create a mask
    // shift all bits in m by r steps
    int mask = m << r;

    return n | mask;
}

void printBin(int n)
{
    for (int i = 31; i >= 0; i--)
    {
        cout << getIthbit(n, i);
    }

    cout << endl;
}

bool isPowerOf2(int n)
{
    // if a number is power of 2, say 16 we can observe the following property

    // 16 -> 10000
    // 15 -> 01111
    // ans -> 0

    // for not power of 2
    // 5 -> 101
    // 4 -> 100
    // and -> 100

    return (n & (n - 1) == 0);
}

int countSetBits(int n)
{
    int ans = 0;

    while (n > 0)
    {
        n &= n - 1;
        ans++;
    }

    return ans; 
}

int main()
{
    // important
    // indexing is from 0 in bits
    // rightmost bit/lsb is at index 0

#ifndef IO_FROM_FILE
    freopen("C:\\Users\\Dhruv\\OneDrive\\Documents\\CPP + DSA\\input.txt", "r", stdin);
    freopen("C:\\Users\\Dhruv\\OneDrive\\Documents\\CPP + DSA\\output.txt", "w", stdout);
#endif

    int n = 15;
    int m = 2;
    printBin(n);
    printBin(m);
    printBin(setBitsInNasM(n, m, 3, 1));
    cout << setBitsInNasM(n, m, 3, 1) << endl;

    return 0;
}