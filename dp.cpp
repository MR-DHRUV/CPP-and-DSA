#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        // wohi include exlude wala game ahii
        // we just have to check if current value is the multiple of any number present in coins as a base case as we dont need permuattions like this
        // 1 1 2 and 2 1 1 are concidered as same and its given that all values of coins is unique so duplicacy is eliminated

        vector<int> dp(amount + 1, 0);
        dp[0] = 1; // 0 can be made without any coin
        sort(coins.begin(),coins.end()); // sort as its bottom-up approach so we will need smaller coins first

        for (int c : coins)
        {
            for (int i = c; i <= amount; i++)
            {
                if (i - c >= 0)
                    dp[i] += dp[i - c];
            }
        }

        return dp[amount];
    }
};

int main()
{

    return 0;
}