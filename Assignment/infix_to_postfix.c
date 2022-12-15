#include <stdio.h>
#include <stdlib.h>
#define size 20

char st[20];
int top = -1;

int isEmpty()
{
    return top == -1;
}
int isFull()
{
    return top == size - 1;
}

char peek()
{
    return st[top];
}

char pop()
{
    if (isEmpty())
    {
        printf("Stack Underflow\n");
        return -1;
    }

    char ch = st[top];
    top--;
    return (ch);
}

void push(char oper)
{
    if (isFull())
        printf("Stack Overflow\n");

    else
    {
        top++;
        st[top] = oper;
    }
}


int isOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}


int getPriority(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 2;

    case '^':
        return 3;
    }
    return -1;
}

int toPostfix(char *str)
{
    int i, j;

    for (i = 0, j = -1; str[i]; ++i)
    {

        if (isOperand(str[i]))
        {
            str[++j] = str[i];
        }

        else if (str[i] == '(')
        {
            push(str[i]);
        }

        else if (str[i] == ')')
        {
            while (!isEmpty() && peek() != '(')
            {
                str[++j] = pop();
            }
            if (!isEmpty() && peek() != '(')
            {
                return -1;
            }
            else
            {
                pop();
            }
        }
        else
        {
            while (!isEmpty() && getPriority(str[i]) <= getPriority(peek()))
                str[++j] = pop();
            push(str[i]);
        }
    }

    while (!isEmpty())
    {
        str[++j] = pop();
    }

    str[++j] = '\0';
    printf("%s", str);
}

int main()
{
    char str[] = "((a+(b^c))-d)";
    toPostfix(str);
    return 0;
}