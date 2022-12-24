//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++


class Solution
{
public:
    long long int wineSelling(vector<int> &arr, int N)
    {

        // sell -> +ve
        // buy-> -ve
        vector<pair<int,int>> buy ,sell; 

        // adding elements into vectors so that we can have position of next +ve / -ve in O(1) time

        for (int i = 0; i < N; i++)
        {
            // +ve
            if (arr[i] > 0)
            {
                sell.push_back(make_pair(i,arr[i]));
            }
            // -ve
            else if (arr[i] < 0)
            {
                buy.push_back(make_pair(i,arr[i]));
            }
        }

        auto p = sell.begin();
        auto n = buy.begin();

        long long int ans = 0;

        while (p != sell.end() && n != buy.end())
        {
            // cout<<p->first<<" "<<n->first<<endl;
            
            // +ve == -ve
            if (p->second == abs(n->second))
            {
                // calc work
                long long int w = abs(p->first - n->first) * abs(n->second);
                // cout<<w<<endl;
                ans += w;

                n->second = 0;
                p->second = 0;

                // moving -ve ans +ve to next position
                n++;
                p++;
            }
            else if (p->second > abs(n->second))
            {
                // calc work
                long long int w = abs(p->first - n->first) * abs(n->second);
                // cout<<w<<endl;
                ans += w;
                
                p->second -= abs(n->second); 
                n->second = 0;

                // moving -ve to next position
                n++;
            }
            else
            {
                // +ve < -ve

                // calc work
                long long int w = abs(p->first - n->first) * abs(p->second);
                // cout<<w<<endl;
                ans += w;
                
                // jitna mil gaya utna kam krdo
                n->second += p->second;
                p->second = 0;

                // moving +ve to next position
                p++;
            }
        }

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
        
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        long long int ans = ob.wineSelling(arr,n);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends


// 9
// 1000 1000 1000 -800 -400 -700 -600 -300 -200 