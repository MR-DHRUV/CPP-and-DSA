#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    char data;
    // modification acc to question as we can have duplicates
    int terminalCount;
    int prefixCount;

    TrieNode *children[26];

    // constructors
    TrieNode(){};
    // whenever a new node is created toh waha tk koi na koi word toh haii uss prefix se, so we'll initialize prefixCount with 1
    TrieNode(char ch) : data(ch), terminalCount(0), prefixCount(1)
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
    TrieNode *root;

    void insertRec(TrieNode *root, string s)
    {
        if (s.length() == 0)
        {
            root->terminalCount++;
            return;
        }

        int index = s[0] - 'a';

        TrieNode *child;

        if (root->children[index] != NULL)
        {
            child = root->children[index];
            child->prefixCount++;
        }
        else
        {
            child = new TrieNode(s[0]);
            root->children[index] = child;
        }

        insertRec(child, s.substr(1));
    }

    int searchRec(TrieNode *root, string s)
    {
        if (s.length() == 0)
        {
            return root->terminalCount;
        }

        int index = s[0] - 'a';

        TrieNode *child = root->children[index];

        if (child == NULL)
        {
            return 0;
        }

        return searchRec(child, s.substr(1));
    }

    int countPrefix(TrieNode *root, string s)
    {
        if (s.length() == 0)
        {
            return root->prefixCount;
        }

        int index = s[0] - 'a';

        TrieNode *child = root->children[index];

        if (child == NULL)
        {
            return 0;
        }

        return countPrefix(child, s.substr(1));
    }

    void delRec(TrieNode *root, string s)
    {
        if (s.length() == 0)
        {
            // since we cant delete word that is not present
            if (root->terminalCount > 0)
            {
                root->terminalCount--;
            }
            return;
        }

        int index = s[0] - 'a';

        TrieNode *child = root->children[index];

        if (child == NULL)
        {
            return;
        }

        // if child is present decriment its prefix count as 1 node dete krdia haii
        child->prefixCount--;

        return delRec(child, s.substr(1));
    }

public:
    Trie()
    {
        root = new TrieNode('\0');
    }

    void insert(string &word)
    {
        insertRec(root, word);
    }

    int countWordsEqualTo(string &word)
    {
        // find given string
        // return no of times that has been inserted
        return searchRec(root, word);
    }

    int countWordsStartingWith(string &word)
    {
        // we can do this in O(1)
        // just find the word if presdent in array and return prefix count
        // so while insertion whenever we'll traverse any node we'll incriment prefix count of that node as a new word that contains words till that node exists in the trie
        // and decriment while deletion

        return countPrefix(root,word);
    }

    void erase(string &word)
    {
        delRec(root, word);
    }
};

int main()
{
    Trie t;
    string s = "abc";
    string e = "aef";
    string q = "a";

    t.insert(s);
    t.insert(s);
    t.insert(e);

    cout << t.countWordsEqualTo(s) << endl;
    cout << t.countWordsEqualTo(e) << endl;
    cout << t.countWordsStartingWith(q) << endl;

    return 0;
}