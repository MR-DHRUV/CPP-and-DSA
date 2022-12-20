//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 



// } Driver Code Ends


class Solution
{
public:
    int maxDistance(int arr[], int n)
    {
        // approach
        // we have to find maximum
        // |arr[i]-arr[j]| + | i-j |
        // since j >= i , we can say |i-j| = j-i

        // so our expression is
        // |arr[i]-arr[j]| + (j-i)
        // on removing mod we have 2 possibities

        // 1
        // arr[i]-arr[j] + (j-i) = (arr[i]-i) -(arr[j] - j)  
        // thus we need min and max values of arr[i]-i;

        // 
        // -(arr[i]-arr[j]) + (j-i) = -(arr[i]+i) + (arr[j]+j)  
        // thus we need min and max values of arr[i]+i;

        // p1 has to be maximised and p2 has to be minimised

        // base case
        if (n <= 1)
        {
            return 0;
        }

        // finding max  and min arr[i]+i
        int max1 = INT_MIN;
        int min1 = INT_MAX;

        // finding max and min arr[i]-i
        int max2 = INT_MIN;
        int min2 = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            max1 = max(max1, arr[i] + i);
            min1 = min(min1, arr[i] + i);

            max2 = max(max2, arr[i] - i);
            min2 = min(min2, arr[i] - i);
        }


        int ans = max(max1+min1,max2+min2);
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
	int T;
	cin>>T;
	while(T--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i = 0; i<n; i++)
	        cin>>arr[i];
	    Solution obj;
	    cout<<obj.maxDistance(arr, n)<<endl;
	}
} 

// } Driver Code Ends