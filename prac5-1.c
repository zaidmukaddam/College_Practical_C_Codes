#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int queue_arr[MAX];
int rear = -1;
int front = -1;
int size = 0;

int isEmpty()
{
    if (front == -1 || front == rear + 1)
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

void enqueue(int item)
{
    if (isFull())
    {
        printf("\nQueue Overflow\n");
        return;
    }
    if (front == -1)
        front = 0;
    rear = rear + 1;
    queue_arr[rear] = item;
    size++;
}

int dequeue()
{
    int item;
    if (isEmpty())
    {
        printf("\nQueue Underflow\n");
        exit(1);
    }
    item = queue_arr[front];
    front = front + 1;
    size--;
    return item;
}

int peek()
{
    if (isEmpty())
    {
        printf("\nQueue Underflow\n");
        exit(1);
    }
    return queue_arr[front];
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
        printf("%d  ", queue_arr[i]);
    printf("\n\n");
}

int main()
{
    int choice, item;
    while (1)
    {
        printf("\n1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Display element at the front\n");
        printf("4.Display all elements of the queue\n");
        printf("5.Display Size of the Queue\n");
        printf("6.Quit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nInput the element for adding in queue : ");
            scanf("%d", &item);
            enqueue(item);
            break;
        case 2:
            item = dequeue();
            printf("\nDequeued element is  %d\n", item);
            break;
        case 3:
            printf("\nElement at the front is %d\n", peek());
            break;
        case 4:
            display();
            break;
        case 5:
            printf("The size of the Queue is %d", size);
            break;
        case 6:
            exit(1);
        default:
            printf("\nWrong choice\n");
        }
    }

    return 0;
}
