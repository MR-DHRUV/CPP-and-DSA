#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) : data(x), left(NULL), right(NULL){};
};

class BinTree
{
    // it will store address of nodes in level by level order for inserting elements
    // iske top pr us node ka address rahega jiska ya toh left ya right khaali ho
    // jab bhar jayga koi node toh uska address hata denge
    queue<Node *> q;
    Node *head;

public:
    BinTree(){};
    BinTree(int x)
    {
        // creating and storing head node
        Node *t = new Node(x);
        head = t;
        q.push(t);
    }

    void create();

    void inorder();

    void levelorder();

    void buildFromLevelOrder(vector<int> arr);

    Node *searchBst(int target);
    Node *searchBstIter(int target);
};

void BinTree ::create()
{
    while (q.empty() == false)
    {
        // getting position where we need to add next element
        Node *p = q.front();
        q.pop();

        cout << "Enter the left child of  " << p->data << " : ";
        int temp;
        cin >> temp;

        // -1 ka matlab haii ki we dont want any node at that place , so continue
        if (temp != -1)
        {
            Node *next = new Node(temp);
            p->left = next;
            q.push(next);
        }

        cout << "Enter the right child of " << p->data << " : ";
        cin >> temp;

        if (temp != -1)
        {
            Node *next = new Node(temp);
            p->right = next;
            q.push(next);
        }
    }
};

void in(Node *p)
{
    if (p == NULL)
    {
        return;
    }

    // left
    in(p->left);

    // node
    cout << p->data << " ";

    // right
    in(p->right);
};

void BinTree ::inorder()
{
    in(head);
    cout << endl;
};

void BinTree ::levelorder()
{
    // base case
    if (head == NULL)
    {
        cout << "Tree is empty" << endl;
        return;
    }

    queue<Node *> qt;

    // initialization
    qt.push(head);

    // node ka data print karo aur uske not null nodes daaldo queue me printhone ke lie
    // isse level by level print hoga aur order bni bana rahega
    while (qt.empty() == false)
    {
        Node *f = qt.front();
        qt.pop();

        cout << f->data << " ";

        if (f->left != NULL)
        {
            qt.push(f->left);
        }
        if (f->right != NULL)
        {
            qt.push(f->right);
        }
    }

    cout << endl;
};

void BinTree::buildFromLevelOrder(vector<int> arr)
{
    if (arr.size() < 1)
    {
        return;
    }

    // initialization
    Node *a = new Node(arr[0]);
    head = a;

    queue<Node *> q;
    q.push(head);

    for (int i = 1; i < arr.size(); i++)
    {
        Node *t = q.front();
        q.pop();

        // making left node
        if (arr[i] != -1)
        {
            Node *next = new Node(arr[i]);
            t->left = next;
            q.push(next);
        }

        // making right node
        i++;
        if (arr[i] != -1 && i < arr.size())
        {
            Node *next = new Node(arr[i]);
            t->right = next;
            q.push(next);
        }
    }
}

Node *search(Node *t, int target)
{
    if (t == NULL)
    {
        return NULL;
    }

    // equal
    if (t->data == target)
    {
        return t;
    }
    else if (t->data > target)
    {
        // left will have smaller elements
        return search(t->left, target);
    }
    else
    {
        // right will have smaller elements
        return search(t->right, target);
    }
}

Node *BinTree ::searchBst(int target)
{
    return search(head, target);
}

Node *BinTree ::searchBstIter(int target)
{
    Node *t = head;

    while (t != NULL)
    {
        if (t->data == target)
        {
            return t;
        }
        else if (t->data > target)
        {
            t = t->left;
        }
        else
        {
            t = t->right;
        }
    }

    return NULL;
}

int main()
{
    BinTree b;

    // input in bst fashion
    vector<int> v = {30, 20, 40, 10, 25, 35, 50};

    b.buildFromLevelOrder(v);
    b.levelorder();

    // sorted hoga for bst;
    b.inorder();

    Node *ans = b.searchBstIter(35);

    if (ans)
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}
