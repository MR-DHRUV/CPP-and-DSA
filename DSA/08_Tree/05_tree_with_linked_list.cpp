#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *lchild;
    Node *rchild;

    Node(int x) : data(x), lchild(NULL), rchild(NULL){};
};

class BinTree
{
    // it will store address of nodes in level by level order for inserting elements
    // iske top pr us node ka address rahega jiska ya toh left ya right khaali ho
    // jab bhar jayga koi node toh uska address hata denge
    queue<Node *> q;
    Node *head;

public:
    BinTree(int x)
    {
        // creating and storing head node
        Node *t = new Node(x);
        head = t;
        q.push(t);
    }

    void insert(int x);
    void create();

    // total calls : n + (n+1) = 2n+1 = O(n)
    // n for non leaf nodes
    // since for n non leaf nodes there will be n+1 leaf nodes , so n+1 calls will be made
    // size of the stack : height + 2 = level + 1
    void preorder();
    void inorder();
    void postorder();

    // O(n) same as reccursive
    void preorderIter();
    void inorderIter();
    void postorderIter();

    void levelorder();
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
            p->lchild = next;
            q.push(next);
        }

        cout << "Enter the right child of " << p->data << " : ";
        cin >> temp;

        if (temp != -1)
        {
            Node *next = new Node(temp);
            p->rchild = next;
            q.push(next);
        }
    }
};

void pre(Node *p)
{
    if (p == NULL)
    {
        return;
    }

    // node
    cout << p->data << " ";

    // left
    pre(p->lchild);

    // right
    pre(p->rchild);
};

void in(Node *p)
{
    if (p == NULL)
    {
        return;
    }

    // left
    in(p->lchild);

    // node
    cout << p->data << " ";

    // right
    in(p->rchild);
};

void post(Node *p)
{
    if (p == NULL)
    {
        return;
    }

    // left
    post(p->lchild);

    // right
    post(p->rchild);

    // node
    cout << p->data << " ";
};

void BinTree ::preorder()
{
    pre(head);
    cout << endl;
};

void BinTree ::inorder()
{
    in(head);
    cout << endl;
};

void BinTree ::postorder()
{
    post(head);
    cout << endl;
};

void BinTree ::preorderIter()
{
    // iterative version of pre order traversal
    Node *t = head;
    stack<Node *> st;

    while (t != NULL || st.empty() == false)
    {
        if (t != NULL)
        {
            // printing the data
            cout << t->data << " ";

            // storing the data
            st.push(t);

            // pointing t to its left child
            t = t->lchild;
        }
        else
        {
            // getting latest not null address
            t = st.top();
            st.pop();

            // pointing it to its right child
            t = t->rchild;
        }
    }

    cout << endl;
};

void BinTree ::inorderIter()
{
    // iterative version of pre order traversal
    Node *t = head;
    stack<Node *> st;

    while (t != NULL || st.empty() == false)
    {

        // sabse pahle sabse last wale left pr le jao
        if (t != NULL)
        {
            // storing the data
            st.push(t);

            // pointing t to its left child
            t = t->lchild;
        }
        else
        {
            // ab last se element print hoga aur uska right bhi sath me concider krna hoga

            // getting latest not null address
            t = st.top();
            st.pop();

            // printing the data
            cout << t->data << " ";

            // pointing it to its right child
            t = t->rchild;
        }
    }

    cout << endl;
};

void BinTree ::postorderIter()
{
    // iterative version of pre order traversal
    Node *t = head;
    stack<Node *> st;
    long long int temp;
    while (t != NULL || st.empty() == false)
    {

        // sabse pahle sabse last wale left pr le jao
        if (t != NULL)
        {
            // storing the data
            st.push(t);

            // pointing t to its left child
            t = t->lchild;
        }
        else
        {
            // ab last se element print hoga aur uska right bhi sath me concider krna hoga

            // getting latest not null address
            temp = (long long int)st.top();
            st.pop();
            // cout<<"Temp : "<<temp<<endl;

            if (temp > 0)
            {
                // store the negitive address for printing
                Node *c = (Node *)(temp * (-1));
                st.push(c);

                // pointing it to its right child
                t = ((Node *)temp)->rchild;
            }
            else
            {
                // printing the data
                cout << ((Node *)(temp * (-1)))->data << " ";

                // making t as null so that we can continue printing other elements
                t = NULL;
            }
        }
    }

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
        Node *i = qt.front();
        qt.pop();

        cout << i->data << " ";

        if (i->lchild != NULL)
        {
            qt.push(i->lchild);
        }
        if (i->rchild != NULL)
        {
            qt.push(i->rchild);
        }
    }

    cout << endl;
};

int main()
{
    BinTree t(1);
    t.create();
    t.preorder();
    t.preorderIter();
    t.inorder();
    t.inorderIter();
    t.postorder();
    t.postorderIter();

    t.levelorder();

    return 0;
}