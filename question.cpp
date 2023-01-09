//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class TrieNode
{
public:
    char data;
    int childCount;

    TrieNode *children[26];
    bool isTerminal;

    // constructors
    TrieNode(){};
    TrieNode(char ch) : data(ch), isTerminal(false), childCount(0)
    {
        // init children with NULL
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
    };
    TrieNode(char ch, bool terminal) : data(ch), isTerminal(terminal), childCount(0)
    {
        // init children with NULL
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
    };
};

class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode('\0');
    };

    void insert(string word);
    vector<string> suggest(string word);
};

void insertRec(TrieNode *root, string s)
{
    if (s.length() == 0)
    {
        root->isTerminal = true;
        return;
    }

    int index = s[0] - 'a';

    TrieNode *child;

    if (root->children[index] != NULL)
    {
        child = root->children[index];
    }
    else
    {
        child = new TrieNode(s[0]);
        root->children[index] = child;
        root->childCount++;
    }

    insertRec(child, s.substr(1));
}

void Trie::insert(string word)
{
    insertRec(root, word);
}

// intensively reccursive function: mne bnaya haii not that optimised
void getAllwords(TrieNode *root, vector<string> &suggesions, string prefix)
{
    // traverse all the childrens
    for (int i = 0; i < 26; i++)
    {

        if (root->children[i] != NULL)
        {
            string p = prefix;
            p.push_back(root->children[i]->data);

            if (root->children[i]->isTerminal)
            {
                suggesions.push_back(p);
            }

            // find other strings
            getAllwords(root->children[i], suggesions, p);
        }
    }
}

void swRec(TrieNode *root, string s, const string &pre, vector<string> &suggesions)
{
    if (s.length() == 0)
    {
        if (root->isTerminal)
        {
            suggesions.push_back(pre);
        }
        getAllwords(root, suggesions, pre);
        return;
    }

    int index = s[0] - 'a';

    TrieNode *child = root->children[index];

    if (child == NULL)
    {
        return;
    }

    return swRec(child, s.substr(1), pre, suggesions);
}

vector<string> Trie::suggest(string word)
{
    vector<string> suggesions;
    swRec(root, word, word, suggesions);
    return suggesions;
}

class Solution
{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // inserting all the words into trie
        Trie t;

        for (int i = 0; i < n; i++)
        {
            t.insert(contact[i]);
        }

        vector<vector<string>> ans;

        for (int i = 0; i < s.length(); i++)
        {
            vector<string> sugg = t.suggest(s.substr(0, i + 1));

            if (sugg.size() == 0)
            {
                sugg.push_back("0");
            }

            ans.push_back(sugg);
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
        string contact[n], s;
        for (int i = 0; i < n; i++)
            cin >> contact[i];
        cin >> s;

        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for (int i = 0; i < s.size(); i++)
        {
            for (auto u : ans[i])
                cout << u << " ";
            cout << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends