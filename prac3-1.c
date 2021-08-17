/**************************
Practical 3
prg2 : Evaluation of postfix expression
***************************/
#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAX 20

int stack[MAX];
int top = -1;

void push(int num)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow Error");
    }
    else
    {
        top++;
        stack[top] = num;
    }
}

int pop()
{
    if (top == -1)
    {
        printf("Stack is Empty");
        return -1;
    }
    else
    {
        return (stack[top--]);
    }
}

int evaluate(char c, int a, int b)
{
    switch (c)
    {
    case '+':
        push(a + b);
        break;
    case '-':
        push(a - b);
        break;
    case '/':
        push(a / b);
        break;
    case '*':
        push(a * b);
        break;
    case '^':
        push(pow(a, b));
        break;
    default:
        break;
    }
}

int main()
{
    char input[MAX];
    int len, i;
    int a, b;
    printf("Enter a postfix expression: ");
    gets(input);
    len = strlen(input);
    for (i = 0; i < len; i++)
    {
        if (input[i] >= '0' && input[i] <= '9')
        {
            push(input[i] - '0');
        }
        else
        {
            b = pop();
            a = pop();
            evaluate(input[i], a, b);
        }
    }
    printf("The answer is %d\n", pop());
    return 0;
}