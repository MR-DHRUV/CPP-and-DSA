#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool find132pattern(vector<int> &nums)
    {
        // i have have to find an increasing subsequence of size 3

        // using multiset as segment tree
        // I will put two pointers i and j and will look for k using set
        set<int> st;
        st.insert(nums.back());

        vector<int> prevSmall(nums.size());
        prevSmall[0] = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            prevSmall[i] = min(prevSmall[i - 1], nums[i - 1]);
        }

        for (int i = nums.size() - 2; i >= 1; i--)
        {
            if (prevSmall[i] < nums[i])
            {
                auto r = st.upper_bound(prevSmall[i]);
                if (r != st.end() && *r < nums[i])
                    return true;
            }

            st.insert(nums[i]);
        }

        return false;
    }
};

int main()
{

    return 0;
}