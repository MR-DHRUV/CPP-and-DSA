#include <iostream>
#include <vector>

using namespace std;

// mountain arr : inc then dec
// cant contain duplicates

// approach
// when we are at middle we can find wheater we are in increasing or in decreasing part
// so change start / end accordingly

int mountainArrMaxBin(vector<int> arr)
{

    int start = 0;
    int end = arr.size() - 1;

    // index
    int max = 0;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] > arr[max])
        {
            max = mid;

        };

        if (arr[mid + 1] > arr[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return max;
}

int mountainArrMaxBinEffi(vector<int> arr)
{

    int start = 0;
    int end = arr.size() - 1;

    int maxI = 0;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if( arr[mid] > arr[maxI] ){
            maxI = mid;
        };

        if(arr[mid] > arr[mid+1]){
            end = mid - 1;
        }
        else if(arr[mid] < arr[mid+1]){
            start = mid +1;
        }
    }

    return maxI;
}



int main()
{

    vector<int> arr = {2, 3, 4, 5, 6, 7, 3, 4};

    cout << mountainArrMaxBin(arr) << endl;
    cout << mountainArrMaxBinEffi(arr) << endl;

    return 0;
}


class Solution {
public:
    int findPeakElement(vector<int>& nums) {
    
    int start = 0;
    int end = nums.size() - 1;

    // index
    int max = 0;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (nums[mid] > nums[max])
        {
            max = mid;

        };

        if (nums[mid + 1] > nums[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return max;
    }
};