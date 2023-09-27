//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    bool check(int D, int N, vector<int> A)
    {

        int maxT = 2 * N + 1;

        for (int i = 0; i < N; i++)
        {
            int dist = 0;

            for (int curr = i; dist < maxT; curr = ((curr + D) % N), dist += D)
            {
                if (A[curr] > A[(curr + D) % N])
                    swap(A[curr], A[A[(curr + D) % N]]);
            }
        }

        for (int i = 0; i < N - 1; i++)
        {
            if (A[i] > A[i + 1])
            {
                return false;
            }
        }

        return true;
    }
};

//{ Driver Code Starts.
int main()
{

    int T;
    cin >> T;
    while (T--)
    {
        int N, D;
        cin >> N >> D;
        vector<int> A(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];
        Solution ob;
        if (ob.check(D, N, A))
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }

    return 0;
}
// } Driver Code Ends