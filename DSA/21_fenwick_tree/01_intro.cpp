#include <bits/stdc++.h>
#define ll long long int
using namespace std;

// BIT for range sum
// BIT uses 1 based indexing
class BIT
{
    ll *bit;
    int size;

public:
    BIT(int n) : size(n)
    {
        bit = new ll[n + 1]{0};
    }

    // adding a value x at index i
    // log(N)
    void update(int i, int val)
    {
        // now here we need to concider all the indices which will keep a track of current index

        // so all the incides will be
        // i, j = i+lastSetBit(i)
        // k = j + lastsetBit(j)
        // .... till its less than size

        for (; i <= size; i += (i & (-i)))
        {
            bit[i] += val;
        }
    }

    // to obtain sum till index i
    // max complexity logi as max number of bits in a number N can be logN
    ll sum(int i)
    {
        ll ans = 0;

        // every time we remove last set bit from i to get the sum of next non overlaping interval
        for (; i > 0; i -= (i & (-i)))
        {
            ans += bit[i];
        }

        return ans;
    }

    ll query(int l, int r)
    {
        return sum(r) - sum(l - 1);
    }
};

int main()
{
    // also called binary indexed trees
    // its a data structure which computes things by doing prefix operations on array
    // its a online data structure i.e we can add elements in the end withoud changing the previous one's
    // can't solve complex problems like we saw in segment trees

    // faster than segment trees if applicable on a problem
    /// very small code and can be quickly coded

    // to obtain right most set bit of any number
    // rsb = (x)&(-x)

    // in segment trees andy index i will store data of range
    // j = removeLastBit(i)
    // range -> j+i to i

    // querying
    // to get sum of range (i,j)

#ifndef IO_FROM_FILE
    freopen("C:\\Users\\Dhruv\\OneDrive\\Documents\\CPP + DSA\\input.txt", "r", stdin);
    freopen("C:\\Users\\Dhruv\\OneDrive\\Documents\\CPP + DSA\\output.txt", "w", stdout);
#endif

    // increases speed by prventing the overhead
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q, t, l, r;
    cin >> n >> q;
    vector<ll> arr(n);
    BIT b(n + 1);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        b.update(i + 1, arr[i]);
    };

    while (q--)
    {
        cin >> t >> l >> r;

        if (t == 1)
        {
            // t1 query
            cout << b.query(l, r) << endl;
        }
        else
        {
            // calculate differnce from actual value so that we can update our BIT
            b.update(l,r-arr[l-1]);

            // update original array
            arr[l-1] = r;
        }
    }

    return 0;
}