#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void genPath(unordered_map<int, vector<string>> &dirc, vector<string> seq, vector<vector<string>> &ans, int lvl)
    {
        // base case
        if (lvl < 0)
        {
            // check for possible ans
            if (seq.back() == dirc[0][0])
            {
                reverse(seq.begin(), seq.end());
                ans.push_back(seq);
            }

            return;
        }

        string last = seq.back();

        for (auto word : dirc[lvl])
        {
            // check if possible
            int change = 0;

            for (int i = 0; i < last.length() && change <= 1; i++)
            {
                if (last[i] != word[i])
                {
                    change++;
                }
            }

            // only possible if change == 1
            if (change == 1)
            {
                // a possible pasth mey exist
                vector<string> nSeq = seq;
                nSeq.push_back(word);
                genPath(dirc, nSeq, ans, lvl - 1);
            }
        }
    }

    unordered_map<int, vector<string>> getDirc(const string &beginWord, const string &endWord, vector<string> &wordList, int &maxLvl)
    {
        unordered_map<int, vector<string>> lvlStore;
        lvlStore[0].push_back(beginWord);

        queue<string> qt;
        qt.push(beginWord);

        unordered_set<string> st(wordList.begin(), wordList.end());

        int lvl = 1;

        while (!qt.empty())
        {
            // travelling level by level
            int n = qt.size();

            while (n--)
            {
                string str = qt.front();
                qt.pop();

                // forcing permutations
                for (int i = 0; i < str.length(); i++)
                {
                    for (char ch = 'a'; ch <= 'z'; ch++)
                    {
                        if (ch != str[i])
                        {
                            // build new string
                            string temp = str;
                            temp[i] = ch;

                            // checking it in set
                            if (st.find(temp) != st.end())
                            {
                                lvlStore[lvl].push_back(temp);

                                if (temp == endWord)
                                {
                                    // important last level should only contain end word as rest are useless and creates a problem in dfs or it can be even empty
                                    lvlStore[lvl].clear();
                                    lvlStore[lvl].push_back(temp);

                                    maxLvl = lvl;
                                    return lvlStore;
                                }

                                st.erase(temp);
                                qt.push(temp);
                            }
                        }
                    }
                }
            }

            // incr lvl
            lvl++;
        }

        // no possible convertion path exist
        maxLvl = -1;
        lvlStore.clear();
        return lvlStore;
    }

    // optimization for leetcode
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {

        // cp way
        // breaking problem into 2 steps
        // Step 1 follow word ladder 1 and find out min steps and store the steps for every string
        // step 2 backtrack in the map

        /*
            hot dot dog lot log cog
            hit cog

            This time in queue we will store a map of string to int in which we wil store that at what step what word was made

            hit
            hot
            dot lot
            dog log
            cog cog

            map obtained
            hit -> 0
            hot -> 1
            dot -> 2
            lot -> 2
            dog -> 3
            log -> 3
            cog -> 4

            // Step 2 : backTracking from end to begin using dfs calls to build our sequence using all possible combinations and this will be achieved using reccursion
        */

        // why tle in previous solution
        // previously we are travelling unneccessarily or discovering ways that are not part of our ans
        // is tarah se disha mil gayi haii ki kaise kaise ja skte h min steps me

        // performing step 1

        // map that stores words formed at each level
        int maxLvl;
        unordered_map<int, vector<string>> dirc = getDirc(beginWord, endWord, wordList, maxLvl);

        vector<vector<string>> ans;
        if (maxLvl == -1)
        {
            return ans;
        }

        vector<string> seq;
        seq.push_back(endWord);
        genPath(dirc, seq, ans, maxLvl - 1);

        return ans;
    };
};

int main()
{

    return 0;
}