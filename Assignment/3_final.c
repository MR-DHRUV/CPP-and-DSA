#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;

} *first = NULL;

int count(struct Node *head)
{
    if (head == NULL)
    {
        return 0;
    }

    int c = 1;
    head = head->next;

    while (head != NULL && head != first)
    {
        c++;
        head = head->next;
    }

    return c;
}

void Display(struct Node *p)
{
    if (p == NULL)
    {
        printf("The list ie empty");
        return;
    }

    printf("%d ", p->data);

    while (p->next != first)
    {
        p = p->next;
        printf("%d ", p->data);
    }

    printf("\n");
}

void Insert(int position, int x)
{
    struct Node *p = first;
    struct Node *t;
    int i;

    if (position < 0 || position > count(p))
    {
        printf("INVALID position");
        return;
    }

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;

    for (i = 0; i < position - 1; i++)
    {
        p = p->next;
    }

    t->next = p->next;
    p->next = t;
}

void Insert_at_end(int x)
{
    struct Node *p = first;
    struct Node *t;

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;

    while (p->next != first)
    {
        p = p->next;
    }

    p->next = t;
    t->next = first;
}

void Insert_at_front(int x)
{
    struct Node *t;

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = first;

    if (first == NULL)
    {
        t->next = t;
    }
    else
    {
        // updating next of last node
        struct Node *temp = first;
        while (temp->next != first)
        {
            temp = temp->next;
        }
        temp->next = t;
    }

    first = t;
}

void delete_at_begining(struct Node *p)
{
    struct Node *q = NULL;

    q = first;

    struct Node *temp = first;

    while (temp->next != first)
    {
        temp = temp->next;
    }

    temp->next = first->next;

    first = first->next;
    free(q);
}

void delete_at_end(struct Node *p)
{
    struct Node *temp = p;

    while (temp->next->next != first)
    {
        temp = temp->next;
    }

    temp->next = first;
}

void delete_at_loc(struct Node *p, int target)
{
    struct Node *temp = p;

    while (temp->data != target)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        print("Element Not found\n");
    }
    else
    {
        temp->next = temp->next->next;
    }
}

void inp_insert()
{
    int nxt, idx;
    printf("Enter the element you want to insert : ");
    scanf("%d", &nxt);

    if (count(first) <= 0)
    {
        printf("The list is empty, the insertion can be done only in front\n");
        Insert_at_front(nxt);
    }
    else
    {
        int input;
        printf("Enter 1 for insertion at front\n");
        printf("Enter 2 for insertion at the end\n");
        printf("Enter 3 for insertion at position\n");

        scanf("%d", &input);
        switch (input)
        {
        case 1:
            Insert_at_front(nxt);
            break;

        case 2:
            Insert_at_end(nxt);
            break;
        case 3:
            printf("Enter the position where you want to insert : ");
            scanf("%d", &idx);
            Insert(idx, nxt);
        default:
            break;
        }
    }

    Display(first);
};

void inp_del()
{
    if (count(first) < 1)
    {
        printf("The list is empty\n");
        return;
    }

    int input;
    printf("Enter 1 for deletion at front\n");
    printf("Enter 2 for deletion at the end\n");
    printf("Enter 3 for deletion at position\n");

    scanf("%d", &input);
    switch (input)
    {
    case 1:
        delete_at_begining(first);
        break;

    case 2:
        delete_at_end(first);
        break;
    case 3:
        printf("Enter the element after which you want to delete : ");
        int element;
        scanf("%d", &element);
        delete_at_loc(first, element);
    default:
        break;
    }

    Display(first);
}

int main()
{
    bool infinite = true;
    printf("Welcome to circular single linked list program EXP 3\n");

    while (infinite == true)
    {
        int in;
        int len;
        printf("Enter your choice \n1 for insert\n2 for delete\n3 for display\n4 for exit\n");
        scanf("%d", &in);

        switch (in)
        {
        case 1:
            inp_insert();
            break;

        case 2:
            inp_del();
            break;
        case 3:
            Display(first);
            break;
        case 4:
            infinite = false;
            break;
        default:
            break;
        }
    }

    return 0;
}