//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
using ll = long long int;

// we can use unorderd map to optimize space but that will use logarithmic time in worst case

class BIT
{
    ll *bit;
    ll size;

public:
    BIT(ll n) : size(n)
    {
        bit = new ll[n + 1]{0};
    }

    void update(ll i, ll val)
    {
        for (; i <= size; i += (i & (-i)))
        {
            bit[i] += val;
        }
    }

    ll sum(ll i)
    {
        ll ans = 0;

        for (; i > 0; i -= (i & (-i)))
        {
            ans += bit[i];
        }

        return ans;
    }

    ll query(ll l, ll r)
    {
        return sum(r) - sum(l - 1);
    }
};

class Solution
{
public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], long long N)
    {
        ll maxi = *max_element(arr, arr + N);

        BIT b(maxi + 2);
        ll ans = 0;

        for (ll i = 0; i < N; i++)
        {
            ans += b.query(arr[i] + 1, maxi + 1);
            b.update(arr[i], 1);
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main()
{

    long long T;
    cin >> T;

    while (T--)
    {
        long long N;
        cin >> N;

        long long A[N];
        for (long long i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A, N) << endl;
    }

    return 0;
}

// } Driver Code Ends