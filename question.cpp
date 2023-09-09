#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
    class Cmp
    {
    public:
        bool operator()(const ListNode *a, const ListNode *b)
        {
            return a->val > b->val;
        }
    };

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {

        multiset<ListNode *, Cmp> st;

        for (auto head : lists)
        {
            while (head != NULL)
            {
                st.insert(head);
                head = head->next;
            }
        }

        ListNode *head = new ListNode(-1), *temp = head;

        for (auto it : st)
        {
            temp->next = it;
            temp = temp->next;
        }

        temp->next = NULL;
        return head->next;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main()
{

    return 0;
}