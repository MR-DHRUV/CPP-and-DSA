#include <bits/stdc++.h>
using namespace std;

void printArr(vector<int> arr)
{
  for (int i = 0; i < arr.size(); i++)
  {
    cout << arr[i] << " ";
  }

  cout << endl;
}

int main()
{
  vector<int> max_heap = {30, 20, 15, 5, 10, 12, 6};
  /*
              30
            /   \
          20     15
         / \    /  \
        5  10  12   6
  */

  // how it looks

  int element = 40;

  // process of insertion
  // 1 add it to first available space, so that there will be no black spaces in the array
  // 2 compare 40 with its parent and swap while parent is small

  // 1
  max_heap.push_back(element);
  /*
              30
            /   \
          20     15
         / \    /  \
        5  10  12   6
      /
     40
  */

  // 2
  int i = max_heap.size() - 1;

  // complexity : O(logN)
  while (i / 2 >= 0)
  {
    int parent_index = i / 2;

    if (max_heap[i] > max_heap[parent_index])
    {
      swap(max_heap[parent_index], max_heap[i]);
      i = parent_index;
    }
    else
    {
      break;
    }
  }
  /*
              40
            /   \
          30     15
         / \    /  \
        20  10  12   6
      /
     5
  */

  printArr(max_heap);

  return 0;
}