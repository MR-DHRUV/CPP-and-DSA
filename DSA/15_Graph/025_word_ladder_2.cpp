//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    // updation in algo from word ladder 1
    // we cannot delete right away any word as that word can be involved in sequence of same level
    // once we have traversed a given level then only we will remove all the words that are used in the given level

    /*
        5
        pat
        bot
        pot
        poz
        coz
        bat
        coz

        Output:

        bat bot pot poz coz
        bat pat pot poz coz
    */

    // here the size of queue will vary from ans to ans thus we cannot predict the time complexity of this queue


    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string> &wordList)
    {
        // we will store word,noOfTransformsDone in queue
        queue<vector<string>> qt;

        // init
        vector<string> sequence;
        sequence.push_back(beginWord);
        qt.push({beginWord});

        // to search any word of wordList in logN time
        unordered_set<string> s;

        // loading set
        for (auto word : wordList)
        {
            s.insert(word);
        }

        // ans
        vector<vector<string>> ans;

        // at any level we will try to change all characteres from a to z and check if any of them is present in the wordList

        // eg hit
        // first we will permutate h from a to z and rest part same and same for next characters
        int n = beginWord.length();
        int len = INT_MAX; // pata nahi kitna lamba haii sequence

        // vector to store words that are used in any level
        vector<string> lvlStore;

        // here the size of queue will vary from ans to ans thus we cannot predict the time complexity of this queue
        while (!qt.empty())
        {
            // traversing level by level
            int lvls = qt.size();

            for (int lvl = 0; lvl < lvls; lvl++)
            {
                vector<string> sequ = qt.front();
                string w = sequ.back(); // last word of the sequence is our current word
                qt.pop();

                // permutating
                for (int i = 0; i < n; i++)
                {
                    for (char ch = 'a'; ch <= 'z'; ch++)
                    {
                        if (ch == w[i])
                        {
                            continue;
                        }

                        string temp = w;
                        temp[i] = ch;

                        if (s.find(temp) != s.end())
                        {
                            vector<string> seq = sequ;

                            if (temp == endWord)
                            {
                                if (len == INT_MAX)
                                {
                                    // now we have shortest sequence
                                    len = seq.size();

                                    // update seq
                                    seq.push_back(endWord);

                                    // update ans
                                    ans.push_back(seq);
                                }
                                else if (sequ.size() == len)
                                {
                                    // update seq
                                    seq.push_back(endWord);

                                    // update ans
                                    ans.push_back(seq);
                                }
                                else
                                {
                                    return ans;
                                }
                            }
                            else
                            {
                                // vvvvvip : we dont have to ease it rn as some other sequence at same level may use it
                                // s.erase(temp);
                                lvlStore.push_back(temp);

                                // update the seq
                                seq.push_back(temp);
                                qt.push({seq});
                            }
                        }
                    }
                }
            }

            // optimize
            unordered_map<string, bool> mp;

            // now deleting all the words that are used in current level
            for (string word : lvlStore)
            {
                if (!mp[word])
                {
                    mp[word] = true;
                    s.erase(word);
                }
            }

            lvlStore.clear();
        }

        // not possible
        return ans;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for (string i : a)
        x += i;
    for (string i : b)
        y += i;

    return x < y;
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<string> wordList(n);
        for (int i = 0; i < n; i++)
            cin >> wordList[i];
        string startWord, targetWord;
        cin >> startWord >> targetWord;
        Solution obj;
        vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
        if (ans.size() == 0)
            cout << -1 << endl;
        else
        {
            sort(ans.begin(), ans.end(), comp);
            for (int i = 0; i < ans.size(); i++)
            {
                for (int j = 0; j < ans[i].size(); j++)
                {
                    cout << ans[i][j] << " ";
                }
                cout << endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends