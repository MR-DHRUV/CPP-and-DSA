//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int *constructST(int arr[], int n);

int RMQ(int st[], int n, int a, int b);
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++)
            cin >> A[i];
        int Q;
        cin >> Q;

        int *segTree = constructST(A, N);

        for (int i = 0; i < Q; i++)
        {
            int start, e;

            cin >> start >> e;
            if (start > e)
            {
                swap(start, e);
            }
            cout << RMQ(segTree, N, start, e) << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends

/* The functions which
builds the segment tree */

int segTree[10000];

void buildHelper(int s, int e, int idx, int nums[])
{
    if (s == e)
    {
        segTree[idx] = nums[s];
        return;
    }

    int mid = s + (e - s) / 2;

    // left half
    buildHelper(s, mid, (2 * idx) + 1, nums);
    // right half
    buildHelper(mid + 1, e, (2 * idx) + 2, nums);

    // curr
    segTree[idx] = min(segTree[(2 * idx) + 1], segTree[(2 * idx) + 2]);
}

int *constructST(int arr[], int n)
{
    buildHelper(0, n - 1, 0, arr);
}

/* The functions returns the
 min element in the range
 from a and b */
int query(int idx, int s, int e, int &l, int &r)
{
    // no overlap
    if (r < s || l > e)
        return 1e9 + 7;

    // complete overlap
    if (s >= l && e <= r)
        return segTree[idx];

    // partial overlap
    int mid = s + (e - s) / 2;

    int left = query((idx * 2) + 1, s, mid, l, r);
    int right = query((idx * 2) + 2, mid + 1, e, l, r);

    return min(left, right);
}

int RMQ(int st[], int n, int a, int b)
{
    // cout<<"n "<<n<<endl;
    return query(0, 0, n - 1, a, b);
}
