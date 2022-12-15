#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Stack
{
    int size;
    int top;
    int *S;
};

void create(struct Stack *st)
{
    printf("Enter Size : ");
    scanf("%d", &st->size);
    st->top = -1;
    st->S = (int *)malloc(st->size * sizeof(int));
}

void push(struct Stack *st, int x)
{
    if (st->top == st->size - 1)
        printf("Stack overflow\n");
    else
    {
        st->top++;
        st->S[st->top] = x;
    }
}

int pop(struct Stack *st)
{
    int x = -1;
    if (st->top == -1)
        printf("Stack Underflow\n");
    else
    {
        x = st->S[st->top--];
    }
    return x;
}

int isEmpty(struct Stack st)
{
    if (st.top == -1)
        return 1;
    return 0;
}
int isFull(struct Stack st)
{
    return st.top == st.size - 1;
}
int top(struct Stack st)
{
    if (!isEmpty(st))
    {
         printf("%d \n",st.S[st.top]);
        return st.S[st.top];
    }
    else
    {
        printf("Stack is empty\n");
    }
    return -1;
}
int main()
{
    struct Stack st;
    create(&st);

    bool j = true;

    while (j)
    {
        printf("Press\n1 for push \n2 for pop\n3 to view top\n4 for exit\n");
        int i;
        scanf("%d", &i);

        if (i == 1)
        {
            int in;
            printf("enter the element you want to push : ");
            scanf("%d", &in);
            push(&st, in);
        }
        else if (i == 2)
        {
            pop(&st);
        }
        else if (i == 3)
        {
            top(st);
        }
        else if ( i == 4)
        {
            j = false;
            break;
        }
        else
        {
            printf("Invalid Input\n");
        }
    }

    return 0;
}