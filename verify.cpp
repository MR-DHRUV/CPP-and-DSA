#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *head1 = NULL;
struct node *head2 = NULL;
struct node *head3 = NULL; 

void merg();                         
void prr(struct node **head);       
void sortedInsert(struct node **head); 

int main()
{
    bool n = true;
    while (n)
    {
        int input, p;
        printf("\nWhat operation Do you want to perform \n1. Insert in first Linked List \n2. Insert in second  Linked list\n3. Merge both Linked List \n4. Print Linked List \n5. Exit\n");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            sortedInsert(&head1);
            break;
        case 2:
            sortedInsert(&head2);
            break;
        case 3:
            merg();
            break;
        case 4:
            printf("which ll you want to print \n1. first \n2. Second\n3. previously merged LL");
            scanf("%d", &p);
            switch (p)
            {
            case 1:
                prr(&head1);
                break;
            case 2:
                prr(&head2);
                break;
            case 3:
                prr(&head3);
                break;
            default:
                printf("\nInvalid input\n");
                break;
            }
            break;
        case 5:
            n = false;
            printf("\nYou have exited successfully\n");
            break;
        default:
            printf("Invalid Input");
            break;
        }
    }

    return 0;
}

void prr(struct node **head)
{
    if (*head == NULL)
    {
        printf("\nLinked list is Empty!!!\n");
        return;
    }
    struct node *curr = *head;
    printf("Linked LIst : ");
    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

void sortedInsert(struct node **head)
{
    int key;
    printf("\nEnter data you want to input in Linked LIst : ");
    scanf("%d", &key);
    struct node *temp = (struct node *)malloc(sizeof(struct node));


    temp->data = key;

    if (*head == NULL)
    {
        *head = temp;
        prr(head);
        return;
    }

    if (key < (*head)->data)
    {
        temp->next = *head;
        *head = temp;
        prr(head);
        return;
    }
    
    struct node *curr = *head;
    while (curr->next != NULL && curr->next->data < key)
    {
        curr = curr->next;
    }
    temp->next = curr->next;
    curr->next = temp;
    prr(head);
    return;
}
void merg()
{
    if (head1 == NULL && head2 == NULL)
    {
        printf("\nBoth the Linked LIst are empty\n");
        return;
    }
    if (head1 == NULL)
    {
        head3 = head2;
        prr(&head3);
        return;
    }
    if (head2 == NULL)
    {
        head3 = head1;
        prr(&head3);
        return;
    }
    struct node *h = NULL, *t = NULL, *curr1 = head1, *curr2 = head2;
    if (curr1->data <= curr2->data) // for head of head3 or h
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->data = curr1->data;

        h = temp;
        t = temp;

        curr1 = curr1->next;
    }
    else
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->data = curr1->data;
        h = temp;
        t = temp;
        curr2 = curr2->next;
    }
    while (curr1 != NULL && curr2 != NULL)
    {
        if (curr1->data <= curr2->data)
        {
            struct node *temp = (struct node *)malloc(sizeof(struct node));
            temp->data = curr1->data;
            t->next = temp;
            t = temp;
            curr1 = curr1->next;
        }
        else
        {
            struct node *temp = (struct node *)malloc(sizeof(struct node));
            temp->data = curr2->data;
            t->next = temp;
            t = temp;
            curr2 = curr2->next;
        }
    }
    if (curr1 == NULL)
    {
        while (curr2!=NULL)
        {
            struct node *temp = (struct node *)malloc(sizeof(struct node));
            temp->data = curr2->data;
            t->next = temp;
            t = temp;
            curr2 = curr2->next;
        }
        }
    else
    {
       while(curr1!=NULL){
           struct node *temp = (struct node *)malloc(sizeof(struct node));
           temp->data = curr1->data;
           t->next = temp;
           t = temp;
           curr1 = curr1->next;
       }
    }
    head3 = h;
    prr(&head3);
}