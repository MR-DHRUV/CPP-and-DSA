#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// <base_type_of_data, mapped_type, comparator, root_data_structue, update_policy>
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> orderedSet;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> orderedMultiSet;

vector<int> kmp(string &text, string &pattern)
{
    int n = text.size(), m = pattern.size(), i = 1, len = 0, j = 0;
    vector<int> lps(m, 0), ans;

    while (i < m)
    {
        if (pattern[i] == pattern[len])
            lps[i++] = ++len;
        else
        {
            if (len != 0)
                len = lps[len - 1];
            else
            {
                lps[i] = len;
                i++;
            }
        }
    }

    i = 0;

    while (n - i >= m - j)
    {
        if (text[i] == pattern[j])
        {
            i++;
            j++;
        }

        if (j == m)
        {
            ans.push_back(i - j);
            j = lps[j - 1];
        }
        else if (i < n && text[i] != pattern[j])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    return ans;
}

int main()
{
  
  
    return 0;
}