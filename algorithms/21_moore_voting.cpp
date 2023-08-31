#include <bits/stdc++.h>
using namespace std;

// this is an algo to find majority element in an array
// an element is said to be majority iff it occurs atlest n/2+1 times
// based on normalised voting
int majorityElement(vector<int> &nums)
{
    int ele = -1, count = 0;
    // count is the number of normalised votes

    for (int i = 0; i < nums.size(); i++)
    {
        if (count == 0)
        {
            ele = nums[i];
            count++;
        }
        else if (nums[i] == ele)
            count++;
        else
            count--;
    }

    // now we have maximum occuring element in the array
    count = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == ele)
            count++;
    }

    if (count > nums.size() / 2)
        return ele;

    return -1;
}

int main()
{

    return 0;
}