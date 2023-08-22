#include <bits/stdc++.h>
#define ll long long int
using namespace std;

class BIT
{
    ll *bit;
    int size;

public:
    BIT(int n) : size(n)
    {
        bit = new ll[n + 1]{0};
    }

    void update(int i, int val)
    {
        for (; i < size; i += (i & (-i)))
        {
            bit[i] += val;
        }
    }

    ll sum(int i)
    {
        ll ans = 0;

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

    int lower_bound(ll sum)
    {
        // Now, here we need one more operation
        // to find index till which a given prefix sum is a lower_bound
        // i.e first index till which prefix sum is equal or just greater than a given value
        // So' to deal this we'll use binary lifting

        // Observation
        // find the maximum index till which sum is just smaller
        // add 1 to it
        // return ans;

        // We will search in our BIT logarathimcally
        // we'll start from index which is the max power of 2
        // 20 -> 4
        // 32 -> 5
        // 16-> 4
        // and we'll check value at that index  if its less then we can use it, else we'll decrease the power of 2 by 1 

        // now, if we can use any index then we will navigate to the last value till which the sum is smaller 
        // so we'll add the remaning power of 2 to current index to check if we can take the sum till that index 

        // if now skip, if yes add 
        // ansd we'll continue till 2^0

        // This works as
        // say val at 2^3 is large and 2^2 is small 
        // so we can add 2^1 and 2^0 
        // so the max index we can navigate is
        // 4+2+1 = 7 which is less than 8
        // we are doing this in a logarithmic style  

        // we can say that sumTill(2^i) = sumTill(2^i+1) - 1
        // so we are always before index where the value is greater 
        

        ll idx = 0, prevSum = 0;

        for (int i = log2(size); i >= 0; i--)
        {
            // can be used
            if (prevSum + bit[idx + (1 << i)] < sum)
            {
                idx += (1 << i);
                prevSum += bit[idx];
            }
        }

        return idx + 1;
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
            b.update(l, r - arr[l - 1]);

            // update original array
            arr[l - 1] = r;
        }
    }

    return 0;
}