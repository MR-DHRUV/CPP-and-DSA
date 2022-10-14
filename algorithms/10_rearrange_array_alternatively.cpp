//{ Driver Code Starts
// C++ program to rearrange an array in minimum 
// maximum form 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
public:
    // This function wants you to modify the given input
    // array and no need to return anything
    // arr: input array
    // n: size of array
    // Function to rearrange  the array elements alternately.
    void rearrange(long long *arr, int n)
    {
        // https://www.interviewbit.com/blog/rearrange-array-alternately/

        int min_index = 0;
        int max_index = n-1;
        int max = arr[n-1] + 1;


        for (int i = 0; i < n; i++)
        {
            //even inder par large lagana haii 
            if(i%2 == 0)
            {
                arr[i] = arr[i] + ((arr[max_index]%max)*max );
                max_index--;
            }
            else
            {
                arr[i] = arr[i] + ((arr[min_index]%max)*max );
                min_index++;
            }
        }

        // decoding and obtaining all required elements
        // humne upar wale code se har index pr wo element jo tha aur jo waha lagega ek code ki form me store kara dia 
        // hume max aur min index wale element ko decode krna haii 
        // so to decode element which is %max)*max  we divide by max element  
        // so to decode element which is %max)*max  we divide by max element while to decode added alement that is arr[i] we do %max element

        for (int i = 0; i < n; i++)
        {
            arr[i] = arr[i] / max;
        }
         
        

    }
};




//{ Driver Code Starts.

// Driver program to test above function 
int main() 
{
    int t;
    
    //testcases
    cin >> t;
    
    while(t--){
        
        //size of array
        int n;
        cin >> n;
        
        long long arr[n];
        
        //adding elements to the array
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        Solution ob;
        
        //calling rearrange() function
        ob.rearrange(arr, n);
        
        //printing the elements
        for (int i = 0; i < n; i++) 
		    cout << arr[i] << " ";
		
		cout << endl;
    }
	return 0; 
} 

// } Driver Code Ends