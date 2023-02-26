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
    vector<int> dp;
    vector<string> combinations;

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

    bool combinationHelper(string s, int start, string builder)
    {
        // base case
        if (start == s.length())
        {
            return true;
        }

        bool retAns = false;
        string str = "";

        for (int j = start; j < s.length(); ++j)
        {
            str += s[j];

            // agar mujhe koi word mil gaya haii toh m yaha pr break krunga aur aage dhundunga
            if (search(str))
            {
                // building part
                string temp = builder;
                temp += str; // breaked part
                temp += " "; // space

                if (combinationHelper(s, j + 1, temp))
                {
                    // adding step
                    if (j + 1 == s.length())
                    {
                        temp.erase(temp.end()-1); // extra space hata dia last ka
                        combinations.push_back(temp);
                    }
                    retAns = true;
                }
            }
            // aaga ka pura break ni hua toh current word me next alphabet add krke search krunga, same stratagy just optimised by using dp
        }

        return retAns;
    }

    vector<string> breakWordCombinations(string s)
    {
        string str;
        combinations.clear();
        combinationHelper(s, 0, str);
        return combinations;
    }
};

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
    vector<string> dict = {"cat","cats","and","sand","dog"};
    vector<string> ans = obj.wordBreak("catsanddog",dict);

    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<endl;
    }
    


    return 0;
}