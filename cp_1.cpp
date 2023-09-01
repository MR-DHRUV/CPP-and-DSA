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
const int maxN = 200005, maxNum = 1e6 + 100;
int arr[maxN], freq[maxNum]{0};
ll ans[maxN];
Query queries[maxN];

// this is a code for range sum queries
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q, l, r;
    scanf("%d%d", &n, &q);
    rootN = sqrtl(n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < q; i++)
    {
        scanf("%d%d", &l, &r);
        queries[i] = Query(l, r, i);
    }

    // sorting queries
    sort(queries, queries + q, [](Query &a, Query &b)
         {
        if(a.l/rootN == b.l/rootN)
            return a.r > b.r;

        return a.l < b.l; });

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

            // remove previous from sum
            curr_ans -= (freq[arr[curr_r]] * freq[arr[curr_r]] * arr[curr_r]);

            // add new freq
            freq[arr[curr_r]]++;
            curr_ans += (freq[arr[curr_r]] * freq[arr[curr_r]] * arr[curr_r]);
        }

        while (curr_l > l)
        {
            curr_l--;
            // remove previous from sum
            curr_ans -= (freq[arr[curr_l]] * freq[arr[curr_l]] * arr[curr_l]);

            // add new freq
            freq[arr[curr_l]]++;
            curr_ans += (freq[arr[curr_l]] * freq[arr[curr_l]] * arr[curr_l]);
        }

        // contraction
        while (curr_r > r)
        {
            // remove previous from sum
            curr_ans -= (freq[arr[curr_r]] * freq[arr[curr_r]] * arr[curr_r]);

            // add new freq
            freq[arr[curr_r]]--;
            curr_ans += (freq[arr[curr_r]] * freq[arr[curr_r]] * arr[curr_r]);

            curr_r--;
        }

        while (curr_l < l)
        {
            // remove previous from sum
            curr_ans -= (freq[arr[curr_l]] * freq[arr[curr_l]] * arr[curr_l]);

            // add new freq
            freq[arr[curr_l]]--;
            curr_ans += (freq[arr[curr_l]] * freq[arr[curr_l]] * arr[curr_l]);

            curr_l++;
        }

        ans[queries[i].idx] = curr_ans;
    }

    for (int i = 0; i < q; i++)
    {
        printf("%I64d\n", ans[i]);
    }

    return 0;
}