// Write a program to implement the stack ADT using two queues.

#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int rear1 = -1, front1 = -1, queue1[MAX];
int rear2 = -1, front2 = -1, queue2[MAX];

void insertion1(int ele)
{
    rear1 = rear1 + 1;
    queue1[rear1] = ele;
    if (front1 == -1)
    {
        front1 = 0;
    }
}
int deletion1()
{
    int x;
    x = queue1[front1];
    if (front1 == rear1)
    {
        front1 = rear1 = -1;
    }
    else
    {
        front1++;
    }
    return x;
}
void insertion2(int ele)
{
    rear2++;
    queue2[rear2] = ele;
    if (front2 == -1)
    {
        front2 = 0;
    }
}
int deletion2()
{
    int x;
    x = queue2[front2];
    if (front2 == rear2)
    {
        front2 = rear2 = -1;
    }
    else
    {
        front2++;
    }
    return x;
}
void push()
{
    int ele;
    printf("Enter element to be insert: ");
    scanf("%d", &ele);
    insertion1(ele);
}
void pop()
{
    int x;
    while (front1 != rear1)
    {
        x = deletion1();
        insertion2(x);
    }
    x = deletion1();
    printf("Deleted: %d", x);
    while (front2 != -1)
    {
        x = deletion2();
        insertion1(x);
    }
}
void display()
{
    int i;
    for (i = front1; i <= rear1; i++)
    {
        printf("[%d],", queue1[i]);
    }
    printf("\n");
}
int main()
{
    int ch;

    while (1)
    {
        printf("\n(1) Push \n(2) Pop \n(3) Display \n(4) Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        }
    }
    return 0;
}