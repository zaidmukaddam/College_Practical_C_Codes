/**************************
Practical 3
prg1 : infix to postfix
***************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 50

char stack[MAX];
int top = -1;

void push(char c)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow");
    }
    else
    {
        top++;
        stack[top] = c;
    }
}

char pop()
{
    if (top == -1)
    {
        printf("Stack Empty\n");
        return ' ';
    }
    else
    {
        return stack[top--];
    }
}

int isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

char giveTop()
{
    if (top == -1)
        return ' ';
    else
        return stack[top];
}

int precedence(char symbl)
{
    if (symbl == '^')
    {
        return (3);
    }
    else if (symbl == '*' || symbl == '/')
    {
        return (2);
    }
    else if (symbl == '+' || symbl == '-')
    {
        return (1);
    }
    else
    {
        return (0);
    }
}

void infixtopostfix(char infix[])
{
    int len = strlen(infix);
    int i;
    char c;

    for (i = 0; i < len;)
    {
        if (isalpha(infix[i]) || isdigit(infix[i]))
        {
            printf("%c", infix[i++]);
        }
        else //operator
        {
            if (infix[i] == '(')
            {
                push(infix[i++]);
            }
            else if (isEmpty())
            {
                push(infix[i++]);
            }
            else if (giveTop() == '(')
            {
                push(infix[i++]);
            }
            else if (infix[i] == ')')
            {
                while (giveTop() != '(')
                {
                    c = pop();
                    printf("%c", c);
                }
                if (giveTop() == '(')
                {
                    c = pop();
                }
                i++;
            }
            else if (precedence(infix[i]) > precedence(giveTop()))
            {
                push(infix[i++]);
            }
            else if (precedence(infix[i]) <= precedence(giveTop()))
            {
                c = pop();
                printf("%c", c);
            }
        }
    }
    while (!isEmpty())
    {
        c = pop();
        printf("%c", c);
    }
}

void main()
{
    char infix[MAX];

    printf("Enter an infix expression: ");
    gets(infix);

    printf("The postfix expression is : ");
    infixtopostfix(infix);
}
