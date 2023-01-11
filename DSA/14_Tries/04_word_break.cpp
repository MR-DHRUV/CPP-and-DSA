//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

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
    bool search(string word);
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

bool canIbreak(TrieNode *node, TrieNode *root, string &s, int i)
{
    // base case
    if (s.size() == i && node == root)
        return true;

    // if child not present
    if (!node->children[s[i] - 'a'])
        return false;

    // set childe
    node = node->children[s[i] - 'a'];

    // reccursive process
    if (node->isTerminal && canIbreak(root, root, s, i + 1))
        return true;

    // backtrack to root to find other words
    return canIbreak(node, root, s, i + 1);
};

class Solution
{
public:
    // A : given string to search
    // B : vector of available strings

    int wordBreak(string A, vector<string> &B)
    {
        // loading trie
        Trie t;

        for (int i = 0; i < B.size(); i++)
        {
            t.insert(B[i]);
        }

        return canIbreak(t.root, t.root, A, 0);
    };
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
        vector<string> dict;
        for (int i = 0; i < n; i++)
        {
            string S;
            cin >> S;
            dict.push_back(S);
        }
        string line;
        cin >> line;
        Solution ob;
        cout << ob.wordBreak(line, dict) << "\n";
    }
}

// } Driver Code Ends