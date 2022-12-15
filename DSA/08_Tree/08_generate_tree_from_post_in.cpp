//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.
Node *builder(int in[], int post[], int &index, int inorderStart, int inorderEnd, map<int, int> &elementToIndex)
{
    // checking if index lies in range of post order
    if (index < 0)
    {
        return NULL;
    }

    // for excessive calls
    if (inorderStart > inorderEnd)
    {
        return NULL;
    }

    // creating a new node
    int element = post[index--];
    Node *temp = new Node(element);

    int position = elementToIndex[element];

    // further calls
    // post me pahle right ki call jaygi
    temp->right = builder(in, post, index, position + 1, inorderEnd, elementToIndex);
    temp->left = builder(in, post, index, inorderStart, position - 1, elementToIndex);

    return temp;
}

// Function to return a tree created from postorder and inoreder traversals.
Node *buildTree(int in[], int post[], int n)
{

    // storing the index vs element map to get index of any element of inorder in 0(1) time
    map<int, int> elementToIndex;

    for (int i = 0; i < n; i++)
    {
        elementToIndex[in[i]] = i;
    }

    int postOrderStart = n-1;

    Node *ans = builder(in, post, postOrderStart, 0, n - 1, elementToIndex);

    return ans;
}

