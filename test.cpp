#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    TrieNode *children[26];
    bool isTerminal;

    bool containsKey(char ch)
    {
        return children[ch - 'a'] != NULL;
    }

    TrieNode *get(char ch)
    {
        return children[ch - 'a'];
    }

    void set(char ch, TrieNode *x)
    {
        children[ch - 'a'] = x;
    }
};

class Trie
{
    TrieNode *root;
    vector<int>dp;

public:
    Trie()
    {
        root = new TrieNode();
        root->isTerminal = false;
    }

    void insert(string s)
    {
        TrieNode *temp = root;

        for (int i = 0; i < s.length(); i++)
        {
            if (!temp->containsKey(s[i]))
            {
                TrieNode *n = new TrieNode();
                n->isTerminal = false;
                temp->set(s[i], n);
            }

            temp = temp->get(s[i]);
        }

        temp->isTerminal = true;
    }

    bool search(string s)
    {
        TrieNode *temp = root;

        for (int i = 0; i < s.length(); i++)
        {
            if (!temp->containsKey(s[i]))
            {
                return false;
            }

            temp = temp->get(s[i]);
        }

        return temp->isTerminal;
    }

    bool canIbreak(string s,int n, int start)
    {
        // base case
        if(start == n)
        {
            return true;
        }

        // already determined
        if(dp[start] != -1)
        {
            return dp[start];
        }

        string str = "";

        for (int j = start; j < n; ++j)
        {
            str += s[j];

            // temp mil gaya haii ab uske aage ka part khoj lao 
            if(search(str))
            {
                if(canIbreak(s,n,j+1))
                {
                    return dp[start] = true;
                }
            }
        }
        
        return dp[start] = false;
    }

    bool breakWord(string s)
    {
        dp = vector<int>(s.length()+1,-1);
        return canIbreak(s, s.length(),0);
    }
};

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        Trie *t = new Trie();

        // loading the trie
        for (int i = 0; i < wordDict.size(); i++)
        {
            t->insert(wordDict[i]);
        }

        return t->breakWord(s);
    }
};

int main()
{

    return 0;
}