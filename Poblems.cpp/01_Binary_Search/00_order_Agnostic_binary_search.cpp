#include <iostream>
#include <vector>
using namespace std;

int orderAgnosticBinarysearch(vector<int> arr, int target, int start, int end)
{
    if (arr[0] <= arr[arr.size() - 1])
    {
        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (arr.get(m == target)
            {
                return mid;
            }

            else if (arr.get(m > target)
            {
                end = mid - 1;
            }

            else
            {
                start = mid + 1;
            }

        }
    }
}

int main()
{

    return 0;
}