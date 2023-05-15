//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    // precomputing

    const int mod = 1e9 + 7;
    vector<int> mp;

    Solution()
    {
        vector<int> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29}; /// 10 primes in range 2-30
        mp.resize(31);

        for (int i = 0; i <= 30; i++)
        {
            // rejecting numbers which in range 2-30 which have more than one occurance of a single prime no
            // see we have to onl;y check for 2 3 5 as next prime is 7 and 7*7 is 41
            if (i % 4 == 0 || i % 9 == 0 || i % 25 == 0)
            {
                mp[i] = 0;
                continue;
            }

            int mask = 0;

            for (int j = 0; j < 10; j++)
            {
                if (i % prime[j] == 0)
                {
                    mask = mask | (1 << j); // setting jth bit as a indication that the number i contains prime[j]
                }
            }

            mp[i] = mask;
        }
    }

    // calculates 2^n using exponenciation
    long pow2(int n)
    {
        long ans = 1, m = 2;

        while (n != 0)
        {
            if (1 == (n & 1))
                ans = (ans * m) % mod;

            m = m * m % mod;
            n >>= 1;
        }

        return ans;
    }

    int goodSubsets(vector<int> &arr, int n)
    {
        // dp se krenge in this way

        // dp[n][1024]
        // n to represent that we are at index i
        // ans 1024 is mask and will be used in such a way
        // primes from 1 to 30 excluding 1 : 2 3 5 7 11 ...

        // if mask is
        // 1101
        // 7532

        // means we have included 2,5,7 in our product

        // primes in range 2-30 are 2, 3, 5, 7, 11, 13, 17, 19, 23, 29
        // 10 primes
        // no bits required to represent mask = 10
        // maximum number = 2^10 = 1024

        // say current mask is 1010 and current element is 10
        // rep of 10 as primes : 0101

        // we can take current no for current product iff they dont have any prime in comman
        // we will and both masks and check if result is 0 or not
        // if not zero then we cant take it

        // next mask will be current mask | rep of current no

        // for 1
        // we will multiply the final ans by 2^no of 1's to get all subsets that can contain 1 as a subset may or may not contain that 1

        int cntOne = 0;
        vector<int> dp(1024), cnt(31);
        dp[0] = 1;

        // counting the frequency of all valid numbers
        for (int i : arr)
        {
            if (i == 1)
                cntOne++;
            else if (mp[i] != 0)
                cnt[i]++;
        }

        // start tabulation
        for (int i = 2; i < 31; i++)
        {
            if (cnt[i] == 0)
                continue;

            for (int j = 0; j < 1024; j++)
            {
                if ((mp[i] & j) != 0)
                    continue; // this prime no cant be included

                // next index = prev value + exclude case(prev value of dp[j])
                dp[j | mp[i]] = (dp[j | mp[i]] + (dp[j] * 1ll * cnt[i])) % mod;
            }
        }

        long long ans = -1;
        for (int i : dp)
            ans = (ans + i) % mod;

        if (cntOne > 0)
            ans = (ans * pow2(cntOne)) % mod;

        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        Solution ob;
        cout<<ob.goodSubsets(a, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends