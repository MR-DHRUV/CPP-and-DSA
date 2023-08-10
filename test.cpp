#include <iostream>
#include <vector>
using namespace std;
long long segtree[400002];
bool lazy[400002];

// add val to array[idx], idx is from left to right inclusive both sides
void updateRangeLazy(int node, int start, int end, int left, int right)
{
   if (lazy[node])
   {                                                     // update this node
      segtree[node] = (end - start + 1) - segtree[node]; // myself
      if (start != end)
      {
         lazy[node * 2] = !lazy[node * 2];
         lazy[node * 2 + 1] = !lazy[node * 2 + 1];
      }
      lazy[node] = false;
   }
   if (right < start or left > end)
   { // this node is completely outside the range of query
      return;
   }

   if (start >= left and end <= right) // I am completely inside the range of update
   {
      segtree[node] = (end - start + 1) - segtree[node];
      if (start != end)
      {
         lazy[node * 2] = !lazy[node * 2];
         lazy[node * 2 + 1] = !lazy[node * 2 + 1];
      }
      return;
   }
   int mid = (start + end) / 2;
   updateRangeLazy(node * 2, start, mid, left, right);
   updateRangeLazy(node * 2 + 1, mid + 1, end, left, right);

   segtree[node] = segtree[node * 2] + segtree[node * 2 + 1];
}

long long queryLazy(int node, int start, int end, int left, int right)
{
   if (right < start or left > end)
   { // this node is completely outside the range of query
      return 0;
   }
   if (lazy[node])
   {                                                     // update this node
      segtree[node] = (end - start + 1) - segtree[node]; // myself
      if (start != end)
      {
         lazy[node * 2] = !lazy[node * 2];
         lazy[node * 2 + 1] = !lazy[node * 2 + 1];
      }
      lazy[node] = false;
   }
   if (start >= left and end <= right)
   { // this node is completely inside the range of query
      return segtree[node];
   }
   int mid = (start + end) / 2;
   return queryLazy(node * 2, start, mid, left, right) +
          queryLazy(node * 2 + 1, mid + 1, end, left, right);
}

int main()
{
#ifndef IO_FROM_FILE
   freopen("C:\\Users\\Dhruv\\OneDrive\\Documents\\CPP + DSA\\input.txt", "r", stdin);
   freopen("C:\\Users\\Dhruv\\OneDrive\\Documents\\CPP + DSA\\output.txt", "w", stdout);
#endif

   int n;
   cin >> n;
   int q;
   cin >> q;
   while (q--)
   {
      int a;
      int b, c;
      cin >> a >> b >> c;
      if (a == 1)
      {
         cout << queryLazy(1, 0, n - 1, b, c) << endl;
      }
      else
      {
         updateRangeLazy(1, 0, n - 1, b, c);
      }
   }
}