#include <bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// <base_type_of_data, mapped_type, comparator, root_data_structue, update_policy>
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> orderedSet;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> orderedMultiSet;

int main()
{
    // The second data structure is ordered set
    // Std::set does not provide us 2 very important functions
    // 1 Order/index of any key
    // 2 key at index

    // Say we are solving a problem like
    // We will be given Q queries in which we can either insert or remove an element
    // No we need to find no of elements smaller then an element and index of an given element in the set

    // we can either use segment tree for it, but we can quickly use this DS for such purpose
    orderedSet st;

    st.insert(5);
    st.insert(3);
    st.insert(4);
    st.insert(1);
    st.insert(7);

    cout << st.order_of_key(6) << endl;
    cout << *st.find_by_order(2) << endl;
    cout << *st.find_by_order(0) << endl;

    for(auto &i : st)
        cout << i << " ";
    cout << endl;

    return 0;
}