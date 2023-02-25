#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
// to change from lowercase to uppercase in just one change
#define baseLetter 'a'

    // children
    TrieNode *children[26];

    // count of no of words that end on this letter
    int terminalCount;

    // count of no of words which have this prefix
    int prefixCount;

    // default constructor
    TrieNode() : terminalCount(0), prefixCount(0){};

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
    TrieNode *set(TrieNode *n, char ch)
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

    // returns the no of occurances of a word 
    int countWordsEqualTo(string s)
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

        return temp->terminalCount;
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

    void erase(string s)
    {
        TrieNode *temp = root;

        for (int i = 0; i < s.length(); i++)
        {
            // if not present just return
            if (!temp->containsKey(s[i]))
            {
                return;
            }

            // point temp to next child
            temp = temp->get(s[i]);
            temp->prefixCount--;
        }

        // now temp points to terminal node
        temp->terminalCount--;
    }
};

int main()
{

    return 0;
}