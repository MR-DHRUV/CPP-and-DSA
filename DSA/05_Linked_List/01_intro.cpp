#include<iostream>
using namespace std;

// self refrencial structure
typedef struct Node
{
    // data
    int data;

    // address of next Node
    struct Node *next;

}Node;


int main()
{
    // problems with array
    // fixed size
    // large array bna denge toh space waste hoga 
    // slow rather time complex inserion and deletion in middle
    

    // linked list
    // 2 blocks hain ek me value dusre me address of next block , agle me agle ka address and so on...
    // 8 101111 , 12 455458 , 17 893459 .....
    // jab bhi naya element add krna ho ek naya node (dabba) bna do aur link krdo last node se 

    // fast insertion , deletion in middle 
    // dynamic size , so always created in heap
    // addresses of nodes are non contigous

    //Terms

    // Head : the first pointer that points to the first node / head node 
    // Node : it is a pair of data and address of next node


    // Declareation of linked list in heap
    Node *p , *q;
    p = new Node;

    p->data = 9;

    // 0 means not pointing anywhere, its last 
    p->next  = 0;

    // q = p : it means q is pointing to a node where p is already pointing
    // q = p->next : it means q is pointing to node after p

    // very usefull code , as it can be used to traverse the list
    // p = p->next : now p will point to node next to p 

    // check if any node is pointing to a next node
    // if(p->next != NULL)
    // or
    // if(p->next != 0)
 
    return 0;
}