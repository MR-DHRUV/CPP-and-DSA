//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

bool isBST(Node* n, int lower, int upper) {
    if (!n) return true;
    if (n->data <= lower || n->data >= upper) return false;
    return (isBST(n->left, lower, n->data) && isBST(n->right, n->data, upper));
}

bool compare(Node* a, Node* b, vector<pair<int, int>>& mismatch) {
    if (!a && !b) return true;
    if (!a || !b) return false;

    if (a->data != b->data)
        mismatch.push_back(pair<int, int>(a->data, b->data));

    return (compare(a->left, b->left, mismatch) &&
            compare(a->right, b->right, mismatch));
}


// } Driver Code Ends
// User function Template for C++

/*struct Node
{
    int data;
    struct Node *left, *right;
};*/

class Solution
{

    vector<int> in;
    Node *n1 = NULL;
    Node *n2 = NULL;

    void inorder(Node *root)
    {
        if (root == NULL)
        {
            return;
        }

        inorder(root->left);
        in.push_back(root->data);
        inorder(root->right);
    }

    void findTargets(Node *root, int t1, int t2)
    {
        if (root == NULL)
        {
            return;
        }

        if (root->data == t1)
        {
            n1 = root;
        }
        if (root->data == t2)
        {
            n2 = root;
        }

        findTargets(root->left, t1, t2);
        findTargets(root->right, t1, t2);
    }

    void getIncorrect(Node *root, int &t1, int &t2, int &df1, int &df2)
    {
        in.clear();
        inorder(root);

        t1 = -1, t2 = -1;
        df1 = -1, df2 = -1; // deciding factor

        for (int i = 0; i < in.size() - 1; i++)
        {
            if (in[i] > in[i + 1])
            {
                if (t1 == -1)
                {
                    t1 = in[i];
                    df1 = in[i + 1];
                }
                else
                {
                    if (in[i] == df1)
                    {
                        t2 = in[i + 1];
                    }
                    else
                    {
                        t2 = in[i];
                        df2 = in[i + 1];
                    }

                    break;
                }
            }
        }
    }

    bool swapAndCheck(Node *root, int t1, int t2)
    {
        // swap stage
        findTargets(root, t1, t2);
        swap(n1->data, n2->data);

        // check stage
        int temp1, temp2, dtemp1, dtemp2;
        getIncorrect(root, temp1, temp2, dtemp1, dtemp2);

        if (temp1 == -1)
        {
            return true;
        }

        // backtrack and return false
        swap(n1->data, n2->data);
        return false;
    }

public:
    struct Node *correctBST(struct Node *root)
    {
        // CHALAKI WAALI APPROACH
        // inorder karo aur incorrect nodes detect karo : O(N) + O(N)
        // find them : O(N)
        // swap them : O(1)

        int t1, t2, df1, df2;

        // scanning inorder to obtain incorrect nodes
        getIncorrect(root, t1, t2, df1, df2);
        // cout << t1 << " " << df1 << " " << t2 << " " << df2 << endl;

        // case 1+0 : t1 and t2 are to be swapped
        if (df2 == -1)
        {
            // agar t2 nahi milla toh df must be swapped : case 0
            if (t2 == -1)
            {
                t2 = df1;
            }

            findTargets(root, t1, t2);
            swap(n1->data, n2->data);

            return root;
        }
        else
        {
            // now we have 4 targets : t1,df1,t2,df2
            // ab 4 case bnenge

            // case 1: swap t1 t2
            bool chk = swapAndCheck(root, t1, t2);
            if (chk)
            {
                return root;
            }

            chk = swapAndCheck(root, t1, df2);
            if (chk)
            {
                return root;
            }

            chk = swapAndCheck(root, df1, t2);
            if (chk)
            {
                return root;
            }

            chk = swapAndCheck(root, df1, df2);
        }

        // // obtain their address

        // // debug code
        // in.clear();
        // inorder(root);
        // for (int i = 0; i < in.size(); i++)
        // {
        //     cout << in[i] << " ";
        // }

        return root;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    getchar();

    while (t--) {
        string s;
        getline(cin, s);

        Node* root = buildTree(s);
        Node* duplicate = buildTree(s);

        Solution ob;
        root = ob.correctBST(root);

        // check 1: is tree now a BST
        if (!isBST(root, INT_MIN, INT_MAX)) {
            cout << "0\n";
            continue;
        }

        // check 2: comparing with duplicate tree

        vector<pair<int, int>> mismatch;
        // a vector to store data of mismatching nodes

        if (!compare(root, duplicate, mismatch)) {
            // false output from this function indicates change in structure of
            // tree
            cout << "0\n";
            continue;
        }

        // finally, analysing the mismatching nodes
        if (mismatch.size() != 2 || mismatch[0].first != mismatch[1].second ||
            mismatch[0].second != mismatch[1].first)
            cout << "0\n";
        else
            cout << "1\n";
    }
    return 0;
}

// } Driver Code Ends