#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// method 1 : using map to store addresses of all the visited nodes and checking them on each iteration
//  map stores key value pairs, it dont allow duplicate keys
bool isLooped(Node *head)
{
    if (head == NULL)
    {
        return false;
    }

    map<Node *, bool> visited;

    Node *temp = head;

    while (temp != NULL)
    {
        // this is cycle point
        if (visited[temp] == true)
        {
            return true;
        }

        // set visited of temp as true
        visited[temp] = true;
        temp = temp->next;
    }

    return false;
}

// based on floyed's cycle detection algorithm
bool isCircular(Node *head)
{

    if (head == NULL)
    {
        return true;
    }

    // Write your code here.
    Node *slow = head;
    Node *fast = head;

    while (fast->next != NULL && slow->next != NULL)
    {
        // moved 2 nodes at a time
        fast = fast->next;
        if (fast->next == NULL)
        {
            return false;
        }

        fast = fast->next;
        slow = slow->next;

        // agar beech me null aagaya toh return ho gaye function
        if (fast->next == NULL || slow->next == NULL)
        {
            return false;
        }

        // circular means last and head linked ho beech se linked na ho
        if (slow == fast && fast == head)
        {
            return true;
        }

        // neccacary for loop to get terminated, as it can be a looped list
        if (slow == fast && fast != head)
        {
            return false;
        }
    }

    return false;
}

// step 1 : find point of intersection using floys cycle detection algo
// step 2 : if point of intersection null nahi haii toh slow aur fast ko ek sath chalao ,jaha meet kar jaye waha se start h loop
Node *startLoop(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *slow = head;
    Node *fast = head;

    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if (fast == NULL || fast->next == NULL)
        {
            return NULL;
        }

        fast = fast->next;
        slow = slow->next;
        if (slow == NULL)
        {
            return NULL;
        }

        if (slow == fast)
        {
            break;
        }
    }
    // formula

    // A -> list start to loop start ki length
    // B -> loop start to point of intersection ki length
    // C -> length of loop

    // distance by fast = 2*distance by slow
    // A +xC + B = 2*(A + B + yC)
    // C(x-2y) = A+B
    // kC = A+B
    // A + B = kC

    // in simple terms we can say A + B forms the cycle
    // so agar slow start se A times chale toh woh loop start pr aajayga
    // aur agar fast point of intersection se A times chale toh wo loop complete krke uske start pr aajayga, as pahle hi POI B distace pr haii
    // and B + A = C

    /*
        crisp explaination
        x : list start to loop start
        y : loop start to poi
        z : poi to loop start

        dist moved by fast = df = x + p(y+z) + y
        dist moved by slow = ds = x + (p-1/2)(y+z) + y // slow will took p- 1/2 complete revolutions

        time = time
        distance/speed = distance/speed

        (x + p(y+z) + y) / 2v = (x + (p-1/2)(y+z) + y) / v

        (x + p(y+z) + y) =  2*(x + (p-1/2)(y+z) + y)
        x + p(y+z) + y =  2x + p-1(y+z) + 2y

        x + y +z + y =  2x + 2y
        x + z = 2x
        z = x
    */

    slow = head;

    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    // koi bhi krdo fast ya slow same hi jagah point kr rhe hain woh
    return fast;
}

Node *removeLoop(Node *head)
{
    if (head == NULL)
    {
        return head;
    }

    Node *start = startLoop(head);
    if (start == NULL)
    {
        return head;
    }

    Node *temp = start;

    // it will work for all the cases
    while (temp->next != start)
    {
        temp = temp->next;
    }

    temp->next = NULL;

    return head;
}

int main()
{

    return 0;
}