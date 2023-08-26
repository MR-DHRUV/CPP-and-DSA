#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
using ll = long long int;
class Node
{
public:
    int val;
    int mul = 1;
    int add = 0;

    Node(int x) : val(x){};
};

class BIT
{
    vector<Node> bit;

public:
    BIT()
    {
        bit.push_back(Node(0)); // init with an element 0
    }

    void append(int &x)
    {
        bit.push_back(Node(x));
    }

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
        long long ans = bit[i].val;

        while (i < bit.size())
        {
            auto &p = bit[i];
            ans = (ans * p.mul) % mod;
            ans = (ans + p.add) % mod;

            i += (i) & (-i);
        }

        return ans;
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