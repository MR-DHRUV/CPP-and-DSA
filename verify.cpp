//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // Function to count subarrays with sum equal to 0.
    long long int findSubarray(vector<long long int> &arr, int n)
    {

        // Approach
        // convert the array into prefix sum arr
        // if a no appear more than once in prefix sum that means there are elements between their occruances that sum up to 0;

        // 0 1 2 3 4 5 6  7 8 index
        // 1 2 3 -5 6 9 -12 3
        // 1 3 6 1 7 16  4  1

        // 1->3
        // 4->7
        // 1->7
        // these are 3 subarrays with 0 sum, that is we are no including the index of first occurance and we start out sum from occurance+1 till the next occurance
        // but in case our prefix sum is 0 then we need to include 1st index also

        // 1 is 3 times
        // No we cant directly say that there will be 2 subarrays with 0 sum
        // with N length we can have (N)*(N-1) /2 subarrays

        // if we have prefix sum = 0;
        // then we need to include

        long long int ans;
        long long int sum = 0;
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            mp[sum]++;
        }

        for (auto it : mp)
        {
            int x = it.second;

            if (it.first == 0)
            {
                x = (x) * (x + 1) / 2;
                ans += x;
            }
            else
            {
                x = x * (x - 1) / 2;
                ans += x;
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n; // input size of array

        vector<long long int> arr(n, 0);

        for (int i = 0; i < n; i++)
            cin >> arr[i]; // input array elements
        Solution ob;
        cout << ob.findSubarray(arr, n) << "\n";
    }
    return 0;
}
// } Driver Code Ends