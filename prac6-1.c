#include <stdio.h>
#define MAX 6

int queue[MAX];
int front = -1, rear = -1, size = 0;

void display()
{
    int i;
    if (front == -1 && rear == -1)
    {
        printf("Queue is Empty");
    }
    else if (front < rear)
    {
        for (i = front; i <= rear; i++)
        {
            printf("[%d]=%d\t", i, queue[i]);
        }
    }
    else if (rear < front)
    {
        for (i = front; i <= MAX - 1; i++)
        {
            printf("[%d]=%d\t", i, queue[i]);
        }
        for (i = 0; i <= rear; i++)
        {
            printf("[%d]=%d\t", i, queue[i]);
        }
    }
}

int dequeue()
{
    int val = -1;
    if (front == -1)
    {
        printf("Queue Empty-UnderFlow Condition\n");
    }
    else
    {
        val = queue[front];
        if (front == rear)
        {
            front = rear = -1;
        }
        else if (front == MAX - 1)
        {
            front = 0;
        }
        else
        {
            front = front + 1;
        }
        size--;
    }
    return (val);
}

void enqueue(int num)
{
    if ((front == 0 && rear == MAX - 1 || (rear == front - 1)))
    {
        printf("Queue Full-Overflow Condition");
    }
    else
    {
        if (front == -1 && rear == -1)
        {
            front = rear = 0;
        }
        else if (rear == MAX - 1 && front != 0)
        {
            rear = 0;
        }
        else
        {
            rear = rear + 1;
        }
        queue[rear] = num;
        size++;
    }
}

void peek()
{
    printf("The front of the queue is %d\n", queue[front]);
}

void main()
{
    int choice, val, num;
    do
    {
        printf("\nMenu Operations for Queue\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Size\n");
        printf("4. Front\n");
        printf("5. Display the Queue\n");
        printf("6. Quit The program\n");
        printf("Enter a choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter a number: ");
            scanf("%d", &num);
            enqueue(num);
            break;
        case 2:
            val = dequeue();
            if (val == -1)
            {
                printf("Queue Empty - Underflow Condition\n");
            }
            else
            {
                printf("Deleted Element is %d\n", val);
            }
            break;
        case 3:
            printf("The number of elements %d\n", size);
            break;
        case 4:
            peek();
            break;
        case 5:
            display();
            break;
        case 6:
            printf("Quiting the program....\n");
            break;
        default:
            printf("Wrong Input");
            break;
        }
    } while (choice != 6);
}
