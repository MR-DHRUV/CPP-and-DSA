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
    int ans = INT_MAX;

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

    bool convert(string from, string to, int start, int isAns)
    {
        // base case
        if (from == to)
        {
            return true;
        }

        for (int i = start; i < from.length(); i++)
        {
            // skip matching characters
            while (from[i] == to[i] && i < from.length())
            {
                i++;
            }

            if (i >= from.length())
            {
                ans = min(ans, isAns);
                continue;
            }

            // now try to convert a word
            char temp = from[i]; // storing to backtrack
            from[i] = to[i];

            if (search(from))
            {
                // conversion was possible: try to convert ahead
                if (convert(from, to, i + 1, isAns + 1))
                {
                    if (from == to)
                    {
                        ans = min(ans, isAns);
                    }
                }
            }

            // try to find a smaller ans
            from[i] = temp;
        }

        return false;
    }

    int getMinSteps(string from, string to)
    {
        ans = INT_MAX;
        convert(from, to, 0, 0);

        if (ans == INT_MAX)
        {
            return -1;
        }

        return ans;
    }
};

int wordLadder(string begin, string end, vector<string> &dict)
{
    Trie *t = new Trie();

    // loading the trie
    for (int i = 0; i < dict.size(); i++)
    {
        t->insert(dict[i]);
    }

    return t->getMinSteps(begin, end);
}

class Solution
{
public:
    // generates all posssible combinations in which we can break the word
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        Trie *t = new Trie();

        // loading the trie
        for (int i = 0; i < wordDict.size(); i++)
        {
            t->insert(wordDict[i]);
        }

        return t->breakWordCombinations(s);
    }
};

int main()
{
    Solution obj;
    vector<string> dict = {"cat", "cats", "and", "sand", "dog"};
    vector<string> ans = obj.wordBreak("catsanddog", dict);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}