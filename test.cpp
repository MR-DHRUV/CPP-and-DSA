#include <bits/stdc++.h>
#define ll long long int
#define MAX 810000
#define mat vector<vector<ll>>

using namespace std;

class SegTree
{
   mat seg[MAX];
   ll size;
   ll mod;

   mat multiply(const mat &a, const mat &b)
   {
      mat res(2, vector<ll>(2, 0));

      res[0][0] = (a[0][0] * b[0][0] + a[0][1] * b[1][0]) % mod;
      res[0][1] = (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % mod;
      res[1][0] = (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % mod;
      res[1][1] = (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % mod;

      return res;
   }

   void build(ll idx, ll low, ll high)
   {
      if (low == high)
      {
         cin >> seg[idx][0][0] >> seg[idx][0][1] >> seg[idx][1][0] >> seg[idx][1][1];
         return;
      }

      ll m = (low + high) / 2;
      build(2 * idx + 1, low, m);
      build(2 * idx + 2, m + 1, high);

      // multiply matrices
      seg[idx] = multiply(seg[2 * idx + 1], seg[2 * idx + 2]);
   }

   mat queryHelper(ll idx, ll low, ll high, ll &l, ll &r)
   {
      if (low >= l && high <= r)
         return seg[idx];

      ll mid = (low + high) / 2;
      bool a = true, b = true;
      mat left, right;

      if (!(low > r || mid < l))
         left = queryHelper(2 * idx + 1, low, mid, l, r);
      else
         a = false;
      if (!(mid + 1 > r || high < l))
         right = queryHelper(2 * idx + 2, mid + 1, high, l, r);
      else
         b = false;

      if (!a)
         return right;
      else if (!b)
         return left;

      return multiply(left, right);
   }

public:
   SegTree(ll n, ll r)
   {
      mod = r;
      size = n - 1;
      build(0, 0, size);
   }

   mat query(ll &l, ll &r)
   {
      return queryHelper(0, 0, size, l, r);
   }
};

int main()
{
   ll r, n, m;
   scanf("%lld%lld%lld", &r, &n, &m);
   SegTree st(n, r);

   ll a, b;
   while (m--)
   {
      scanf("%lld%lld", &a, &b);

      mat ans = st.query(--a, --b);

      printf("%lld %lld\n", ans[0][0], ans[0][1]);
      printf("%lld %lld\n\n", ans[1][0], ans[1][1]);
   }

   return 0;
}
