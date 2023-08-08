#include <bits/stdc++.h>
using namespace std;

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
int queryHelper(int idx, int s, int e, int &l, int &r)
{
    // no overlap
    if (r < s || l > e)
        return 1e9 + 7;

    // complete overlap
    if (s >= l && e <= r)
        return segTree[idx];

    // partial overlap
    int mid = s + (e - s) / 2;

    int left = queryHelper((idx * 2) + 1, s, mid, l, r);
    int right = queryHelper((idx * 2) + 2, mid + 1, e, l, r);

    return min(left, right);
}

int RMQ(int st[], int n, int a, int b)
{
    // cout<<"n "<<n<<endl;
    return queryHelper(0, 0, n - 1, a, b);
}

int updateHelper(int s, int e, int idx, int &target, int &val)
{
    // current interval ka koi lena dena nahi haii
    if (target < s || target > e)
        return 1e9;

    if (s == e)
    {
        segTree[s] = val;
        return val;
    }

    int mid = s + (e - s) / 2;

    if (target <= mid)
        return updateHelper(s, mid, (2 * idx) + 1, target, val);
    else
        return updateHelper(mid + 1, e, (2 * idx) + 2, target, val);

    // now update current node
    segTree[idx] = min(segTree[(2 * idx) + 1], segTree[(2 * idx) + 2]);
}

void update(int target, int val, int n)
{
    // point updates or update queries
    // we are now given an index and a value and we have to update the array[idx] to val
    // wohi same postorder style me values update krdo target se
    updateHelper(0, n - 1, 0, target, val);
}

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
