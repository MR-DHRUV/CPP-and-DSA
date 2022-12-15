//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends

class Solution
{

public:
    vector<int> findRange(string str, int n)
    {
        // using kadane

        vector<int> ans(2);
        ans[0] = -1;

        int start = 0;
        int end;

        int maxE = 0;
        int sum = 0;

        int prevMax = 0;

        for (int i = 0; i < n; i++)
        {
            int e = str[i] == '0' ? 1 : -1;

            sum += e;
            maxE = max(sum, maxE);

            if (maxE > prevMax)
            {
                // update ans whenever we find a greater sum
                ans[0] = start;
                ans[1] = end;
            }

            if (sum < 0)
            {
                sum = 0;
                start = i;
                end = i;
            }
        }

        if (ans[0] == -1)
        {
            ans.pop_back();
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        Solution ob;
        auto ans = ob.findRange(s, n);

        if (ans.size() == 1)
        {
            cout << ans[0] << "\n";
        }
        else
        {
            cout << ans[0] << " " << ans[1] << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends