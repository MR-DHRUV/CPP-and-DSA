//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data, height;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        height = 1;
        left = right = NULL;
    }
};

int setHeights(Node *n)
{
    if (!n)
        return 0;
    n->height = 1 + max(setHeights(n->left), setHeights(n->right));
    return n->height;
}

Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    setHeights(root);
    return root;
}

bool isBST(Node *n, int lower, int upper)
{
    if (!n)
        return 1;
    if (n->data <= lower || n->data >= upper)
        return 0;
    return isBST(n->left, lower, n->data) && isBST(n->right, n->data, upper);
}

pair<int, bool> isBalanced(Node *n)
{
    if (!n)
        return pair<int, bool>(0, 1);

    pair<int, bool> l = isBalanced(n->left);
    pair<int, bool> r = isBalanced(n->right);

    if (abs(l.first - r.first) > 1)
        return pair<int, bool>(0, 0);

    return pair<int, bool>(1 + max(l.first, r.first), l.second && r.second);
}

bool isBalancedBST(Node *root)
{
    if (!isBST(root, INT_MIN, INT_MAX))
        cout << "BST voilated, inorder traversal : ";

    else if (!isBalanced(root).second)
        cout << "Unbalanced BST, inorder traversal : ";

    else
        return 1;
    return 0;
}

void printInorder(Node *n)
{
    if (!n)
        return;
    printInorder(n->left);
    cout << n->data << " ";
    printInorder(n->right);
}

struct Node *deleteNode(struct Node *root, int data);

int main()
{
    int t;
    cin >> t;
    getchar();

    while (t--)
    {
        string s;
        getline(cin, s);
        Node *root = buildTree(s);

        int n;
        cin >> n;
        int ip[n];
        for (int i = 0; i < n; i++)
            cin >> ip[i];

        for (int i = 0; i < n; i++)
        {
            root = deleteNode(root, ip[i]);

            if (!isBalancedBST(root))
                break;
        }

        if (root == NULL)
            cout << "null";
        else
            printInorder(root);
        cout << endl;

        getline(cin, s); // to deal with newline char
    }
    return 1;
}

// } Driver Code Ends

/* Node is as follows:

struct Node
{
    int data, height;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        height = 1;
        left = right = NULL;
    }
};

*/

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
    root->left = cr;
    b->right = cl;

    // changing heights
    c->height = getHeight(c);
    root->height = getHeight(root);

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
    root->right = cl;
    b->left = cr;

    // changing heights
    c->height = getHeight(c);
    root->height = getHeight(root);

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
    b->height = getHeight(b);
    root->height = getHeight(root);

    return b;
}

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
    else if (getBalanceFactor(root) == -2 && (getBalanceFactor(root->right) == 1 || getBalanceFactor(root->right) == 0))
    {
        return RLRotation(root);
    }
    // case 4 : RR
    else if (getBalanceFactor(root) == -2 && (getBalanceFactor(root->right) == -1))
    {
        return RRRotation(root);
    }

    return root;
}

Node *deleteNode(Node *root, int data)
{
    root = delR(root, data);
    return root;
}


/*
48 15 77 1 36 60 93 N N 24 38 55 62 86 99 N N N N N N N 65
12
24 65 15 62 48 60 1 99 55 38 77 36

74 21 79 11 41 76 93 9 19 33 67 N N 86 N 6 N N N 23 N 44 73
15
93 74 41 33 44 21 6 67 23 73 79 11 19 86 9

43 19 65 14 23 58 83 10 15 22 28 51 64 73 84 1 N N N N N N N 44 N N N N 76 N 87
16
23 58 10 44 19 14 43 22 64 1 87 73 83 15 51 28

*/