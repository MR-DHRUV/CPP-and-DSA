#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rangeBitwiseAnd(int left, int right)
    {
        // core intuition
        // for consicutive numbers 1,2,3,4...
        // when a bit is flipped then all the bits to their right are also fipped
        // and of all numbers in range l,r will only have non flipped bits

        int ans = 0;

        for (int i = 0; i < 31; i++)
        {
            if ((left & 1) == (right & 1))
            {
                if ((left & 1) == 1)
                {
                    ans |= 1 << i;
                }
            }
            else
            {
                // flipped bit
                ans = 0;
            }

            left >>= 1;
            right >>= 1;
        }

        return ans;
    }

    int rangeBitwiseAndFAST(int left, int right)
    {
        // even better approach
        while (right > left)
            right = right & right - 1;

        return left & right;
    }
};

int main()
{

    return 0;
}