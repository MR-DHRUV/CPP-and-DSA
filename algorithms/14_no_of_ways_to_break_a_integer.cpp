//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    int waysToBreakNumber(int N)
    {
        // formulae
        // no of ways = (n+1)(n+2)/2
        long long int mod = 1e9 + 7;

        long long int ans = (((N + 1) * (N + 2)) / 2 )% mod;

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
        int N;
        cin >> N;
        Solution ob;
        cout << ob.waysToBreakNumber(N) << endl;
    }
    return 0;
}
// } Driver Code Ends