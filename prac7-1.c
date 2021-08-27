#include <stdio.h>
#define MAX 4

int queue[MAX];
int rear = 0, size = 0;

int isEmpty()
{
    if (rear == 0)
        return 1;
    else
        return 0;
}

void enqueue(int num)
{
    int i;
    if (rear == MAX)
    {
        printf("OverFlow Condition\n");
    }
    else
    {
        i = rear - 1;
        while (i >= 0 && num < queue[i])
        {
            queue[i + 1] = queue[i];
            i--;
        }
        queue[i + 1] = num;
        rear++;
        size++;
    }
}

void dequeue()
{
    if (isEmpty())
    {
        printf("Underflow Condition");
    }
    else
    {
        rear = rear - 1;
        printf("Deleted Number is %d\n", queue[rear]);
        size--;
    }
}

void max()
{
    if (isEmpty())
    {
        printf("Underflow Condition");
    }
    else
    {
        printf("The MAX priority in the queue is %d", queue[rear - 1]);
    }
}

void display()
{
    int i;
    if (isEmpty())
    {
        printf("Underflow Condition");
    }
    else
    {
        for (i = 0; i < rear; i++)
        {
            printf("%d\t", queue[i]);
        }
        printf("\n");
    }
}

void main()
{
    int choice, num;

    do
    {
        printf("\nPriority Queue\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Display Max\n");
        printf("5. Size of the queue\n");
        printf("6. Quit\n");
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
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            max();
            break;
        case 5:
            printf("The size of the queue is %d\n", size);
            break;
        case 6:
            printf("Quitting...");
            break;
        default:
            printf("Wrong Input\n");
            break;
        }
    } while (choice != 6);
}
