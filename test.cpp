#include <bits/stdc++.h> 
#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

class Node {
public:
    int data;
    Node* next;
    Node* child;

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->child = NULL;
    }
};

*****************************************************************/
 Node *getMid( Node *head)
{
    Node *slow = head;
    Node *fast = head->child;

    while (fast != NULL && fast->child != NULL)
    {
        fast = fast->child;
        fast = fast->child;
        slow = slow->child;
    }

    return slow;
}

 Node *mergeList( Node *left,  Node *right)
{
    if (left == NULL)
    {
        return right;
    }
    if (right == NULL)
    {
        return left;
    }

    Node *ans = new Node(-1);
    // Node *ans = new Node;
    Node *temp = ans;

    while (left != NULL && right != NULL)
    {
        if (left->data < right->data)
        {
            temp->child = left;
            temp = left;
            left = left->child;
        }
        else
        {
            temp->child = right;
            temp = right;
            right = right->child;
        }
    }

    while (left != NULL)
    {
        temp->child = left;
        temp = left;
        left = left->child;
    }

    while (right != NULL)
    {
        temp->child = right;
        temp = right;
        right = right->child;
    }

    return ans->child;
}

 Node *mergeSort( Node *head)
{
    if (head == NULL || head->child == NULL)
    {
        return head;
    }

    // obtaining mid
     Node *mid = getMid(head);

     Node *left = head;
     Node *right = mid->child;

    // break list into 2 equal heads
    mid->child = NULL;

    // sorting both halves
    left = mergeSort(left);
    right = mergeSort(right);

    // merging right and left kist
    Node *result = mergeList(left, right);

    return result;
}

Node *flattenLinkedList(Node *root)
{
    if(root == NULL)
    {
        return root;
    }
    
   // Your code here
   
   Node *temp = root;
   Node *btm;
   
   while(temp != NULL )
   {
       btm = temp->child;
       
       while(btm->child != NULL)
       {
           btm = btm->child;
       }
       
       btm->child = temp->next;
       temp = temp->next;
   }
   
   
    return mergeSort(root);
}



