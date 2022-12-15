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

    int height();

    void insert(int x);
    void remove(int x);

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

// O(logN) approach
void BinTree ::insert(int x)
{
    // first search for element to be inserted as bst cant have duplicates

    // if element is present resturn true

    // else
    // element will be added at the same position from where the pointer t has became null in the search
    // so we will have a following pointer

    Node *curr = head;
    Node *prev = NULL;

    while (curr != NULL)
    {
        if (curr->data == x)
        {
            return;
        }
        else if (curr->data > x)
        {
            prev = curr;
            curr = curr->left;
        }
        else
        {
            prev = curr;
            curr = curr->right;
        }
    }

    // if we are here in function that means node is not present we need to add this node
    Node *p = new Node(x);

    if (p == NULL)
    {
        cout << "Heap is full !" << endl;
        return;
    }

    if (prev->data > x)
    {
        prev->left = p;
    }
    else
    {
        prev->right = p;
    }

    return;
}



// first search for element to be deleted

// searching element to be deleted

// if we want to delete a node then we have to find out its inorder predicessor and inorder successor as either predicessor or sucessor will take its place

// inorder predicessor wo node hai jo inorder traversal me given node se pahle aaye

// O(logN) approach

Node *del(Node *root, int target , const Node *head)
{

    if(root == NULL)
    {
        return NULL;
    }

    // if it is a leaf node we have to remove it
    if(root->left == NULL && root->right == NULL && root->data == target)
    {
        if(root == head)
        {
            head = NULL;
        }
        else
        {
            free(root);
        }

        // as node is deleted NULL is returned
        return NULL;
    }

    if(root->data > target)
    {
        root->left = del(root->left,target,head);
    }
    else if(root->data < target)
    {
        root->right = del(root->right,target,head);
    }
    else
    {
        // we have found the node to be deleted

        // we will replace target from element from that side whose height will be more 
        if(heightCalc(root->left) > heightCalc(root->right))
        {
            // replace from left side so finding inorder predecessor
            Node *pre = root->left;
            while (pre->right != NULL)
            {
                pre = pre->right;
            }

            root->data = pre->data;

            // now we have to delete pre from tree
            root->left = del(root->left , pre->data,head);
        }
        else
        {
            // replace from left side so finding inorder sucessor
            Node *pre = root->right;
            while (pre->left != NULL)
            {
                pre = pre->left;
            }

            root->data = pre->data;

            // now we have to delete pre from tree
            root->right = del(root->right , pre->data,head);
        }
        
    }

    return root;
}

void BinTree ::remove(int x)
{
    del(head,x,head);
}

int main()
{
    // BinTree b(8);

    // // input in bst fashion
    // vector<int> v = {30, 20, 40};

    // // b.buildFromLevelOrder(v);
    // b.levelorder();

    // // sorted hoga for bst;
    // b.inorder();

    // Node *ans = b.searchBstIter(35);

    // if (ans)
    //     cout << "True" << endl;
    // else
    //     cout << "False" << endl;

    // b.insert(5);
    // b.insert(15);
    // b.insert(50);
    // b.insert(4);
    // b.insert(89);
    // b.insert(15);
    // b.insert(10);
    // b.inorder();

    // b.remove(400);
    // b.inorder();

    BinTree b(50);

    b.insert(10);
    b.insert(40);
    b.insert(20);
    b.insert(30);
    b.inorder();

    b.remove(50);
    b.inorder();

    return 0;
}
