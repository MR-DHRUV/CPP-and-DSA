#include <bits/stdc++.h>
using namespace std;

void printMat(const vector<vector<int>> &vec)
{
    for (const auto &row : vec)
    {
        for (const auto &element : row)
        {
            cout << element << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> printAllLis(vector<int> &nums)
{
    // We we will first make lis element by element in dp array
    // then we will reverse engineer things to generate all lis

    // step 1 : finding lis ending at index i
    int n = nums.size();
    vector<int> dp(n);
    unordered_map<int, vector<int>> mp; // it will track lis of given size

    int len = 0;  // length of lis
    int idx = -1; // index at which lis is seen

    for (int i = 0; i < n; i++)
    {
        int maxE = 0;

        // finding length of previous maximum lis such that arr[i] can be added in it
        for (int j = 0; j < i; j++)
        {
            // check if we can add or not
            if (nums[j] < nums[i])
            {
                maxE = max(maxE, dp[j]);
            }
        }

        dp[i] = 1 + maxE;
        mp[dp[i]].push_back(i);

        if (dp[i] > len)
        {
            len = dp[i];
            idx = i;
        }
    }

    // Step 2: reverse engineerinng using bsf : same as seen in word ladder
    queue<pair<vector<int>, vector<int>>> qt;
    vector<vector<int>> ans;

    // len , current_index, lis vector
    qt.push({{len, idx}, {nums[idx]}});

    while (!qt.empty())
    {
        auto top = qt.front();
        qt.pop();

        // ab dekho ki yeh kis kis previous element se bn skta haii
        // to check it
        // length of lis at that index should be top wale ki length -1
        // and element at that index should be less than top wala element

        int currLen = top.first[0];
        int currIdx = top.first[1];

        if (currLen-1 == 0)
        {
            reverse(top.second.begin(), top.second.end());
            ans.push_back(top.second);
            continue;
        }

        for (auto i : mp[currLen-1])
        {
            if (i < currIdx && nums[i] < nums[currIdx])
            {
                vector<int> temp = top.second;
                temp.push_back(nums[i]);
                qt.push({{currLen - 1, i}, temp});
            }
        }
    }

    return ans;
}

int main()
{
    vector<int> nums = {10, 22, 9, 33, 21, 50, 41, 60, 80, 1};
    vector<vector<int>> ans = printAllLis(nums);
    printMat(ans);

    return 0;
}