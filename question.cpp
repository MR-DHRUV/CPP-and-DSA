#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long findKthSmallest(vector<int> &coins, int k)
    {
        sort(coins.begin(), coins.end());

        if (coins[0] == 1)
            return k;

        set<pair<int, int>> st;
    }
};



int main()
{

    return 0;
}