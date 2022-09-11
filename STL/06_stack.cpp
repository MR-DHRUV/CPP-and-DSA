#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<string> s;
    // LIFO

    s.push("Dhruv");
    s.push("Gupta");

    //in tsack we can only access element on top that is the  last element

    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;

    return 0;
}