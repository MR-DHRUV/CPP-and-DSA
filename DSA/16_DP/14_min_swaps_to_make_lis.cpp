#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int solve(int i, vector<int> nums1, vector<int> nums2)
    {
        // base case
        if (i == nums1.size())
            return 0;

        // check if we have to swap or not
        int ans = 0;

        if (nums1[i - 1] >= nums1[i] || nums2[i - 1] >= nums2[i])
        {
            // finding optimal swap
            swap(nums1[i], nums2[i]);
            ans = 1 + solve(i + 1, nums1, nums2);
        }
        else
        {
            ans = solve(i + 1, nums1, nums2);
        }

        return ans;
    }

public:
    int minSwap(vector<int> &nums1, vector<int> &nums2)
    {
        return solve(1, nums1, nums2);
    }
};

int main()
{

    return 0;
}