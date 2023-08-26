//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


using ll = long long int;
class BIT
{
    ll *bit;
    ll size;

public:
    BIT(int n)
    {
        size = n + 1;
        bit = new ll[n + 2]{0};
    }

    void update(ll i, ll val)
    {
        ++i;
        for (; i < size; i += (i & (-i)))
        {
            bit[i] += val;
        }
    }

    ll sum(ll i)
    {
        ++i;
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
        ll ans = 0;
        BIT b(N + 2);

        set<ll> nums(arr, arr + N);
        unordered_map<ll, ll> eleToIdx;

        int j = 0;
        for (auto &e : nums)
            eleToIdx[e] = j++;

        for (ll i = 0; i < N; i++)
        {
            ll idx = eleToIdx[arr[i]];

            ans += b.query(idx + 1, j - 1); // j-1 points to max element
            b.update(idx, 1);
        }

        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends