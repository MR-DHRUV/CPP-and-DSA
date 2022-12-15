//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
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

    return root;
}

// } Driver Code Ends
/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution
{
    void getInorder(Node *root, vector<int> &in)
    {
        if (root == NULL)
        {
            return;
        }

        getInorder(root->left, in);
        in.push_back(root->data);
        getInorder(root->right, in);
    }

    vector<int> mergeArr(vector<int> in1, vector<int> in2)
    {
        int i = 0;
        int j = 0;

        vector<int> ans;

        while (i < in1.size() && j < in2.size())
        {
            if (in1[i] == in2[j])
            {
                ans.push_back(in2[j++]);
                ans.push_back(in1[i++]);
            }
            else if (in1[i] > in2[j])
            {
                ans.push_back(in2[j++]);
            }
            else
            {
                ans.push_back(in1[i++]);
            }
        }

        while (i < in1.size())
        {
            ans.push_back(in1[i++]);
        }

        while (j < in2.size())
        {
            ans.push_back(in2[j++]);
        }

        return ans;
    }

    Node *buildFromInorder(vector<int> in, int s, int e)
    {
        if (s > e)
        {
            return NULL;
        }

        int mid = s + (e - s) / 2;

        Node *t = new Node(in[mid]);
        t->left = buildFromInorder(in, s, mid - 1);
        t->right = buildFromInorder(in, mid + 1, e);

        return t;
    }

public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    Node *merge(Node *root1, Node *root2)
    {
        // approach 1
        // find inorder of both
        // merge inorder in sorted way
        // build tree from inorder

        vector<int> in1;
        vector<int> in2;

        getInorder(root1, in1);
        getInorder(root2, in2);

        vector<int> in = mergeArr(in1, in2);
        Node *ans = buildFromInorder(in, 0, in.size() - 1);

        return ans;
    }
};

void printInorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main()
{

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--)
    {
        string s;
        getline(cin, s);
        Node *root1 = buildTree(s);

        getline(cin, s);
        Node *root2 = buildTree(s);

        // getline(cin, s);
        Solution obj;
        Node *ans = obj.merge(root1, root2);
        printInorder(ans);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends