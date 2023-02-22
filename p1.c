#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

typedef struct Stack
{
    int top;
    int size;
    char *s;
} Stack;

void init(Stack *st, int n)
{
    st->size = n;
    st->s = (char *)malloc(sizeof(char) * n);
    st->top = -1;
}

bool empty(Stack *st)
{
    if (st->top == -1)
    {
        return true;
    }

    return false;
}

bool full(Stack *st)
{
    if (st->top == st->size - 1)
    {
        return true;
    }

    return false;
}

void push(Stack *st, char x)
{
    if (full(st))
    {
        printf("Stack is full \n");
        return;
    }

    st->s[++st->top] = x;
}

char pop(Stack *st)
{
    if (empty(st))
    {
        printf("Stack is empty \n");
        return -1;
    }

    return st->s[st->top--];
}

char top(Stack *st)
{
    if (empty(st))
    {
        return '.';
    }

    return st->s[st->top];
}

bool isOperand(char c)
{
    if (c == '*' || c == '+' || c == '/' || c == '-' || c == '^' || c == '(' || c == ')')
    {
        return false;
    }

    return true;
}

int getPrecedence(char c)
{
    if (c == '^')
    {
        return 4;
    }
    else if (c == '*' || c == '/')
    {
        return 3;
    }
    else if (c == '+' || c == '-')
    {
        return 2;
    }
    else if (c == '(' || c == ')')
    {
        return 1;
    }

    return 0;
}

char *toPostfix(char *str, int n)
{
    Stack st;
    init(&st, n + 2);

    char *ans = (char *)malloc(sizeof(char)*n);
    int j = 0;

    push(&st, '#');

    for (int i = 0; i < n; i++)
    {
        if (isOperand(str[i]))
        {
            ans[j++] = str[i];
        }
        else
        {
            if (str[i] == '(')
            {
                push(&st, str[i]);
            }
            else if (str[i] == ')')
            {
                char t = pop(&st);

                while (t != '(')
                {
                    if (t == '#' || t == '.')
                    {
                        printf("Invalid infix expression \n");
                        return "-1";
                    }

                    ans[j++] = t;
                    t = pop(&st);
                }
            }
            else if (getPrecedence(str[i]) > getPrecedence(top(&st)))
            {
                push(&st, str[i]);
            }
            else
            {
                while (getPrecedence(str[i]) <= getPrecedence(top(&st)))
                {
                    ans[j++] = pop(&st);
                    if (ans[j] == '#' || ans[j] == '.')
                    {
                        printf("Invalid infix expression \n");
                        return "-1";
                    }
                }

                push(&st, str[i]);
            }
        }
    }

    while (top(&st) != '#')
    {
        ans[j++] = pop(&st);
    }

    for (int i = 0; i < n; i++)
    {
        printf("%c", ans[i]);
    }

    return ans;
}

int getValue(int x , int y , char b)
{
    if(b == '*')
    {
        return x*y;
    }

    else if(b == '/')
    {
        return x/y;
    }

    else if(b == '+')
    {
        return x+y;
    }

    else if(b == '-')
    {
        return x-y;
    }

    return -1;
} 


int evalPostfix(char *str, int n)
{
    Stack st;
    init(&st, n + 2);

    for (int i = 0; i < n; i++)
    {
        
    }
    


    return top(&st);
}

int main(int argc, char const *argv[])
{

    char str[] = "a+b*c/d";
    char *ans = toPostfix(str,8);
    // printf("%s",ans);

    return 0;
}