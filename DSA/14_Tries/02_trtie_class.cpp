#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    // data
    char data;

    // children array to store all alphabets
    TrieNode *children[26];

    // to check whether the node is terminal or not
    bool isTerminal;

    // constructors
    TrieNode(){};
    TrieNode(char ch) : data(ch), isTerminal(false)
    {
        // init children with NULL
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
    };
    TrieNode(char ch, bool terminal) : data(ch), isTerminal(terminal)
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
        // root is initailised with null character
        root = new TrieNode('\0');
    };

    // functions
    // complexity of each operation : O(word.length())
    void insert(string word);
    bool search(string word);
    void del(string word);

    // suggesion dega yeh
    vector<string> suggest(string word);
};

void insertRec(TrieNode *root, string s)
{
    // base case
    if (s.length() == 0)
    {
        // all the characters are set, just mark last node as terminal node
        root->isTerminal = true;
        return;
    }

    // find index of alphabet
    // it is assumed that we'll only have capital letters
    int index = s[0] - 'A';

    TrieNode *child;

    // given alphabet of string is present in trie
    if (root->children[index] != NULL)
    {
        // just move ahead
        child = root->children[index];
    }
    else
    {
        // absent
        child = new TrieNode(s[0]);
        root->children[index] = child;
    }

    // Reccursive step
    // given string ko ek aage se bhej do
    insertRec(child, s.substr(1));
}

void Trie::insert(string word)
{
    insertRec(root, word);
}

void delRec(TrieNode *root, string s)
{
    // base case
    if (s.length() == 0)
    {
        // all the characters are found, just mark last node as a non terminal node
        root->isTerminal = false;
        return;
    }

    // find index of alphabet
    // it is assumed that we'll only have capital letters
    int index = s[0] - 'A';

    TrieNode *child = root->children[index];

    // given alphabet of string is absent in trie, thus the word is absent
    if (child == NULL)
    {
        return;
    }

    // if present
    // Reccursive step
    // given string ko ek aage se bhej do
    return delRec(child, s.substr(1));
}

void Trie::del(string word)
{
    // just find if present
    // if found just mark, node of last character as a non terminal node

    // no need to delete the node as there can be other words using it
    delRec(root, word);
}

bool searchRec(TrieNode *root, string s)
{
    // base case
    if (s.length() == 0)
    {
        // we can say a word is present only if its last letter is termical
        // all the characters are set, just return true
        return root->isTerminal;
    }

    // find index of alphabet
    // it is assumed that we'll only have capital letters
    int index = s[0] - 'A';

    TrieNode *child = root->children[index];

    // given alphabet of string is absent in trie
    if (child == NULL)
    {
        return false;
    }

    // if present
    // Reccursive step
    // given string ko ek aage se bhej do
    return searchRec(child, s.substr(1));
}

bool Trie::search(string word)
{
    return searchRec(root, word);
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

            // agar wop terminal node haii toh string bnado
            if (root->children[i]->isTerminal)
            {
                suggesions.push_back(p);
            }

            // find other strings
            getAllwords(root->children[i], suggesions, p);
        }
    }
}

void swRec(TrieNode *root, string s,const string &pre ,vector<string> &suggesions)
{
    // base case
    if (s.length() == 0)
    {
        // here we are just checking if we have words that can start with a given string
        // now we have verified that all the letters of the start string are present
        // now we need all possible words that are after it
        // by words i mean terminal
        // s is passed to functions as all the suggesions will contain s
        getAllwords(root, suggesions,pre);

        return;
    }

    // find index of alphabet
    // it is assumed that we'll only have capital letters
    int index = s[0] - 'A';

    TrieNode *child = root->children[index];

    // given alphabet of string is absent in trie
    if (child == NULL)
    {
        return;
    }

    // if present
    // Reccursive step
    // given string ko ek aage se bhej do
    return swRec(child, s.substr(1), pre,suggesions);
}

vector<string> Trie::suggest(string word)
{
    vector<string> suggesions;
    swRec(root, word, word,suggesions);
    return suggesions;
}

void printArr(vector<string> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" "; 
    }

    cout<<endl;
    
}


int main()
{
    Trie t;
    t.insert("HELLO");
    t.insert("A");
    t.insert("AB");
    t.insert("ABC");
    t.insert("ABCE");
    t.insert("ABCD");
    t.insert("ABCEFGH");

    // cout << t.root->children[7]->data;
    cout << t.search("HELLO") << endl;
    cout << t.search("HE") << endl;
    cout << t.search("ABC") << endl;

    vector<string> suggesions = t.suggest("A");
    printArr(suggesions);

    

    return 0;
}