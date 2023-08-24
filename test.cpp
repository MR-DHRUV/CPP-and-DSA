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
      order.erase(unique(order.begin(), order.end()), order.end());

      int ans = 0;

      BIT b(nums.size() + 1);

      for (int i = 0; i < nums.size(); i++)
      {
         int &ele = nums[i];
         int ele_rank = upper_bound(order.begin(), order.end(), 2 * 1ll * ele) - order.begin();

         ans += b.query(ele_rank + 1, nums.size());

         int ele_index = lower_bound(order.begin(), order.end(), ele) - order.begin();
         b.update(ele_index + 1, 1);
      }

      return ans;
   }
};