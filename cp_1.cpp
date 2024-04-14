#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<long long> maximumSegmentSum(vector<int> &nums, vector<int> &removeQueries)
    {
        int n = nums.size();
        
        multiset<long long, greater<long long>> segmentSums;
        set<int> removedIndices{-1, n};

        vector<long long> res(n), prefix(n);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++)
            prefix[i] = prefix[i - 1] + nums[i];

        segmentSums.insert(prefix.back());

        for (int i = 0; i < n; i++)
        {
            auto after = removedIndices.lower_bound(removeQueries[i]);
            auto before = prev(after);

            auto sum = prefix[*after - 1] - (*before < 0 ? 0 : prefix[*before]);
            segmentSums.erase(segmentSums.find(sum));

            segmentSums.insert(prefix[*after - 1] - prefix[removeQueries[i]]);
            if (removeQueries[i] - 1 >= 0)
                segmentSums.insert(prefix[removeQueries[i] - 1] - (*before < 0 ? 0 : prefix[*before]));

            removedIndices.insert(removeQueries[i]);

            res[i] = *segmentSums.begin();
        }

        return res;
    }
};

int main()
{
  
  
    return 0;
}