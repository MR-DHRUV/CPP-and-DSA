#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
class BIT
{
    ll *bit;
    ll size;

public:
    BIT(ll n) : size(n + 1)
    {
        bit = new ll[n + 2]{0ll};
    }

    void update(ll i, ll val)
    {
        ++i;
        for (; i <= size; i += (i & (-i)))
        {
            bit[i] += val;
        }
    }

    ll sum(ll i)
    {
        ++i;
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
    int countRangeSum(vector<int> &nums, int lower, int upper)
    {
        // we will do prefix sum on nums;
        // now for any prefix sum we need count of elements that can be subtracted from prefixSum[i] to make it fall in range

        // let x be an element that must be subtracted from prefixSum[i] to make it lie in lower range

        // lower = prefixSum[i] -x
        // x = prefixSum[i] - lower
        // y = prefixSum[i] - upper

        // so wee need count of prefix sums that lie in range [y,x] as y < x
        // can be done using multiset as well as seg tree / bit as well as sq root decomposition

        vector<ll> prefixSum(nums.size() + 1);
        prefixSum[0] = 0; // 0 sum toh haii hi humare pass

        for (int i = 0; i < nums.size(); i++)
        {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        // indexing
        vector<ll> sums(prefixSum.begin(), prefixSum.end());
        sort(sums.begin(), sums.end());

        BIT b(prefixSum.size() + 1);
        int ans = 0;

        for (int i = 0; i < prefixSum.size(); i++)
        {
            ll &sum = prefixSum[i];

            int idx = lower_bound(sums.begin(), sums.end(), sum) - sums.begin();
            int start_idx = lower_bound(sums.begin(), sums.end(), sum - upper) - sums.begin();
            int end_idx = upper_bound(sums.begin(), sums.end(), sum - lower) - sums.begin() - 1;

            ans += b.query(start_idx, end_idx);

            b.update(idx, 1);
        }

        return ans;
    }
};

int main()
{

    return 0;
}