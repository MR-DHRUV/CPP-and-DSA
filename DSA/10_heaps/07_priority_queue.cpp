#include <bits/stdc++.h>
using namespace std;

int main()
{
    // priority queue
    // we can make min/max heap using priority queue

    // max heap
    priority_queue<int> pq;

    pq.push(1);
    pq.push(3);
    pq.push(2);
    pq.push(5);
    pq.push(5);
    pq.push(3);

    // max element is there at top
    cout << pq.top() << endl;
    pq.pop();

    cout << pq.top() << endl;
    pq.pop();

    cout << pq.top() << endl;
    pq.pop();

    cout<<"Min Heap"<<endl;

    // min heap
    priority_queue<int, vector<int>, greater<int>> min_heap;

    min_heap.push(1);
    min_heap.push(3);
    min_heap.push(2);
    min_heap.push(1);
    min_heap.push(5);
    min_heap.push(3);

    // min element is there at top
    cout << min_heap.top() << endl;
    min_heap.pop();

    cout << min_heap.top() << endl;
    min_heap.pop();

    cout << min_heap.top() << endl;
    min_heap.pop();


    

    return 0;
}