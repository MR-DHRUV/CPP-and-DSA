#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    vector<long long> mostFrequentIDs(vector<int> &nums, vector<int> &freq)
    {
        vector<long long> v;
        const int maxNum = *max_element(nums.begin(), nums.end());
        vector<long long> feq(maxNum + 1, 0);
        long long maxfeq = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (freq[i] >= 0)
            {
                feq[nums[i]] += freq[i];
                maxfeq = max(maxfeq, feq[nums[i]]);
            }
            else
            {
                long long temp = feq[nums[i]];
                feq[nums[i]] = max(0LL, feq[nums[i]] + freq[i]);
                if (temp == maxfeq)
                {
                    maxfeq = *max_element(feq.begin(), feq.end());
                }
            }
            v.push_back(maxfeq);
        }
        return v;
    }
};

int main()
{
  
  
    return 0;
}