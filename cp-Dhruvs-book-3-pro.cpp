#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize('unroll-loops,O3')

#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define all(x) (x).begin(), (x).end()
#define el "\n"

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef pair<int, int> pii;

class Solution
{
    using ll = long long;

public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    long long maximumSubarraySum(vector<int> &nums, int k)
    {
        // number to indx
        unordered_map<int, int> mp;
        mp[nums[0]] = 0;

        // prefix sum
        vector<ll> pfx(nums.size(), 0);
        ll ans = LONG_MIN;
        for (int i = 1; i < nums.size(); i++)
            pfx[i] = nums[i] + pfx[i - 1];

        for (int i = 1; i < nums.size(); i++)
        {
            if (mp.count(nums[i] - k))
                ans = max(ans, pfx[i] - (mp[nums[i] - k] - 1 >= 0 ? pfx[mp[nums[i] - k] - 1] : 0));

            if (mp.count(nums[i] + k))
                ans = max(ans, pfx[i] - (mp[nums[i] + k] - 1 >= 0 ? pfx[mp[nums[i] + k] - 1] : 0));

            // maximizing prefix sum
            // see p[i] will be subtracted from further indices so we have to minimize it
            if (mp.count(nums[i]) == 0 || pfx[mp[nums[i]]] > p[i])
                mp[nums[i]] = i;
        }

        return ans == LONG_MIN ? 0 : ans;
    }
};

void __main__()
{
    int t;
    cin >> t;

    ll arr[200000];

    while (t--)
    {
        ll n, x, y, ans = 0;
        cin >> n >> x >> y;

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        unordered_map<ll, unordered_map<ll, ll>> mp;

        for (int i = n - 1; i >= 0; i--)
        {
            ll idx_X = (arr[i] % x == 0 ? 0 : x - (arr[i] % x)), idx_y = (arr[i] % y);
            ans += mp[idx_X][idx_y];
            mp[arr[i] % x][arr[i] % y]++;
        }

        cout << ans << el;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    __main__();
    return 0;
}