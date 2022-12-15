#include<bits/stdc++.h>
using namespace std;


int kadane(vector<int> arr)
{
    int maxE = arr[0];
    int sum = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        // make sum
        sum += arr[i];

        // update ans
        maxE = max(maxE,sum);

        // if sum is negitive, make it 0 as we will not concider that element;
        if(sum < 0)
        {
            sum = 0;
        }
    }

    return maxE;
    
}


int main()
{
    // kadane's algorithm
    // used to find contiguos subarray with maximun sum in O(N) 
    


    return 0;
}