#include <bits/stdc++.h>
#define ll long long int
using namespace std;

struct Query
{
    int l, r, idx;
    Query() {}
    Query(int l, int r, int i)
    {
        this->l = l;
        this->r = r;
        this->idx = i;
    }
};

int rootN = 1;
int arr[200005];
ll freq[10000000]{0};
Query queries[200005];

// this is a code for range sum queries
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q, l, r;
    cin >> n >> q;
    rootN = sqrtl(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < q; i++)
    {
        cin >> l >> r;
        queries[i] = Query(l, r, i);
    }

    // sorting queries
    sort(queries, queries + q, [](Query &a, Query &b)
         {
        if(a.l/rootN == b.l/rootN)
            return a.r > b.r;

        return a.l < b.l; });

    vector<ll> ans(q);
    int curr_l = 0, curr_r = -1;
    ll curr_ans = 0ll;

    // using this stratagy net complexity = Q*rootN + N*rootN
    for (int i = 0; i < q; i++)
    {
        // zero based indexing
        l = queries[i].l - 1, r = queries[i].r - 1;

        // expansion
        while (curr_r < r)
        {
            curr_r++;
            freq[arr[curr_r]]++;

            // remove previous from sum
            ll prevFreq = freq[arr[curr_r]] - 1;
            curr_ans -= (prevFreq * prevFreq * arr[curr_r]);

            // add new freq
            curr_ans += (freq[arr[curr_r]] * freq[arr[curr_r]] * arr[curr_r]);
        }

        while (curr_l > l)
        {
            curr_l--;
            freq[arr[curr_l]]++;

            // remove previous from sum
            ll prevFreq = freq[arr[curr_l]] - 1;
            curr_ans -= (prevFreq * prevFreq * arr[curr_l]);

            // add new freq
            curr_ans += (freq[arr[curr_l]] * freq[arr[curr_l]] * arr[curr_l]);
        }

        // contraction
        while (curr_r > r)
        {
            freq[arr[curr_r]]--;

            // remove previous from sum
            ll prevFreq = freq[arr[curr_r]] + 1;
            curr_ans -= (prevFreq * prevFreq * arr[curr_r]);

            // add new freq
            curr_ans += (freq[arr[curr_r]] * freq[arr[curr_r]] * arr[curr_r]);

            curr_r--;
        }

        while (curr_l < l)
        {
            freq[arr[curr_l]]--;

            // remove previous from sum
            ll prevFreq = freq[arr[curr_l]] + 1;
            curr_ans -= (prevFreq * prevFreq * arr[curr_l]);

            // add new freq
            curr_ans += (freq[arr[curr_l]] * freq[arr[curr_l]] * arr[curr_l]);

            curr_l++;
        }

        ans[queries[i].idx] = curr_ans;
    }

    for (auto &i : ans)
        cout << i << endl;

    return 0;
}