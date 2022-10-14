// //{ Driver Code Starts
// //Initial Template for C++

// #include <bits/stdc++.h>
// using namespace std;


// // } Driver Code Ends
// //User function Template for C++

// // return a string formed by compressing string s
// // do not print anything


// class Solution{

//     pair<int,int> longestRepeting(string s)
//     {
//         int start 



        
//     }

//     public:
//     string compress(string s)
//     {
//         // step 1 : finding longest possible repeating string
        

//     }
// };



// //{ Driver Code Starts.

// int main()
// {
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         string s;
//         cin>>s;
//         Solution obj;
//         cout<< obj.compress(s) << "\n";
//     }
//     return 0;
// }

// // } Driver Code Ends



//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution{
    
    public:
    vector<int> help_classmate(vector<int> arr, int n) 
    { 
        vector<int>ans;
        stack<int> st;
        st.push(-1);

        for (int i = n-1; i >= 0; i--)
        {
            while (arr[i] <= st.top())
            {
                st.pop();
            }

            ans.push_back(st.top());
            st.push(arr[i]);
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
		int n;
		cin>>n;
		vector<int> array(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>array[i];
		}
		Solution obj;
		vector<int> result = obj.help_classmate(array,n);
		for (int i = 0; i < n; ++i)
		{
			cout<<result[i]<<" ";
		}
		cout<<"\n";
	}
	return 0; 
}


// } Driver Code Ends