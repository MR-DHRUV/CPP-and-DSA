#include <bits/stdc++.h>
using namespace std;

vector<int> findUniqueII(vector<int> nums)
{
    int x = 0;

    for (int &i : nums)
        x ^= i;

    int n1 = 0, n2 = 0, rsb = (x &( -x));

    for (int &i : nums)
    {
        if (rsb & i)
            n1 ^= i;
        else
            n2 ^= i;
    }

    return {n1, n2};
}

int main()
{
    // I am having 2n+2 numbers
    // with 2 numbers that are occuring once find them
    auto res = findUniqueII({1,2,6,2,1,8});
    for(int &a : res)
        cout<<a<<" ";

    return 0;
}