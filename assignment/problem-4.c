// Write a program to reverse the words in a sentence with a stack.

#include <stdio.h>
#include <string.h>

#define MAX 100

int top = -1;
int item;

char string[MAX];

int Empty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

int Full()
{
    if (top == MAX - 1)
        return 1;
    else
        return 0;
}

void push(char item)
{

    if (Full())
    {
        printf("\nStack is FULL !!!\n");
        return;
    }

    top = top + 1;
    string[top] = item;
}

char pop()
{

    if (Empty())
    {
        printf("\nStack is EMPTY!!!\n");
        return 0;
    }

    item = string[top];
    top = top - 1;
    return item;
}

int main()
{
    char str[MAX];

    int i;

    printf("\nInput a string: ");
    scanf("%[^\n]s", str);

    for (i = 0; i < strlen(str); i++)
        push(str[i]);

    for (i = 0; i < strlen(str); i++)
        str[i] = pop();

    printf("\nReversed String is: %s\n", str);

    return 0;
}
