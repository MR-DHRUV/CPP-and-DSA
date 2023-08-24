#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
class BIT
{
    ll *bit;
    ll size;

public:
    BIT(ll n) : size(n)
    {
        bit = new ll[n + 1]{0};
    }

    void update(ll i, ll val)
    {
        for (; i <= size; i += (i & (-i)))
        {
            bit[i] += val;
        }
    }

    ll sum(ll i)
    {
        ll ans = 0;

        for (; i > 0; i -= (i & (-i)))
        {
            ans += bit[i];
        }

        return ans;
    }

    ll query(ll l, ll r)
    {
        return sum(r) - sum(l - 1);
    }
};

class Solution
{
public:
    int reversePairs(vector<int> nums)
    {
        vector<int> order(nums.begin(), nums.end());

        sort(order.begin(), order.end());
        order.erase(unique(order.begin(), order.end()), order.end()); // remove duplicates

        int ans = 0;

        // now hum order ko use krenge instead of actual index to reduce space complexity to O(N)from O(4*maxElement)
        BIT b(nums.size());

        for (int i = 0; i < nums.size(); i++)
        {
            int &ele = nums[i];

            // now we need to find form index at which value is greater than 2*ele
            int ele_rank = upper_bound(order.begin(), order.end(), 2 * 1ll * ele) - order.begin();

            // now we need elements in range [ele_rank,nums.size()]
            // BIT used 1 based indexing
            ans += b.query(ele_rank + 1, nums.size());

            // update BIT
            int ele_index = lower_bound(order.begin(), order.end(), ele) - order.begin();

            b.update(ele_index + 1, 1);
        }

        return ans;
    }
};

int main()
{
#ifndef IO_FROM_FILE
    freopen("C:\\Users\\Dhruv\\OneDrive\\Documents\\CPP + DSA\\input.txt", "r", stdin);
    freopen("C:\\Users\\Dhruv\\OneDrive\\Documents\\CPP + DSA\\output.txt", "w", stdout);
#endif

    Solution obj;

    auto a = obj.reversePairs({-1, 3, 2, -3, 1, -9, -123, 98});

    cout << a << endl;

    return 0;
}