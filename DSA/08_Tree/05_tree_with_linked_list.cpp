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

    int countNodes();
    int count1Nodes();
    int count2Nodes();
    int countLeafNodes();

    int sumTree();
    int height();

    void buildFromLevelOrder(vector<int> arr);
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

void pre(Node *p)
{
    if (p == NULL)
    {
        return;
    }

    // node
    cout << p->data << " ";

    // left
    pre(p->left);

    // right
    pre(p->right);
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

void post(Node *p)
{
    if (p == NULL)
    {
        return;
    }

    // left
    post(p->left);

    // right
    post(p->right);

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
            t = t->left;
        }
        else
        {
            // getting latest not null address
            t = st.top();
            st.pop();

            // pointing it to its right child
            t = t->right;
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
            t = t->left;
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
            t = t->right;
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
            t = t->left;
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
                t = ((Node *)temp)->right;
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

// here things are happening in post order , left right count
int count(Node *h)
{
    // base condition
    if (h == NULL)
    {
        return 0;
    }

    // counting left and right nodes
    int x = count(h->left);
    int y = count(h->right);

    // +1 for current node
    return (x + y + 1);
}

int BinTree ::countNodes()
{
    // same 2n+1 calls isme bhi -> O(n)
    return count(head);
}

int count1(Node *h)
{
    // base condition
    if (h == NULL)
    {
        return 0;
    }

    // counting left and right nodes
    int x = count1(h->left);
    int y = count1(h->right);

    // +1 for current node

    if ((h->left == NULL && h->right != NULL) || (h->left != NULL && h->right == NULL))
    {
        return (x + y + 1);
    }

    return x + y;
}

int BinTree ::count1Nodes()
{
    // same 2n+1 calls isme bhi -> O(n)
    return count1(head);
}

int count2(Node *h)
{
    // base condition
    if (h == NULL)
    {
        return 0;
    }

    // counting left and right nodes
    int x = count2(h->left);
    int y = count2(h->right);

    if (h->left != NULL && h->right != NULL)
    {
        return (x + y + 1);
    }

    return x + y;
}

int BinTree ::count2Nodes()
{
    // same 2n+1 calls isme bhi -> O(n)
    return count2(head);
}

int countLeaf(Node *h)
{
    // base condition
    if (h == NULL)
    {
        return 0;
    }

    // counting left and right nodes
    int x = countLeaf(h->left);
    int y = countLeaf(h->right);

    if (h->left == NULL && h->right == NULL)
    {
        return (x + y + 1);
    }

    return x + y;
}

int BinTree ::countLeafNodes()
{
    // same 2n+1 calls isme bhi -> O(n)
    return countLeaf(head);
}

int sum(Node *h)
{
    // base condition
    if (h == NULL)
    {
        return 0;
    }

    // counting left and right nodes
    int x = sum(h->left);
    int y = sum(h->right);

    // right ka sum + left ka sum + current node ka data
    return (x + y + h->data);
}

int BinTree ::sumTree()
{
    // same 2n+1 calls isme bhi -> O(n)
    return sum(head);
}

int heightCalc(Node *h)
{
    // base condition
    if (h == NULL)
    {
        return 0;
    }

    // counting left and right nodes
    int x = heightCalc(h->left);
    int y = heightCalc(h->right);

    // har point par us subtree ki max possible height return krega
    return max(x, y) + 1;
}

int BinTree ::height()
{
    // same 2n+1 calls isme bhi -> O(n)
    return heightCalc(head);
}

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

int main()
{
    // BinTree t(1);
    // t.create();
    // t.preorder();
    // t.preorderIter();
    // t.inorder();
    // t.inorderIter();
    // t.postorder();
    // t.postorderIter();

    // t.levelorder();

    // cout << "Nodes : " << t.countNodes() << endl;
    // cout << "0 Nodes : " << t.countLeafNodes() << endl;
    // cout << "1 Nodes : " << t.count1Nodes() << endl;
    // cout << "2 Nodes : " << t.count2Nodes() << endl;
    // cout << "Sum : " << t.sumTree() << endl;
    // cout << "Height : " << t.height() << endl;

    BinTree b;
    vector<int> v = {1, 2, 3, 4, 5, 6, 7 , 8};

    b.buildFromLevelOrder(v);
    b.levelorder();
    b.preorder();
    b.inorder();
    b.postorder();

    return 0;
}
