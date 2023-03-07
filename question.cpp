//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class TrieNode
{
public:
// to change from lowercase to uppercase in just one change
#define baseLetter 'a'

    // children
    TrieNode *children[26];
    bool isTerminal = false;

    // check whether it contains the following key or not
    bool containsKey(char ch)
    {
        return children[ch - baseLetter] != NULL;
    }

    // get specific children
    TrieNode *get(char ch)
    {
        return children[ch - baseLetter];
    }

    // set a children
    void set(TrieNode *n, char ch)
    {
        children[ch - baseLetter] = n;
    }
};

class Trie
{
    TrieNode *root;

public:
    Trie() { root = new TrieNode(); }

    void insert(const string &s, const int &start)
    {
        TrieNode *temp = root;

        for (int i = start; i < s.length(); i++)
        {
            // if not present just put node
            if (!temp->containsKey(s[i]))
            {
                temp->set(new TrieNode(), s[i]);
            }

            // point temp to next child
            temp = temp->get(s[i]);
        }

        temp->isTerminal = true;
    }

    void solve(TrieNode *node, int &ans, const string &s, int start)
    {
        if (node == NULL)
        {
            return;
        }

        if (start == s.size())
        {
            ans++;
            return;
        }

        if (s[start] == '?')
        {
            // try to match and make a word
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                if (node->containsKey(ch))
                {
                    solve(node->get(ch), ans,s,start+1);
                }
            }
        }
        else
        {
            if (node->containsKey(s[start]))
            {
                solve(node->get(s[start]), ans, s, start + 1);
            }
            else
            {
                ans = 0;
                return;
            }
        }
    }

    int match(const string &s)
    {
        int ans = 0;
        solve(root, ans, s, 0);
        return ans;
    }
};

vector<int> wildcardQueries(int n, int l, vector<string> &dictionary, int q, vector<string> &query)
{
    Trie *t = new Trie();

    for (int i = 0; i < n; i++)
    {
        t->insert(dictionary[i]);
    }

    vector<int> ans;

    for (int i = 0; i < q; i++)
    {
        ans.push_back(t->match(query[i]));
    }

    return ans;
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        string arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution ob;
        vector<string> ans = ob.findPrefixes(arr, n);

        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";

        cout << "\n";
    }

    return 0;
}

// } Driver Code Ends