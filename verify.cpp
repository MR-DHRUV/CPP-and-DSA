//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{

public:
    int noConseBits(int n)
    {
        // for max value starting from msb as we dont want msb to be 0

        int count = 0;

        for (int i = 31; i >= 0; i--)
        {
            int bit = (n >> i) & 1;

            if (bit == 1)
            {
                count++;
            }
            else
            {
                count = 0;
            }

            if (count == 3)
            {
                n = n ^ (1 << i); // make this bit 0
            }
        }

        return n;
    }
};

//{ Driver Code Starts.

int main()
{

    int tt;
    cin >> tt;
    Solution sol;
    while (tt--)
    {

        int n;
        cin >> n;
        int ans = sol.noConseBits(n);
        cout << ans << '\n';
    }

    return 0;
}

// } Driver Code Ends