//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // O(N*wordLength*26)
    int wordLadderLength(string startWord, string targetWord, vector<string> &wordList)
    {
        // Code here

        // startWord ko targetWord me convert krna haii by changing any one character at a time and that new word must exist in dictionary or wordList

        // brute force
        // we will replace every character from a to z  and try to see if it exists in dict or not
        // we will move level by level by making all possible transformations at any level
        /*
            hot dot dog lot log cog
            hit -> cog

            level 0 hit
            level 1 hot
            level 2 dot lot
            level 3 dog log
            level 4 cog cog

            since we are making changes level by level we will use BFS traversal

        */

        // we will store word,noOfTransformsDone in queue
        queue<pair<string, int>> qt;
        qt.push({startWord, 1}); // 1 as initial length of sequence is 1

        // to search any word of wordList in O(1) time
        unordered_set<string> s;

        // loading set
        for (auto word : wordList)
        {
            s.insert(word);
        }

        // at any level we will try to change all characteres from a to z and check if any of them is present in the wordList

        // eg hit
        // first we will permutate h from a to z and rest part same and same for next characters

        int n = startWord.length();

        // no of words in queue will N at worst case : O(N)
        while (!qt.empty())
        {
            string w = qt.front().first;
            int t = qt.front().second;
            qt.pop();

            // permutating : O(S+26) = O(S)
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
                        // target bn gaya ans return kardo
                        if (temp == targetWord)
                        {
                            return t + 1;
                        }

                        // erasing that word from set so that we accidently dont make that word again as agar pahle used h toh woh shortest transfromation se hi hua hoga
                        s.erase(temp);
                        qt.push({temp, t + 1});
                    }
                }
            }
        }

        // not possible
        return 0;
    }
};

//{ Driver Code Starts.
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
        int ans = obj.wordLadderLength(startWord, targetWord, wordList);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends