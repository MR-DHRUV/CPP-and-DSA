#include <bits/stdc++.h>
using namespace std;

struct tNode
{
    int data;
    struct tNode *left;
    struct tNode *right;
};

// We can use this techneque to get inorder, preorder or postorder traversal of any tree in O(N) time and most importantly in O(1) space
// traditional method gives in O(n) space either reccursive or iterative

// predecessor : the element obtained after going to left child once then followingg its right until its the last right
void MorrisTraversal(struct tNode *root)
{
    struct tNode *current, *pre;

    if (root == NULL)
    {
        return;
    }

    // Setting current as starting node
    current = root;

    while (current != NULL)
    {

        if (current->left == NULL)
        {
            cout << current->data << " ";
            current = current->right;
        }
        else
        {

            /* Finding the inorder predecessor of current */
            pre = current->left;
            while (pre->right != NULL && pre->right != current)
            {
                pre = pre->right;
            }

            /* Making a temprary link between predisessor node and janhan se yeh aaya tha */
            if (pre->right == NULL)
            {
                pre->right = current;
                current = current->left;
            }

            /* Revert the changes made in the 'if' part to
            restore the original tree i.e., fix the right
            child of predecessor */
            else
            {
                pre->right = NULL;
                cout << current->data << " ";
                current = current->right;
            } 
        }     
    }         
}

struct tNode *newtNode(int data)
{
    struct tNode *node = new tNode;
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

int main()
{

    /* Constructed binary tree is
            1
        / \
        2	 3
    / \
    4	 5
*/
    struct tNode *root = newtNode(1);
    root->left = newtNode(2);
    root->right = newtNode(3);
    root->left->left = newtNode(4);
    root->left->right = newtNode(5);

    MorrisTraversal(root);

    return 0;
}
