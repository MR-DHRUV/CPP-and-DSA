//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX], int n, int m, int k)
    {

        vector<int> ans;

        int rs = 0;
        int re = n - 1;

        int cs = 0;
        int ce = m - 1;

        while (rs <= re && cs <= ce)
        {

            // left to right
            for (int i = cs; i <= ce; i++)
            {
                ans.push_back(a[rs][i]);
            }
            rs++;

            // top to bottom
            for (int i = rs; i <= re; i++)
            {
                ans.push_back(a[i][ce]);
            }
            ce--;

            if (rs <= re)
            {
                for (int i = ce; i >= cs; i--)
                {
                    ans.push_back(a[re][i]);
                }
                re--;
            }

            if (cs <= ce)
            {
                for (int i = re; i >= rs; i--)
                {
                    ans.push_back(a[i][cs]);
                }
                cs++;
            }
        }

        return ans[k - 1];
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n, m;
        int k = 0;
        // cin>>k;
        cin >> n >> m >> k;
        int a[MAX][MAX];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j];
            }
        }
        Solution ob;
        cout << ob.findK(a, n, m, k) << endl;
    }
}
// } Driver Code Ends