#include <bits/stdc++.h>
using namespace std;

int main()
{
    // initial size of vector is 0 and its capacity is also 0
    vector<int> v;
    cout << v.capacity() << endl;

    // adding elements in last
    v.push_back(1);
    cout << v.capacity() << endl;

    // when an element is added in vector and it runs out of space, then its size gets doubbled
    v.push_back(1);
    cout << v.capacity() << endl;

    v.push_back(1);
    cout << v.capacity() << endl;

    // getting of ofcurrent elements
    cout << v.size() << endl;

    // accessing elements
    cout << v[0] << endl;
    cout << v.at(0) << endl;

    /// front and back
    cout << v.front() << endl;
    cout << v.back() << endl;

    // removing last element
    v.pop_back();

    // clearing whole vector
    v.clear();
    cout << v.size() << endl;

    // constructors

    // initialised a vector of size 5 with all elements as 0
    vector<int> H(5, 0);

    // make a replica of a vector;
    vector<int> Hcopy(H);

    // inserts 566 in the first place as iterator is starting from begaining
    vector<int>::iterator iter = v.begin();
    v.insert(iter, 566);

    //(iterator, no of copies , value)
    v.insert(iter + 2, 5, 566);

    return 0;
}