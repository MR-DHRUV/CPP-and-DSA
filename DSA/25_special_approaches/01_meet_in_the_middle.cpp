#include <bits/stdc++.h>
using namespace std;
#define int long long int

vector<int> subsetSums(vector<int> &a)
{
    int n = a.size(); // total sums 2^n
    vector<int> sums;

    for (int i = 0; i < (1 << n); i++)
    {
        int sum = 0;

        // max set bit can be at index n
        for (int j = 0; j < n; j++)
        {
            if ((i >> j) & 1)
                sum += a[j];
        }

        sums.push_back(sum);
    }

    return sums;
}

int32_t main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    // Given a sequence of N (1 ≤ N ≤ 34) numbers S1, ..., SN (-20,000,000 ≤ Si ≤ 20,000,000), determine how many subsets of S (including the empty one) have a sum between A and B (-500,000,000 ≤ A ≤ B ≤ 500,000,000), inclusive.

    // here we cant use dp as numbers are huge and cant make such a large array

    // We need sum in range A to B
    // Meet in the middle approach
    // We will make A move towards B and B towards A to reduce overall complexity of the algo

    // here N = 34 max
    // total subets = 2^34

    // breaking it into 2 parts
    // 2^17 each
    // Now we can compute all subset sum in 2^17 and look for all possible pairs in other part using hashmap to make sum fall in range

    // if we used a single part then complexity will be 2^32 but now its 2^17
    int n, A, B, arr[40], ans = 0;
    cin >> n >> A >> B;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> st1, st2;

    // set1: put it
    for (int i = 0; i < n; i++)
    {
        if (i <= n / 2)
            st1.push_back(arr[i]);
        else
            st2.push_back(arr[i]);
    }

    vector<int> sums1 = subsetSums(st1), sums2 = subsetSums(st2);
    sort(sums2.begin(), sums2.end()); // to do bin search to calculate numbers in a range

    for (int &i : sums1)
    {
        int low = A - i, high = B - i;
        int cnt = upper_bound(sums2.begin(), sums2.end(), high) - lower_bound(sums2.begin(), sums2.end(), low);
        ans += cnt;
    }

    cout << ans << endl;

    return 0;
}