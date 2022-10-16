//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


// } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       //Your code here
        int start = 0;
        int storage = 0;
        int ft = 0;
        int dt = 0;

        for (int i = 0; i < n; i++)
        {
            ft += p[i].petrol;
            dt += p[i].distance;
            
            
            // checking id travel is possible or not

            // if possible
            if (p[i].petrol - p[i].distance + storage >= 0)
            {
                storage += p[i].petrol - p[i].distance;
            }
            else
            {
                // +1 isilliye hua kyuki current wala possible nahi haii
                start = i+1;

                // reset the storage
                storage = 0;
            }
        }
        
        
        // at any cost the total distance must be less than or equal to total fuel
        if (start >= n || dt > ft)
        {
            return -1;
        }

        return start;
       
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
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}

// } Driver Code Ends