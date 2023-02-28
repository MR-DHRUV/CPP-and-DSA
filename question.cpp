//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class TrieNode
{
public:
    TrieNode *children[26];
    int prefixCount = 0;

    // check whether it contains the following key or not
    inline bool containsKey(char ch)
    {
        return children[ch - 'a'] != NULL;
    }

    // get specific children
    inline TrieNode *get(char ch)
    {
        return children[ch - 'a'];
    }

    // set a children
    inline void set(TrieNode *n, char ch)
    {
        children[ch - 'a'] = n;
    }
};

class Solution
{
public:
    vector<int> prefixCount(int N, int Q, string li[], string query[])
    {
        TrieNode *root = new TrieNode();

        for (int j = 0; j < N; j++)
        {
            TrieNode *temp = root;
            string s = li[j];

            for (int i = 0; i < s.length(); i++)
            {
                // if not present just put node
                if (!temp->containsKey(s[i]))
                {
                    temp->set(new TrieNode(), s[i]);
                }

                // point temp to next child
                temp = temp->get(s[i]);
                temp->prefixCount++;
            }
        }

        vector<int> ans(Q, 0);

        for (int j = 0; j < Q; j++)
        {
            TrieNode *temp = root;
            bool isAns = true;

            for (int i = 0; i < query[j].length(); i++)
            {
                // if not present just return 0
                if (!temp->containsKey(query[j][i]))
                {
                    isAns = false;
                    ans[j] = 0;
                    break;
                }

                // point temp to next child
                temp = temp->get(query[j][i]);
            }

            if (isAns)
            {
                ans[j] = temp->prefixCount;
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    // disable default 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // set our properties
    #ifndef IO_FROM_FILE
    freopen("C:\\Users\\Dhruv\\OneDrive\\Documents\\CPP + DSA\\input.txt","r",stdin);
    freopen("C:\\Users\\Dhruv\\OneDrive\\Documents\\CPP + DSA\\output.txt","w",stdout);
    #endif

    int t;
    cin >> t;
    while (t--)
    {
        int Q, N, i = 0, x;
        cin >> N;
        string s;
        string li[N];
        for (int i = 0; i < N; i++)
            cin >> li[i];
        cin >> Q;
        x = Q;
        string query[Q];
        while (Q--)
        {
            cin >> s;
            query[i++] = s;
        }

        Solution ob;
        vector<int> ans = ob.prefixCount(N, x, li, query);
        for (auto i : ans)
            cout << i << "\n";
    }
    return 0;
}
// } Driver Code Ends