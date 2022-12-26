#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;

    //  fot maintaining balance factor
    int height;

    Node *left;
    Node *right;

    Node(){};
    Node(int x, int h) : data(x), height(h), left(NULL), right(NULL){};
};

class AVL
{

public:
    Node *root;
    AVL()
    {
        root = NULL;
    };
    void insert(int e);
    void inorder();
    void bulid(vector<int> arr);
    void del(int e);
};

int getHeight(Node *root)
{
    int hl = root && root->left ? root->left->height : 0;
    int hr = root && root->right ? root->right->height : 0;

    return max(hl, hr) + 1;
}

int getBalanceFactor(Node *root)
{
    int hl = root && root->left ? root->left->height : 0;
    int hr = root && root->right ? root->right->height : 0;

    return hl - hr;
}

Node *LLRotation(Node *root)
{
    Node *b = root->left;

    // b's children
    Node *br = b->right;

    // changing links
    b->right = root;

    // placing b's children
    root->left = br;

    // changing heights
    root->height = getHeight(root);
    b->height = getHeight(b);

    // now b will be the new root
    return b;
}

Node *LRRotation(Node *root)
{
    // root->left
    Node *b = root->left;

    // root->left->right
    Node *c = b->right;

    // c's children
    Node *cl = c->left;
    Node *cr = c->right;

    // changing links
    c->left = b;
    c->right = root;

    // placing c's children
    b->right = cl;
    root->left = cr;

    // changing heights
    b->height = getHeight(b);
    root->height = getHeight(root);
    c->height = getHeight(c);

    return c;
}

Node *RLRotation(Node *root)
{
    // root->right
    Node *b = root->right;

    // root->right->left
    Node *c = b->left;

    // c's children
    Node *cl = c->left;
    Node *cr = c->right;

    // changing links
    c->right = b;
    c->left = root;

    // placing c's children
    b->left = cr;
    root->right = cl;

    // changing heights
    b->height = getHeight(b);
    root->height = getHeight(root);
    c->height = getHeight(c);

    return c;
}

Node *RRRotation(Node *root)
{
    // root->right
    Node *b = root->right;

    // b's left children
    Node *bl = b->left;

    // changing links
    b->left = root;

    // placing b's children
    root->right = bl;

    // changing heights
    root->height = getHeight(root);
    b->height = getHeight(b);

    return b;
}

Node *rInsert(Node *root, int e)
{
    // base case
    if (root == NULL)
    {
        // leaf node is always at height 1
        Node *t = new Node(e, 1);
        return t;
    }

    // finding and inserting the node : O(logN)
    if (root->data > e)
    {
        root->left = rInsert(root->left, e);
    }
    else if (root->data < e)
    {
        root->right = rInsert(root->right, e);
    }

    // now at returning time of every call we'll update the height of whole path that is followed
    // O(1)
    root->height = getHeight(root);

    // now checking if the node is balanced or not
    // Rotaion complexity : O(1)

    // case 1 : LL
    if (getBalanceFactor(root) == 2 && getBalanceFactor(root->left) == 1)
    {
        return LLRotation(root);
    }
    // case 2 : LR
    else if (getBalanceFactor(root) == 2 && getBalanceFactor(root->left) == -1)
    {
        return LRRotation(root);
    }
    // case 3 : RL
    else if (getBalanceFactor(root) == -2 && getBalanceFactor(root->right) == 1)
    {
        return RLRotation(root);
    }
    // case 4 : RR
    else if (getBalanceFactor(root) == -2 && getBalanceFactor(root->right) == -1)
    {
        return RRRotation(root);
    }

    return root;
}

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

void AVL ::inorder()
{
    in(root);
    cout << endl;
};

// on insertion in avl trees we must set the height
// O(logN)
void AVL ::insert(int e)
{
    // we are taking value in root as root can ablso be updated
    root = rInsert(root, e);
    // cout<<root->data;
}

Node *buildFromInorder(vector<int> in, int start, int end)
{
    // base condition
    if (start > end)
    {
        return NULL;
    }

    int mid = start + ((end - start) / 2);
    Node *t = new Node(in[mid], 1);

    t->left = buildFromInorder(in, start, mid - 1);
    t->right = buildFromInorder(in, mid + 1, end);

    // set height at return time
    t->height = getHeight(t);

    return t;
}

void AVL ::bulid(vector<int> arr)
{
    // Approach : Inorder to bst gives height balanced bst
    sort(arr.begin(), arr.end());

    root = buildFromInorder(arr, 0, arr.size() - 1);
};

Node *delR(Node *root, int e)
{
    // base case
    if (root == NULL)
    {
        return NULL;
    }

    // deleting leaf node
    if (root->left == NULL && root->right == NULL && root->data == e)
    {
        delete (root);
        return NULL;
    }

    // search the node to be deleted
    if (root->data == e)
    {
        int hl = root->left ? root->left->height : 0;
        int hr = root->right ? root->right->height : 0;

        // hl > hr
        if (hl > hr)
        {
            Node *pre = root->left;
            while (pre->right != NULL)
            {
                pre = pre->right;
            }

            // del that node
            root->data = pre->data;

            // delete pre from left
            root->left = delR(root->left, pre->data);
        }
        else
        {
            Node *succ = root->right;
            while (succ->left != NULL)
            {
                succ = succ->left;
            }

            // del that node
            root->data = succ->data;

            // delete succ from right
            root->right = delR(root->right, succ->data);
        }
    }
    else if (root->data > e)
    {
        root->left = delR(root->left, e);
    }
    else
    {
        root->right = delR(root->right, e);
    }

    // updating height of path followed
    root->height = getHeight(root);

    // now checking if the node is balanced or not 
    // see cases from register
    // Rotaion complexity : O(1)

    // case 1 : LL
    if (getBalanceFactor(root) == 2 && (getBalanceFactor(root->left) == 1 || getBalanceFactor(root->left) == 0))
    {   
        return LLRotation(root);
    }
    // case 2 : LR
    else if (getBalanceFactor(root) == 2 && getBalanceFactor(root->left) == -1)
    {   
        return LRRotation(root);
    }
    // case 3 : RL
    else if (getBalanceFactor(root) == -2 && getBalanceFactor(root->right) == 1)
    {   
        return RLRotation(root);
    }
    // case 4 : RR
    else if (getBalanceFactor(root) == -2 && (getBalanceFactor(root->right) == -1 || getBalanceFactor(root->right) == 0))
    {   
        return RRRotation(root);
    }

    return root;
}

void AVL ::del(int e)
{
    root = delR(root, e);
};

int main()
{
    AVL a;
    a.insert(30);
    a.insert(40);
    a.insert(10);
    a.insert(20);
    a.inorder();
    cout << a.root->data << endl;


    // AVL a;
    // a.bulid({1, 4, 3, 2, 5, 6, 9, 8, 7});
    // a.inorder();


    a.del(40);
    a.inorder();
    cout << a.root->data << endl;
    

    // a.del(2);
    // a.inorder();

    // a.del(7);
    // a.inorder();

    // a.del(4);
    // a.inorder();

    // a.del(1);
    // a.inorder();

    return 0;
}