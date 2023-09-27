#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countTriplets(vector<int> &nums)
    {
        int ans = 0;
        int cnt[1 << 16] = {0};

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < nums.size(); j++)
            {
                cnt[nums[i] & nums[j]]++;
            }
        }

        for (int &num : nums)
        {
            for (int i = 0; i < (1 << 16); i++)
            {
                if ((num & i) == 0)
                    ans += cnt[i];
                else
                {
                    // core optimization
                    // we are going to shift i that many places in which and of numbers and num can't be zero
                    i += (num & i) - 1;

                    // this simply means that we have set bits in some places
                    // now these sets bits will turn off after num&i iterations 
                    // so we subtract 1 as loop incriment is there  
                    // so we effectivly skip large ranges 
                }
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}