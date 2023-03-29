//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array
{
public:
    template <class T>
    static void input(vector<T> &A, int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};

// } Driver Code Ends
class Solution
{
public:
    int minimumInteger(int N, vector<int> &A)
    {

        long double X = 0;
        long double n = N;

        for (int i = 0; i < N; i++)
        {
            long double num = A[i];
            X += (num / n);
        }

        // true X is evaluated just find a suitable num from array
        int ans = INT_MAX;

        for (int i = 0; i < N; i++)
        {
            if ((long double)A[i] >= X)
            {
                ans = min(A[i], ans);
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {

        int N;
        scanf("%d", &N);

        vector<int> A(N);
        Array::input(A, N);

        Solution obj;
        int res = obj.minimumInteger(N, A);

        cout << res << endl;
    }
}

// } Driver Code Ends