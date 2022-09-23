//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    vector<int> twoOddNum(int arr[], int N)
    {
        // code here
        vector<int> res;

        int ans = arr[0];

        for (int i = 1; i < N; i++)
        {
            // XOR operation
            ans = ans ^ arr[i];
        }

        // cout << ans << endl;
        // cout << (5 ^ 1) << endl;

        int ans1 = 0;
        int ans2 = 0;

        // we will first obtain right most set bit of above XOR using formula
        int rightSetBit = ans & (~(ans-1));

        // now we will maintain 2 buckets
        // In one bucket we will collect elements havling a set bit equal to right set bit of xor so that we can filter out elements

        // like hume 5^1 me se 5 nikalna haii so 5 bucket 1 me gaya aur aur 1 bucket 2 me
        // agar koi element bucket 1 me jayga like 2 toh dusra 2 bhi ussi me jayga, so bucket ka xor karao


        for (int i = 0; i < N; i++)
        {
            if((arr[i]&rightSetBit) == 1)
            {
                ans1 = ans1^arr[i];
            }

            else
            {
                ans2 = ans2^arr[i];
            }
        }
         
        res.push_back(max(ans1,ans2));
        res.push_back(min(ans1,ans2));

        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int Arr[N];
        for (int i = 0; i < N; i++)
            cin >> Arr[i];
        Solution ob;
        vector<int> ans = ob.twoOddNum(Arr, N);
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends