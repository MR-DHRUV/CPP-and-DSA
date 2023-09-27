#include <bits/stdc++.h>
using namespace std;

int findUniqueII(vector<int> nums)
{
    // now here we cannot directly do xor
    // sum of bits at each position will be of the form 3n or 3n+1
    // 3n for repeating numbers and 3n+1 for req+unique number

    vector<int> s(32, 0);

    for (int &i : nums)
    {
        for (int j = 0; j < 31 && i > 0; j++)
        {
            int bit = (i >> j) & 1;

            if (bit > 0)
                s[31 - j]++;
        }
    }

    int ans = 0;

    for (int i = 31; i >= 0; i--)
    {
        if (s[i] % 3 == 1)
            ans = ans | (1 << (31 - i));
    }

    return ans;
}

int main()
{
    // I am having 3n+1 numbers
    // with ` numbers that is occuring once find it
    auto res = findUniqueII({1, 2, 6, 2, 1, 8, 1, 6, 2, 6});
    cout << res << " ";

    return 0;
}