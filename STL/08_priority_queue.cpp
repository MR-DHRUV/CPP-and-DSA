#include <bits/stdc++.h>
using namespace std;

int main()
{
    // priority queue ek aisa data structure haii jisme humesha 1st element greatest hota haii , and it is callled max heap

    // min heap me convert hojata haii , jisme 1st element smallest hota haii

    // default max hota haii
    priority_queue<int> maxH;

    maxH.push(1);
    maxH.push(3);
    maxH.push(2);
    maxH.push(0);

    cout << maxH.size() << endl;

    // dirtectly maxH.size() use ni kr skte print krne ke lie kyuki pop decreases the size;
    int n = maxH.size();

    for (int i = 0; i < n; i++)
    {
        cout << maxH.top() << " ";
        // only top element is accesses so to print all elements we need to pop them
        maxH.pop();
    }

    // min _heap
    priority_queue<int, vector<int>, greater<int>> minH;

    minH.push(1);
    minH.push(3);
    minH.push(2);
    minH.push(0);

    cout << endl<< minH.size() << endl;

    // dirtectly maxH.size() use ni kr skte print krne ke lie kyuki pop decreases the size;
    int j = minH.size();

    for (int i = 0; i < j; i++)
    {
        cout << minH.top() << " ";
        // only top element is accesses so to print all elements we need to pop them
        minH.pop();
    }

    return 0;
}