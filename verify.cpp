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

public:
    Trie()
    {
        root = new TrieNode();
        root->isTerminal = false;
    }

    void insert(const string &s)
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

private:
    bool search(const string &s)
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

    void erase(const string &s)
    {
        TrieNode *temp = root;

        for (int i = 0; i < s.size(); i++)
        {
            if (!temp->containsKey(s[i]))
            {
                return;
            }

            temp = temp->get(s[i]);
        }

        temp->isTerminal = false;
    }

public:
    string replaceWithSmallest(const string &s)
    {
        TrieNode *temp = root;

        for (int i = 0; i < s.length(); i++)
        {
            if (!temp->containsKey(s[i]))
            {
                return s; // cant be shortened
            }

            temp = temp->get(s[i]);

            if (temp->isTerminal)
            {
                string shortened;
                shortened.append(s.begin(), s.begin() + i);
                return shortened;
            }
        }

        return s;
    }

public:
};

class Solution
{
public:
    string replaceWords(vector<string> &dictionary, string sentence)
    {

        Trie *t = new Trie();

        for (int i = 0; i < dictionary.size(); i++)
        {
            t->insert(dictionary[i]);
        }

        string ans;

        for (int i = 0; i < sentence.size(); i++)
        {
            string temp;

            while (i < sentence.size() && sentence[i] != ' ')
            {
                temp.push_back(sentence[i++]);
            }

            temp = t->replaceWithSmallest(temp);
            ans.append(temp);
            ans.push_back(' ');
        }

        return ans;
    }
};

int main()
{

    return 0;
}