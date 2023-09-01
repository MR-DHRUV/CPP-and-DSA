#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
using ll = long long int;
class Node
{
public:
    ll val;
    ll mul = 1;
    ll add = 0;

    Node(ll x) : val(x){};
};

class BIT
{
    vector<Node> bit;

public:
    BIT()
    {
        bit.push_back(Node(0ll)); // init with an element 0
    }

    void append(int &x)
    {
        bit.push_back(Node((ll)x));
    }

    /*
        How add and update functions are able to update the range
        I am calling them for the sie of array say 7 at present
        so I start from 7th index
        7 -> 0111  removeLastBit(7) -> 0110

        7 index updated which tracked data from 7 to 7

        now we have 6
        6 -> 0110  removeLastBit(6) -> 0100
        6 tracks data of 5-6 that got updated and so on... till 0

        // Now while querying
        har element ke pass uska data hoga, now we need to accumulate the above updates so while querying we add last bit and get all the updates correctly
    */

    void add(int i, int val)
    {
        while (i > 0)
        {
            bit[i].add = (bit[i].add + val) % mod;
            i -= i & -i;
        }
    }

    void multiply(int i, int val)
    {
        while (i > 0)
        {
            // addition multiply
            bit[i].add = (bit[i].add * val) % mod;

            // multiply factor multiply
            bit[i].mul = (bit[i].mul * val) % mod;
            i -= i & -i;
        }
    }

    int query(int i)
    {
        ++i;
        ll ans = bit[i].val;

        while (i < bit.size())
        {
            auto &p = bit[i];
            ans = (ans * p.mul) % mod;
            ans = (ans + p.add) % mod;

            i += (i) & (-i);
        }

        return ans % mod;
    }
};

class Fancy
{
    BIT b;
    int n = 0;

public:
    Fancy()
    {
    }

    void append(int val)
    {
        // point update : O(log N)
        n++;
        b.append(val);
    }

    void addAll(int inc)
    {
        // range update
        b.add(n, inc);
    }

    void multAll(int m)
    {
        // range update
        b.multiply(n, m);
    }

    int getIndex(int idx)
    {
        // query
        if (idx > n - 1)
            return -1;

        return b.query(idx);
    }
};

int main()
{

    return 0;
}