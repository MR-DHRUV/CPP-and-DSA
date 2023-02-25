//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++



class Solution{   
public:
    int maxSubarrayXOR(int N, int arr[]){    
        
        // kadane approach 
        int ans = 0;
        int last = 0;
        int zor = 0;
        
        // forward loop
        for(int i = 0 ; i < N ; i++)
        {
            last = zor;
            zor = zor ^ arr[i];
            
            if(last > zor || arr[i] > zor)
            {
                zor = arr[i];
            }
            
            ans = max(ans,zor);
        }
        
        // reverse loop
        zor = 0;
        last = 0;
        for(int i = N-1 ; i >= 0 ; i--)
        {
            last = zor;
            zor = zor ^ arr[i];
            
            if(last > zor || arr[i] > zor)
            {
                zor = arr[i];
            }
            
            ans = max(ans,zor);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, X;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.maxSubarrayXOR(N, arr) << endl;
    }
    return 0; 
} 

// } Driver Code Ends