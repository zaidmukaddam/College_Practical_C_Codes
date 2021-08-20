#include <stdio.h>
#define MAX 10

int queue[MAX];
int front = -1, rear = -1, external = 0, start = 0;

int isEmpty()
{
    if (front == -1 && rear == -1)
        return 1;
    else
        return 0;
}

int isFull()
{
    if (rear == MAX - 1)
        return 1;
    else
        return 0;
}

void enqueue(int inp)
{
    int i;
    if (MAX == external)
    {
        printf("Queue overflow.");
    }
    else if (!isFull())
    {
        if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = rear + 1;
        }
        queue[rear] = inp;
        external = external + 1;
    }
    else
    {
        queue[start] = inp;
        start = start + 1;
        external = external + 1;
    }
    for (i = 0; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
}

void dequeue()
{
    int item, i;
    if (isEmpty())
    {
        printf("\nQueue Underflow\n");
    }
    else if (front == rear)
    {
        item = queue[front];
        front = -1;
        rear = -1;
    }
    else
    {
        item = queue[front];
        front = front + 1;
    }
    external = external - 1;
    printf("Popped element is: %d\n", item);
    for (i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
}

int peek()
{
    if (isEmpty())
    {
        printf("\nQueue Underflow\n");
        return 0;
    }
    return queue[front];
}

void size()
{
    int total = 0, i;
    for (i = front; i <= rear; i++)
    {
        total = total + 1;
    }
    printf("Size of current queue: %d\n", total);
}

void display()
{
    int i;
    if (isEmpty())
    {
        printf("\nQueue is empty\n");
        return;
    }
    printf("\nQueue is :\n\n");
    for (i = front; i <= rear; i++)
        printf("%d  ", queue[i]);
    printf("\n\n");
}

void main()
{
    int inp, ch;
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
            dequeue();
            break;

        case 3:
            printf("Element at front is:%d", peek());
            break;

        case 4:
            size();
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
