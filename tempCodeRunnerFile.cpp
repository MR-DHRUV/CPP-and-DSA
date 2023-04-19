//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    const int MOD = 1e9 + 7;
    vector<int> dp;

    // making n as root node
    long long solve(int N)
    {
        if (dp[N] != -1)
        {
            return dp[N];
        }
        if (N == 0 or N == 1)
        {
            return dp[N] = 1;
        }
        else
        {
            long long sum = 0;
            for (int i = 1; i <= N; i++)
            {
                sum = (sum + ((solve(i - 1) % MOD) * (solve(N - i) % MOD)) % MOD) % MOD;
            }
            return dp[N] = sum;
        }
    }

public:
    // Function to return the total number of possible unique BST.
    int numTrees(int n)
    {
        dp.resize(1001,-1);
        return solve(n);
    }
};

//{ Driver Code Starts.
#define mod (int)(1e9+7)
int main(){
    
    //taking total testcases
    int t;
    cin>>t;
    while(t--){
        
        //taking total number of elements
        int n;
        cin>>n;
        Solution ob;
        //calling function numTrees()
        cout<<ob.numTrees(n)<<"\n";
    }
}	
// } Driver Code Ends