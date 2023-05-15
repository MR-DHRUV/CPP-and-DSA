//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
public:
    long long countBits(long long N)
    {
        // say for 3rd bit which corresponds to 2^2 = 4
        /*
         0        0     0        0
         0        0     0        1
         0        0     1        0
         0        0     1        1
         0        1     0        0
         0        1     0        1
         0        1     1        0
         0        1     1        1
        */

        // we can say bits are repeating in a fashion
        // for ith bit first 2^i times bit is 0 and other 2^i times it is 1

        long long ans = 0;

        int a = 1;
        int b = 1 << a; // for calculating powers of 2

        for (int i = 0; i < 31; i++)
        {
            // N/2^i gives the no of intervals (no of sets of 0 + no of sets of 1)
            // thus no of intervals having 1s = N/2^i+1 that's why we have started from b = 2
            // a is the interval length
            // at each step interval length doubles
            // this does not count for partial intervals as thay are lost in division by powers of 2 
            ans += (N / b) * a;

            // for partial interval lost in division by 2
            // N%b gives the size of partial interval
            // subtraction of a gives the count of 1's as an interval will first have a 0's then a 1's.
            int curr = (N % b) - a + 1;
            ans += max(curr,0);

            // multiply by 2
            a <<= 1;
            b <<= 1;
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        long long N;
        scanf("%lld",&N);
        
        Solution obj;
        long long res = obj.countBits(N);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends