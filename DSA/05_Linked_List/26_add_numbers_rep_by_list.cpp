//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/


// so we have to reverse both the lists and start to sum individual nodes
// reverse isilie karenge kyuki addition last se start hota haii 
class Solution
{
    struct Node* reverseList(struct Node *head)
    {
        struct Node* prev = NULL;
        struct Node* curr = head;
        struct Node* next = NULL;

        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head = prev;
        return head;
    }
    
    void insertAtTail(struct Node* &ansHead, struct Node* &ansTail , int val)
    {
        Node *temp = new Node(val);
        
        if(ansHead == NULL)
        {
            ansHead = temp;
            ansTail = temp;
        }
        else
        {
            ansTail->next = temp;
            ansTail = temp;
        }
        return;
    }
    
    struct Node* addList(struct Node* first, struct Node* second)
    {
        int carry =0;
        
        Node*ansHead = NULL;
        Node*ansTail = NULL;
        
        while(first != NULL && second != NULL)
        {
            int sum = first->data + second->data + carry;
            int digit = sum%10;
           
            // will create node and add it in and list 
            insertAtTail(ansHead,ansTail,digit);
            
            carry = sum/10;
            first = first->next;
            second = second->next;
        }
        
       while(first != NULL)
       {
           int sum = carry + first->data;
           int digit = sum%10;
           
           // will create node and add it in and list 
           insertAtTail(ansHead,ansTail,digit);
           carry = sum/10;
           first = first->next;
       }
        
       while(second != NULL)
       {
           int sum = carry + second->data;
           int digit = sum%10;
           
           // will create node and add it in and list 
           insertAtTail(ansHead,ansTail,digit);
           carry = sum/10;
           second = second->next;
       }
       
       while(carry != 0)
       {
           int sum = carry;
           int digit = sum%10;
           
           // will create node and add it in and list 
           insertAtTail(ansHead,ansTail,digit);
           carry = sum/10;
       }
            
        return ansHead;
        
        
    }

    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        if(first == NULL)
        {
            return second;
        }
        else if(second == NULL)
        {
            return first;
        }
        else if(first == NULL && second == NULL)
        {
            return first;
        }
        
        first = reverseList(first);
        second = reverseList(second);
        
        struct Node*ans = addList(first,second);
        
        ans = reverseList(ans);
        return ans;
        
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends