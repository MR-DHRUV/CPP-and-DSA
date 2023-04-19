//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Here we are greedily selecting a activity/meeting

        // A meeting that end first should start first and as it ends first it should be started first\
        // sorting all the meetings on the basis of end time

        vector<pair<int, int>> m;

        for (int i = 0; i < n; i++)
        {
            m.push_back({end[i], start[i]});
        }

        sort(m.begin(), m.end());

        int ans = 0;
        int lastEnd = -1;

        for (int i = 0; i < n; i++)
        {
            if (m[i].second > lastEnd)
            {
                ans++;
                lastEnd = m[i].first;
            }
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
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends