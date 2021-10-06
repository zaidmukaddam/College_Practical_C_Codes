// Write a program to implement the queue ADT using (two stacks).

#include <stdio.h>
#include <stdlib.h>

#define max 10

int s1[max];
int s2[max];

int t1 = -1;
int t2 = -1;

//pop elements from stack 1.
int pop_1(int top)
{
    if (top == -1)
    {
        printf("Underflow!!\n");
        exit(1);
    }
    int x;
    x = s1[top];
    return x;
}

//pop elements from stack 2.
int pop_2(int top)
{
    if (top == -1)
    {
        printf("Underflow!!\n");
        exit(1);
    }
    int y;
    y = s2[top];
    return y;
}

//add elements in the stack 2.
void add_s2(int item)
{
    if (t2 == max - 1)
    {
        printf("overflow!!\n");
        exit(1);
    }
    t2 += 1;
    s2[t2] = item;
}

//for adding all the items back to s1.
int add__s1(int item)
{
    t1 += 1;
    s1[t1] = item;
}

void add_s1(int item);
void add_s1(int item)
{
    if (t1 == max - 1)
    {
        printf("overflow!!\n");
        exit(1);
    }
    else if (t1 == -1) //adding the first item normally in the stack 1.
    {
        t1 += 1;
        s1[t1] = item;
    }
    else
    {
        while (t1 != -1) //for emptying the stack1.
        {
            add_s2(pop_1(t1));
            t1 -= 1;
        }
        t1 += 1;
        s1[t1] = item; //adding the item to stack 1.
    }
    while (t2 != -1) //adding the elements from stack 2 -> stack1.
    {
        add__s1(pop_2(t2));
        t2 -= 1;
    }
}

//for displaying the content of the queue.
void display()
{
    int i;
    printf("displaying the current status!!\n");
    for (i = t1; i >= 0; i--)
        printf("%d ", s1[i]);
    printf("\n");
}

int main()
{
    int ch, x, y;
    do
    {
        printf("(1) Push\n(2) Pop\n(3) Display\n(4) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the no. to be added: ");
            scanf("%d", &x);
            add_s1(x);
            break;
        case 2:
            y = pop_1(t1);
            t1 -= 1;
            printf("The no. popped out is: %d", y);
            printf("\n");
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
            break;
        default:
            printf("Please enter a valid choice!!\n");
            break;
        }
        printf("\n");
    } while (ch != 4);
    return 0;
}