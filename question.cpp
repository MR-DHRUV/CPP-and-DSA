//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
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
    Node *root = newNode(stoi(ip[0]));

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
            currNode->left = newNode(stoi(currVal));

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
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// } Driver Code Ends
/*
// node structure:

struct Node
{
    int data;
    Node* left;
    Node* right;
};

*/

class Solution
{

    Node *createParentMapping(Node *root, int target, unordered_map<Node *, Node *> &nodeToParent)
    {
        // we will create such mapping using level order traversal
        Node *res = NULL;

        queue<Node *> q;
        q.push(root);

        // root node will not have any parent
        nodeToParent[root] = NULL;

        while (!q.empty())
        {
            Node *front = q.front();
            q.pop();

            // checking if it is our target node or not
            if (front->data == target)
            {
                res = front;
            }

            // setting mapping
            if (front->left != NULL)
            {
                // marking parent
                nodeToParent[front->left] = front;
                q.push(front->left);
            }
            if (front->right != NULL)
            {
                // marking parent
                nodeToParent[front->right] = front;
                q.push(front->right);
            }
        }

        return res;
    }

    int solve(Node *target, unordered_map<Node *, Node *> &nodeToParent, int &k)
    {
        // this map will check that we have burned that element or not
        map<Node *, bool> visited;

        // for iterations
        queue<Node *> q;
        q.push(target);

        int ans = 0;

        for (int i = 0; i < k && !q.empty(); i++)
        {
            int size = q.size();
            bool burned = false;

            for (int i = 0; i < size; i++)
            {
                // process neighbouring node
                Node *front = q.front();
                q.pop();

                // attached haii so it will take 0 seconds to burn so just ignore it
                if (front->left != NULL && visited[front->left] == false)
                {
                    // marking that we have visited this element
                    visited[front->left] = true;
                    q.push(front->left);
                    burned = true;
                    ans += front->left->data;
                }
                if (front->right != NULL && visited[front->right] == false)
                {
                    // marking that we have visited this element
                    visited[front->right] = true;
                    q.push(front->right);
                    burned = true;
                    ans += front->right->data;
                }

                // checking for its parent
                if (nodeToParent[front] != NULL && visited[nodeToParent[front]] == false)
                {
                    q.push(nodeToParent[front]);
                    visited[nodeToParent[front]] = true;
                    burned = true;
                    ans += nodeToParent[front]->data;
                }
            }
        }

        return ans;
    }

public:
    int ladoos(Node *root, int home, int k)
    {
        unordered_map<Node *, Node *> nodeToParent;
        Node *targetNode = createParentMapping(root, home, nodeToParent);

        if (targetNode == NULL)
            return 0;

        return solve(targetNode, nodeToParent, k);
    }
};

//{ Driver Code Starts.
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

        int home, k;
        cin >> home >> k;
        getchar();
        Solution obj;
        cout << obj.ladoos(root, home, k) << endl;
    }
    return 0;
}

// } Driver Code Ends