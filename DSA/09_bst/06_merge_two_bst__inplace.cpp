#include <bits/stdc++.h>
using namespace std;

template <class T>
class TreeNode
{

public:
    T data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void printList(TreeNode<int> *p)
{
    // while address of next block is not null
    while (p != NULL)
    {
        cout << (p->data) << " ";
        p = p->right;
    }

    cout << endl;
}

void bstToSortedList(TreeNode<int> *root, TreeNode<int> *&head, TreeNode<int> *&prev)
{
    if (root == NULL)
    {
        return;
    }

    bstToSortedList(root->left, head, prev);

    if (prev == NULL)
    {
        prev = root;
        prev->left = NULL;
        head = root;
    }
    else
    {
        prev->right = root;
        root->left = prev;
        prev = root;
    }

    bstToSortedList(root->right, head, prev);
}

TreeNode<int> *mergeList(TreeNode<int> *head1, TreeNode<int> *head2)
{
    if (head1 == NULL && head2 == NULL)
    {
        return NULL;
    }
    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }

    TreeNode<int> *ans = new TreeNode<int>(-1);
    TreeNode<int> *t = ans;

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            t->right = head1;
            head1 = head1->right;
            t = t->right;
        }
        else
        {
            t->right = head2;
            head2 = head2->right;
            t = t->right;
        }
    }

    while (head1 != NULL)
    {
        t->right = head1;
        head1 = head1->right;
        t = t->right;
    }

    while (head2 != NULL)
    {
        t->right = head2;
        head2 = head2->right;
        t = t->right;
    }

    ans = ans->right;
    ans->left = NULL;
}

int count(TreeNode<int> *head)
{
    int ans = 0;
    while (head != NULL)
    {
        ans++;
        head = head->right;
    }

    return ans;
}

TreeNode<int> *sortedLLToBST(TreeNode<int> *&head, int n)
{
    // base case
    if (n <= 0 || head == NULL)
    {
        return NULL;
    }

    // left part
    TreeNode<int> *left = sortedLLToBST(head, n / 2);
    TreeNode<int> *root = head;
    root->left = left;

    head = head->right;

    root->right = sortedLLToBST(head, n - (n / 2) - 1);

    return root;
}

TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2)
{

    // approach 2 time : O(m+n), space : O(h1+Oh2)
    // convert both trees into sorted doubble linked list
    // merge them
    // sorted list to bst inplace that is in O(1) space;

    TreeNode<int> *head1 = NULL;
    TreeNode<int> *head2 = NULL;
    TreeNode<int> *prev1 = NULL;
    TreeNode<int> *prev2 = NULL;

    bstToSortedList(root1, head1, prev1);
    bstToSortedList(root2, head2, prev2);

    prev1->right = NULL;
    prev2->right = NULL;

    TreeNode<int> *head = mergeList(head1, head2);
    int n = count(head);

    //     cout<<"List : ";
    //     printList(head);

    TreeNode<int> *ans = sortedLLToBST(head, n);

    return ans;
}


int main()
{
    
    return 0;
}
