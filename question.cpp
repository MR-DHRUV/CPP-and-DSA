//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    long long maxGcd(int N)
    {
        // N and N-1 will be there in the answer as they have gcd = 1
        long long int ans = (N)*(N-1);
        
        // finding a number that has gdc =1 with ans

        // maintain a count as we need only 2 numbers
        int count = 0;

        for (long long int i = N-2; i >= 0 && count < 3; i--)
        {
            if(__gcd(ans,i) == 1)
            {
                ans = ans*i;
                count++;
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
        int N;
        cin >> N;
        Solution ob;
        cout << ob.maxGcd(N) << "\n";
    }
}
// } Driver Code Ends