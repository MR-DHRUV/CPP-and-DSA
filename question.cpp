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

    // count of no of words that end on this letter
    int terminalCount = 0;

    // count of no of words which have this prefix
    int prefixCount = 0;

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

    void insert(string s)
    {
        TrieNode *temp = root;

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

        // now temp points to terminal node
        temp->terminalCount++;
    }

    int countWordsStartingWith(string s)
    {
        TrieNode *temp = root;

        for (int i = 0; i < s.length(); i++)
        {
            // if not present just return 0
            if (!temp->containsKey(s[i]))
            {
                return 0;
            }

            // point temp to next child
            temp = temp->get(s[i]);
        }

        return temp->prefixCount;
    }
};

class Solution
{
public:
    int prefixSuffixString(vector<string> &s1, vector<string> s2)
    {
        // loading s1
        Trie t1, t2;

        for (int i = 0; i < s1.size(); i++)
        {
            string s = s1[i];
            t1.insert(s);

            reverse(s.begin(), s.end());
            t2.insert(s);
        }

        int ans = 0;

        for (int i = 0; i < s2.size(); i++)
        {
            string s = s2[i];
            int a = t1.countWordsStartingWith(s);

            reverse(s.begin(), s.end());
            a += t2.countWordsStartingWith(s);

            if (a > 0)
                ans++;
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        string str1, str2, newline;
        if (i == 0)
            getline(cin, newline);
        getline(cin, str1);
        getline(cin, str2);
        // getline(cin,newline);
        // cout<<str1<<endl<<str2<<endl;
        vector<string> s1, s2;
        stringstream ss1(str1);
        stringstream ss2(str2);
        string str;
        while (ss1 >> str)
        {
            s1.push_back(str);
        }
        while (ss2 >> str)
        {
            s2.push_back(str);
        }
        Solution ob;
        cout << ob.prefixSuffixString(s1, s2) << endl;
    }
}
// } Driver Code Ends