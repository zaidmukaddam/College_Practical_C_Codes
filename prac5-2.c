#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int queue[MAX];
int front = -1, rear = -1, size = 0, start = 0;

int isEmpty()
{
    if (front == -1 && rear == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull()
{
    if (rear == MAX - 1)
        return 1;
    else
        return 0;
}

void enqueue(int num)
{
    if (isFull())
    {
        printf("Queue is Full\n");
    }
    else
    {
        if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = rear + 1;
        }
        size++;
        queue[rear] = num;
    }
}

int dequeue()
{
    int val, i;
    if (front == rear)
    {
        val = queue[front];
        front = rear = -1;
    }
    else
    {
        val = queue[front];
        front = 0;
        for (i = front + 1; i <= rear; i++)
        {
            queue[i - 1] = queue[i];
        }
        rear = rear - 1;
    }
    size--;
    return val;
}

int peek()
{
    if (isEmpty())
    {
        printf("\nQueue Underflow\n");
        exit(1);
    }
    return queue[front];
}

void display()
{
    int i;
    if (isEmpty())
    {
        printf("\nQueue is empty\n");
    }
    printf("\nQueue is :\n\n");
    for (i = front; i <= rear; i++)
        printf("%d  ", queue[i]);
    printf("\n\n");
}

void main()
{
    int inp, ch, item;
    do
    {
        printf("\n1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Display element at the front\n");
        printf("4.Display Size of the Queue\n");
        printf("5.Display all elements of the queue\n");
        printf("6.Quit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter element: ");
            scanf("%d", &inp);
            enqueue(inp);
            break;

        case 2:
            if (!isEmpty())
            {
                item = dequeue();
                printf("\nDequeued element is  %d\n", item);
            }
            else
            {
                printf("Queue is Empty");
            }
            break;
        case 3:
            printf("Element at front is: %d", peek());
            break;

        case 4:
            printf("The size of the Queue is %d", size);
            break;

        case 5:
            display();
            break;

        case 6:
            break;

        default:
            printf("\nInvalid input.");
            break;
        }
    } while (ch != 6);
}
