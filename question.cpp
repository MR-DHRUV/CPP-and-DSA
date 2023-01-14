//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    vector<int> maximumToys(int N, vector<int> A, int Q, vector<vector<int>> Queries)
    {
        // for each query construct a min heap with only non defective elements
        vector<int> ans;

        vector<vector<int>> mp;
        for (int i = 0; i < N; i++)
        {
            mp.push_back({A[i], i});
        }

        // replace minHeap in O(1)
        sort(mp.begin(), mp.end());

        // value vs index map
        // multimap as there can me more than 1 index corresponding to a value
        multimap<int, int> mpp;

        // calc prefix sum
        vector<long long int> prefixSum(N);
        long long int s = 0;
        for (int i = 0; i < mp.size(); i++)
        {
            s += mp[i][0];
            prefixSum[i] = (s);
            mpp.insert({mp[i][0], i});
        }

        // serving Queries
        for (int i = 0; i < Q; i++)
        {
            int cash = Queries[i][0];

            if (cash < prefixSum[0])
            {
                ans.push_back(0);
                continue;
            }

            // finding smallest sum that is greater or equal to cash
            int idx = lower_bound(prefixSum.begin(), prefixSum.end(), cash) - prefixSum.begin();

            // since lower bound can give a value that is greater than cash or if the cash is so large that there is no lower bound of it, so in these 2 cases we need to point our idx to a previous index
            if (idx == prefixSum.size() || prefixSum[idx] != cash)
            {
                idx--;
                cash = prefixSum[idx];
            }

            // no of elements included till any index in prefix sum is equal to index itself
            int no_of_toys = idx + 1;

            //
            unordered_set<int> st;

            // when there are defective elements in the query
            if (Queries[i][1] != 0)
            {
                for (int k = 2; k < Queries.size(); k++)
                {
                    // 1 based index
                    --Queries[i][k];

                    // cost of defective
                    int defective = A[Queries[i][k]];

                    // find an index corresponding to defective value
                    auto it = mpp.find(defective);

                    // putting index of defective item into set which are not incuded in prefix sum till idx
                    if (it->second > idx)
                    {
                        st.insert(Queries[i][k]);
                    }
                    else
                    {
                        // removing defective items that are included
                        cash -= defective;
                        no_of_toys--;
                    }
                }
            }

            idx++;

            // checking if can add a few items after maximising
            while (idx < mp.size() && cash + mp[idx][0] <= Queries[i][0])
            {
                if (st.find(mp[idx][1]) == st.end())
                {
                    no_of_toys++;
                    cash += mp[idx][0];
                }
                idx++;
            }

            ans.push_back(no_of_toys);
        }

        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int N;
        cin >> N;
        vector<int> A(N);
        for (auto &i : A)
        {
            cin >> i;
        }
        int Q;
        cin >> Q;
        vector<vector<int>> Queries(Q);
        for (int i = 0; i < Q; i++)
        {
            int x, y;
            cin >> x >> y;
            Queries[i].push_back(x);
            Queries[i].push_back(y);
            for (int j = 0; j < Queries[i][1]; j++)
            {
                cin >> x;
                Queries[i].push_back(x);
            }
        }
        Solution obj;
        auto ans = obj.maximumToys(N, A, Q, Queries);
        for (auto i : ans)
            cout << i << " ";
        cout << endl;
    }
}
// } Driver Code Ends