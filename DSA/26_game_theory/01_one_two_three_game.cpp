#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canWinNim(int n)
    {
        // 1 to 3 stones can be picked in 1 move
        // last stone remove -> winner
        // first move is mine

        // agar 1 se 3 stones h toh m hi jeetunga
        // 4 th stone aate hi m pakka harunga

        if (n % 4 == 0)
            return 0;

        return 1;
    }
};

int main()
{

    return 0;
}