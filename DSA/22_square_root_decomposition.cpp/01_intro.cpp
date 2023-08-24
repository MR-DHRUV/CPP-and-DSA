#include <bits/stdc++.h>
using namespace std;

class SQ
{

    int *sq;
    int blkSize;
    vector<int> arr;

public:
    SQ(vector<int> &arr)
    {
        blkSize = ceil(sqrt(arr.size()));
        sq = new int[blkSize]{INT_MAX};

        build();
    }

    void build()
    {
        for (int i = 0; i < arr.size(); i++)
        {
            sq[i / blkSize] = min(sq[i / blkSize], arr[i]);
        }
    }

    // O(sqrt(N))
    int query(int l, int r)
    {
        int ans = INT_MAX;

        // first box
        while (l < r && l % blkSize != 0 && l != 0)
        {
            ans = min(ans, arr[l++]);
        }

        // middle portions
        while (l + blkSize - 1 <= r)
        {
            ans = min(ans, sq[l / blkSize]);
            l += blkSize;
        }

        // last box
        while (l <= r)
        {
            ans = min(ans, arr[l++]);
        }

        return ans;
    }

    void update(int i, int val)
    {
        sq[i / blkSize] = min(sq[i / blkSize], val);
    }
};

int main()
{
    // efficient way to solve range query questions
    // O(N + (Q*sqrt(N)))

    // isme hum ek sqrt array bnayenge jisme any index will store the data of sqrt(N) elements
    // index mapping will be such that
    // i/sqrt(n) will help us determine the index of ith index in sqrt array
    // we will anwser queries by utilizing the info present in the sqrt array

    // we will have 2 cases
    // complete overlap -> return ans in sqrt array
    // partial overlap -> manual traversing

    // sqrt decomposition for finding min in a range

    return 0;
}