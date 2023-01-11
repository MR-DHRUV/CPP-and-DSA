#include <bits/stdc++.h>
using namespace std;

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
    void del(string word);
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

void delRec(TrieNode *root, string s)
{
    if (s.length() == 0)
    {
        root->isTerminal = false;
        return;
    }

    int index = s[0] - 'a';

    TrieNode *child = root->children[index];

    if (child == NULL)
    {
        return;
    }

    return delRec(child, s.substr(1));
}

void Trie::del(string word)
{
    delRec(root, word);
}

bool searchRec(TrieNode *root, string s)
{
    if (s.length() == 0)
    {
        return root->isTerminal;
    }

    int index = s[0] - 'a';

    TrieNode *child = root->children[index];

    if (child == NULL)
    {
        return false;
    }

    return searchRec(child, s.substr(1));
}

bool Trie::search(string word)
{
    return searchRec(root, word);
}

