// Write a program to implement two stacks in one array.

#include <stdio.h>

#define MENU_DISP_S1 1
#define MENU_DISP_S2 2
#define MENU_PUSH_S1 3
#define MENU_POP_S1 4
#define MENU_TOP_S1 5
#define MENU_PUSH_S2 6
#define MENU_POP_S2 7
#define MENU_TOP_S2 8

void run(int choice);
void printMenu();

/* Stack */
#define MAX 10
#define STACK_FRONT 1
#define STACK_BACK 2

static int stack[MAX];
static int topFront = -1, topBack = MAX;

// stackId: Front/Back stack
void push(int stackId, int x);
void pop(int stackId);
int top(int stackId);
int isEmpty(int stackId);
void display(int stackId);

void run(int choice)
{
    switch (choice)
    {
    case MENU_DISP_S1:
    {
        if (isEmpty(STACK_FRONT))
        {
            printf("Empty front stack.\n");
            break;
        }
        else
        {
            display(STACK_FRONT);
        }

        break;
    }
    case MENU_DISP_S2:
    {
        if (isEmpty(STACK_BACK))
        {
            printf("Empty back stack.\n");
            break;
        }
        else
        {
            display(STACK_BACK);
        }
        break;
    }
    case MENU_PUSH_S1:
    {
        int val;
        printf("Enter value to push on front stack: ");
        scanf("%d", &val);
        push(STACK_FRONT, val);
        break;
    }
    case MENU_POP_S1:
    {
        printf("Popping front stack. \n");
        pop(STACK_FRONT);
        break;
    }
    case MENU_TOP_S1:
    {
        if (isEmpty(STACK_FRONT))
            printf("Empty front stack.\n");
        else
            printf("Top of front stack: %d\n", top(STACK_FRONT));
        break;
    }
    case MENU_PUSH_S2:
    {
        int val;
        printf("Enter value to push on back stack: ");
        scanf("%d", &val);
        push(STACK_BACK, val);
        break;
    }
    case MENU_POP_S2:
    {
        printf("Popping back stack.\n");
        pop(STACK_FRONT);
        break;
    }
    case MENU_TOP_S2:
    {
        if (isEmpty(STACK_BACK))
            printf("Empty front stack.\n");
        else
            printf("Top of front stack: %d\n", top(STACK_BACK));
        break;
    }
    }
}

int isEmpty(int stackId)
{
    return (stackId == STACK_FRONT) ? (topFront == -1) : (topBack == MAX);
}

void push(int stackId, int x)
{
    if (stackId == STACK_FRONT)
    {
        if (topFront == topBack - 1)
        {
            printf("Front stack overflow.\n");
            return;
        }
        stack[++topFront] = x;
    }
    if (stackId == STACK_BACK)
    {
        if (topBack == topFront + 1)
        {
            printf("Back stack overflow.\n");
            return;
        }
        stack[--topBack] = x;
    }
}

void pop(int stackId)
{
    if (stackId == STACK_FRONT)
    {
        if (topFront == -1)
        {
            printf("Front stack underflow.\n");
            return;
        }
        topFront--;
    }

    if (stackId == STACK_BACK)
    {
        if (topBack == MAX)
        {
            printf("Back stack underflow.\n");
            return;
        }
        topBack++;
    }
}

int top(int stackId)
{
    int topVal = 0;
    if (stackId == STACK_FRONT && !isEmpty(STACK_FRONT))
        topVal = stack[topFront];
    if (stackId == STACK_BACK && !isEmpty(STACK_BACK))
        topVal = stack[topBack];

    return topVal;
}

void display(int stackId)
{
    if (stackId == STACK_FRONT)
    {
        printf("FRONT STACK.\n");
        for (int i = topFront; i >= 0; i--)
            printf("[%d]\n", stack[i]);
        printf("___________\n");
    }

    if (stackId == STACK_BACK)
    {
        printf("BACK STACK.\n");
        for (int j = topBack; j < MAX; j++)
            printf("[%d]\n", stack[j]);
        printf("___________\n");
    }
}

void printMenu()
{
    printf("(1) Display stack 1.\n");
    printf("(2) Display stack 2.\n");
    printf("(3) Push on stack 1.\n");
    printf("(4) Pop stack 1.\n");
    printf("(5) Top of stack 1.\n");
    printf("(6) Push on stack 2.\n");
    printf("(7) Pop stack 2.\n");
    printf("(8) Top of stack 2.\n");
    printf("(-1) Exit.\n");
}

int main()
{
    int choice;
    do
    {
        printMenu();
        scanf("%d", &choice);
        run(choice);
    } while (choice != -1);
    return 0;
}