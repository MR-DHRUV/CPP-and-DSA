#include <bits/stdc++.h>
using namespace std;

// brain kerninghams algorithm is used to count set bits in only time equal to no of set bits , no extra iterations

int countsetBits(int n)
{
    int count = 0;

    while (n > 0)
    {
        n = n & (n - 1);
        count++;

        // also
        // we can first obtain right most set bit using formula
        // int rightSetBit = n & (~(n-1));
    }

    return count;
}

int main()
{
    cout << countsetBits(5) << endl;
    return 0;
}