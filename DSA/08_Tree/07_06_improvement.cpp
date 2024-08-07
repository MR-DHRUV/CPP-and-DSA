//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void printPostOrder(Node *root)
{
    if (root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution
{

    // To decrese our complexity to O(N) from N^2
    void createMapping(int in[], map<int,int> &nodeToIndex, int n)
    {
        for (int i = 0; i < n; i++)
        {
            nodeToIndex[in[i]] = i;
        }
    }

    // we need to retain the index this we are taking it by refrance
    Node *solve(int in[], int pre[], int &index, int inorderStart, int inorderEnd, int n , map<int,int> nodeToIndex)
    {
        // base case

        // we have traversed whole preorder and made all elements
        if (index >= n)
        {
            return NULL;
        }

        // We have called the reccursive function for out of range
        if (inorderStart > inorderEnd)
        {
            return NULL;
        }

        // elements will be inserted in tree in first come first basis of pre order
        int element = pre[index++];

        // Make a new node
        Node *temp = new Node(element);

        // finding the index of current element in inorder
        int position = nodeToIndex[element];

        // Now we need to make calls according to right and left element in pre order 
        temp->left = solve(in, pre, index, inorderStart, position- 1, n , nodeToIndex);
        temp->right = solve(in, pre, index, position+1, inorderEnd, n , nodeToIndex);

        // returning the node as answer
        return temp;
    }

public:
    Node *buildTree(int in[], int pre[], int n)
    {
        int preOrderIndex = 0;
        
        // creating a map to store a mapping of elements of inorder to their indexes
        map<int,int> m;
        createMapping(in,m,n);

        //                               range of concideration of in order to generate next nodes
        Node *ans = solve(in, pre, preOrderIndex, 0, n - 1, n , m);

        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int inorder[n], preorder[n];
        for (int i = 0; i < n; i++)
            cin >> inorder[i];
        for (int i = 0; i < n; i++)
            cin >> preorder[i];
        Solution obj;
        Node *root = obj.buildTree(inorder, preorder, n);
        printPostOrder(root);
        cout << endl;
    }
}

// } Driver Code Ends