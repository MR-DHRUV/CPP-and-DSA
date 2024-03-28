//{ Driver Code Starts
// C++ program to find largest subarray sum with
// at-least k elements in it.
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    long long int maxSumWithK(long long int a[], long long int n, long long int k)
    {
        // 2 core approaches
        // I can move a window of size K , say currently window is from i to j, then I can add the maximum subarray sum till index i-1
        // to find the max subarray sum till any index I can use Kadane
        // 2*O(N)

        // In the previous case I have suffixed the window, Now I will try to prefix it
        // We will slide a window of size K
        // and now we can check either previous_max + next element or current window yeilds the largest sum
        // the proceess of adding next elements lets us make bigger windows
        // it is ensured that the windows are contigous as eiher next element is added to the last k'sized window or an previous larger window
        // O(N), single traversal

        long long int sum = 0, ans , prev;

        for (int i = 0; i < k; i++)
            sum += a[i];

        ans = sum;
        prev = sum;

        for (int i = k; i < n; i++)
        {
            sum += a[i] - a[i - k];
            prev = max(prev + a[i], sum); // sum is of current k'sized window
            // ans ans+a[i] is of previous max window ending at i-1
            ans = max(ans, prev);
        }

        return ans;
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
    long long int t;
    cin >> t;
    while (t--)
    {
        long long int n, k, i;
        cin >> n;
        long long int a[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cin >> k;
        Solution ob;
        cout << ob.maxSumWithK(a, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends