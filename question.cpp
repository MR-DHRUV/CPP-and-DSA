//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
    unordered_set<string> st;
    string ans;

    set<string> st1;

    void gen1(string s, int i, int &n, int &k)
    {
        if (i == n)
        {
            st1.insert(s);
            return;
        }

        for (int j = 0; j < k; j++)
            gen1(s + char('0' + j), i + 1, n, k);
    }

    void gen(string s, int &k)
    {
        for (int i = 0; i < k; i++)
        {
            string nxt = s + char(i + '0');
            if (st.find(nxt) == st.end())
            {
            cout << nxt << endl;
                // cout << s << " " << i << endl;

                st.insert(nxt);
                ans.push_back(nxt.back());
                gen(nxt.substr(1), k);
            }
        }
    }

public:
    string findString(int n, int k)
    {
        string temp(n - 1, '0');
        ans = string(n - 1, '0');
        gen(temp, k);
        gen1("", 0, n, k);

        // ans.append(temp.begin(), temp.end());
        cout << ans << endl;

        for(auto &it : st1)
        {
            if(ans.find(it) == ans.npos)
            {
                cout << it << endl;
            }
            
        }

        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
#ifndef IO_FROM_FILE
    freopen("C:\\Users\\Dhruv\\OneDrive\\Documents\\CPP + DSA\\input.txt", "r", stdin);
    freopen("C:\\Users\\Dhruv\\OneDrive\\Documents\\CPP + DSA\\output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        Solution ob;
        string ans = ob.findString(N, K);
        int ok = 1;
        for (auto i : ans)
        {
            if (i < '0' || i > K - 1 + '0')
                ok = 0;
        }
        if (!ok)
        {
            cout << -1 << endl;
            continue;
        }
        unordered_set<string> st;
        for (int i = 0; i + N - 1 < ans.size(); i++)
        {
            st.insert(ans.substr(i, N));
        }
        int tot = 1;
        for (int i = 1; i <= N; i++)
            tot *= K;
        if (st.size() == tot)
        {
            cout << ans.size() << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}
// } Driver Code Ends