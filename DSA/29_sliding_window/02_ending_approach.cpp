#include <bits/stdc++.h>
using namespace std;

// for questions like
/*Given an array of integers nums and an integer k, return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.*/

// In such situaltions where we need to exhaustively check all the subarrays, we can us the sliding window in following way

// we will move window one by one such that we have a maximal window with product less than k that ends at j
// Now we can add all the subarrays ending at j

// Eg: [10, 5, 2, 6] k = 100

// i     j         product      count
// 0     0         10           1 ({10})
// 0     1         50           2 ({10, 5}, {5})
// 1     2         10           2 ({5, 2}, {2})
// 1     3         60           3  ({5, 2, 6}, {2, 6}, {6})
// Total count = 8
#pragma GCC optimize("O3,O1,Ofast");

class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {

        if (k == 0)
            return 0;
        int ans = 0, i = 0, j = 0;
        long long p = 1;

        while (j < nums.size())
        {
            p *= nums[j++];

            while (p >= k && i < j)
                p /= nums[i++];
            ans += (j - i);
        }

        return ans;
    }
};

int main()
{

    return 0;
}