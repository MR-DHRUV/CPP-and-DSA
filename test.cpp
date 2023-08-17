#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct segtree
{

   int size;
   vector<int> sums;

   void init(int n)
   {
      size = 1;
      while (size < n)
         size *= 2;
      sums.assign(2 * size, 0);
   }

   void change(int i, int v, int x, int lx, int rx)
   {
      if (rx - lx == 1)
      {
         sums[x] += v;
         return;
      }
      int m = (lx + rx) / 2;
      if (i < m)
         change(i, v, 2 * x + 1, lx, m);
      else
         change(i, v, 2 * x + 2, m, rx);
      sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
   }
   void change(int i, int v)
   {
      change(i, v, 0, 0, size);
   }

   int calc(int l, int r, int x, int lx, int rx)
   {
      if (lx >= l && rx <= r)
         return sums[x];
      if (rx <= l || lx >= r)
         return 0;
      int m = (lx + rx) / 2;
      return calc(l, r, 2 * x + 1, lx, m) + calc(l, r, 2 * x + 2, m, rx);
   }
   int calc(int l)
   {
      return calc(l, size, 0, 0, size);
   }
};

int main()
{
   #ifndef IO_FROM_FILE
       freopen("C:\\Users\\Dhruv\\OneDrive\\Documents\\CPP + DSA\\input.txt", "r", stdin);
       freopen("C:\\Users\\Dhruv\\OneDrive\\Documents\\CPP + DSA\\output.txt", "w", stdout);
   #endif

   int n, m;
   cin >> n >> m;

   vector<int> a(n);

   for (int i = 0; i < n; ++i)
      cin >> a[i];

   while (m--)
   {
      int op;
      cin >> op;

      if (op == 1)
      {

         int x, y;
         cin >> x >> y;

         x -= 1;

         segtree st;
         st.init(40);

         int sum = 0;

         for (int i = x; i < y; ++i)
         {
            int val = a[i];
            sum += st.calc(val);
            st.change(val - 1, 1);
         }

         cout << sum << "\n";
      }
      else
      {
         int x, y;
         cin >> x >> y;
         a[x - 1] = y;
      }
   }

   return 0;
}