#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {1, 3, 6, 6, 6, 6, 7};

    // 1 Binary Search
    cout << binary_search(v.begin(), v.end(), 5) << endl;
    cout << binary_search(v.begin(), v.end(), 3) << endl;

    // will return index of element greater than or equal to 6 in the given range
    cout << lower_bound(v.begin(), v.end(), 6) - v.begin() << endl;

    // will return index of element greater than 6 in the given range
    cout << upper_bound(v.begin(), v.end(), 6) - v.begin() << endl;

    // kaha se , kitna , kaha tk
    // iscase me 1 baar rotate hoga
    rotate(v.begin(), v.begin() + 1, v.end());

    for (int i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    vector<int> v1 = {10, 3, 8, 6, 6, 7};


    // based on intro sort that is combination of 3 sorts, quick sort , heap sort and insertion sort 
    sort(v1.begin(), v1.end());

    for (int i : v1)
    {
        cout << i << " ";
    }
    cout << endl;



    ///////////////////////////////////////////////////////////////////////////////////////
    int a = 3;
    int b = 5;

    cout << max(a, b) << endl;
    cout << min(a, b) << endl;

    swap(a, b);

    cout << a << endl;

    ///////////////////////////////////////////////////////////////////////////////////////

    string myStr = "abc";
    reverse(myStr.begin(), myStr.end());

    cout << myStr << endl;

    return 0;
}