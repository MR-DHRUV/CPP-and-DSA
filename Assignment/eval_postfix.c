#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define size 200

char st[200];
int top = -1;

int isEmpty()
{
    return top == -1;
}
int isFull()
{
    return top == size - 1;
}

char pop()
{
    if (isEmpty())
    {
        printf("Stack Underflow\n");
        printf("Invalid Postfix Expression \n");
        exit(0);
        abort();

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

int getValue(int x, int y, char b)
{
    if (b == '*')
    {
        return x * y;
    }

    else if (b == '/')
    {
        return x / y;
    }

    else if (b == '+')
    {
        return x + y;
    }

    else if (b == '-')
    {
        return x - y;
    }

    return -1;
}

bool isOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^' || x == '(' || x == ')')
    {
        return false;
    }
    return true;
}

int evalPostfix(char *exp, int n)
{

    for (int i = 0; i < n; i++)
    {
        if (isOperand(exp[i]))
        {
            push(exp[i] - '0');
        }

        else
        {
            int x = pop();
            int y = pop();

            int ans = getValue(y, x, exp[i]);

            // very important
            push(ans);
        }
    }

    return pop();
}

int main()
{
    int n;
    printf("Enter the length of expression \n");
    scanf("%d", &n);

    char str[n];

    printf("Enter a valid postfix expression \n");
    int i = 0;

    int j = n;
    while (j--)
    {
        scanf("%s", &str[i++]);
    }

    int ans = evalPostfix(str, n);
    printf("%d", ans);

    return 0;
}