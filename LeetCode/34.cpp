#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {

        int start = 0;
        int end = nums.size();

        vector<int> res = {-1, -1,};

    

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target)
            {

                if (res[0] == -1)
                {
                    res[0] = mid;
                    res[1] = mid;
                }

                // this is for least
                if (res[0] > mid)
                {
                    res[0] = mid;
                }

                end = mid - 1;
            }

            else if (nums[mid] > target)
            {
                end = mid - 1;
            }

            else
            {
                start = mid + 1;
            }
        }

        start = 0;
        end = nums.size();

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target)
            {

                // this is for max
                if (res[1] < mid)
                {
                    res[1] = mid;
                }

                start = mid + 1;
            }

            else if (nums[mid] > target)
            {
                end = mid - 1;
            }

            else
            {
                start = mid + 1;
            }
        }

        return res;
    }
};

vector<int> find(int arr[], int n, int x)
{
    int start = 0;
    int end = n-1;

    vector<int> res = {-1, -1};

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == x)
        {

            if (res[0] == -1)
            {
                res[0] = mid;
                res[1] = mid;
            }

            // this is for least
            if (res[0] > mid)
            {
                res[0] = mid;
            }

            end = mid - 1;
        }

        else if (arr[mid] > x)
        {
            end = mid - 1;
        }

        else
        {
            start = mid + 1;
        }
    }

    start = 0;
    end = n-1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == x)
        {

            // this is for max
            if (res[1] < mid)
            {
                res[1] = mid;
            }

            start = mid + 1;
        }

        else if (arr[mid] > x)
        {
            end = mid - 1;
        }

        else
        {
            start = mid + 1;
        }
    }

    return res;
}

// O(n) but we need O(logN);
// class Solution
// {
// public:
//     vector<int> searchRange(vector<int> &nums, int target)
//     {
//         vector<int> res = {-1 , -1};

//         for (int i = 0; i < nums.size(); i++)
//         {
//             if (nums[i] == target)
//             {
//                 if (res[0] == -1)
//                 {
//                     res[0] = i;
//                     res[1] = i;
//                 }

//                 if(i > res[1]){
//                     res[1] = i;
//                 }

//             }
//         }

//         return res;
//     }
// };

int main()
{

    vector<int> v = {1, 3, 4, 5, 3, 4, 5, 6};

    Solution obj;

    cout << (obj.searchRange(v, 3))[0] << endl;
    cout << (obj.searchRange(v, 3))[1] << endl;

    return 0;
}