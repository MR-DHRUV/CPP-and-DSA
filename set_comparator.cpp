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
    vector<vector<int>> kTop(vector<int> &arr, int N, int K)
    {
        auto cmp = [](const pair<int, int> &a, const pair<int, int> &b) -> bool
        {
            if (a.first == b.first)
                return a.second < b.second;

            return a.first > b.first;
        };

        set<pair<int, int>, decltype(cmp)> st(cmp);

        unordered_map<int, int> freq;
        vector<vector<int>> ans;

        for (int i = 0; i < N; i++)
        {
            int f = ++freq[arr[i]], j = 0;
            st.erase({f - 1, arr[i]});
            st.insert({f, arr[i]});
            vector<int> r;

            for (auto &it : st)
            {
                if (j == K)
                    break;

                r.push_back(it.second);
            }

            ans.push_back(r);
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

        int K;
        scanf("%d", &K);

        vector<int> a(N);
        Array::input(a, N);

        Solution obj;
        vector<vector<int>> res = obj.kTop(a, N, K);

        for (auto it : res)
            Array::print(it);
    }
}

// } Driver Code Ends