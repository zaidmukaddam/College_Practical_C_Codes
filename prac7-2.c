#include <stdio.h>
#define MAX 5

struct item
{
    int key;
    int value;
};

struct item queue[MAX];

int rear = 0, size = 0;

int isEmpty()
{
    if (rear == 0)
        return 1;
    else
        return 0;
}

void enqueue(int key, int num)
{
    int i;
    if (rear == MAX)
    {
        printf("OverFlow Condition\n");
    }
    else
    {
        i = rear - 1;
        while (i >= 0 && key < queue[i].key)
        {
            queue[i + 1].key = queue[i].key;
            queue[i + 1].value = queue[i].value;
            i--;
        }
        queue[i + 1].value = num;
        queue[i + 1].key = key;
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
        printf("Deleted Number is %d at %d\n", queue[rear].value, queue[rear].key);
        size--;
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
            printf("%d => %d\n", queue[i].key, queue[i].value);
        }
        printf("\n");
    }
}

void main()
{
    int choice, key, num;

    do
    {
        printf("\nPriority Queue\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Size of the queue\n");
        printf("5. Quit\n");
        printf("Enter a choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the key: ");
            scanf("%d", &key);
            printf("Enter a number: ");
            scanf("%d", &num);
            for (int i = 0; i < rear; i++)
            {
                if (key == queue[i].key)
                {
                    printf("The key [%d] alredy exists", queue[i].key);
                    break;
                }
            }
            enqueue(key, num);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("The size of the queue is %d\n", size);
            break;
        case 5:
            printf("Quitting...");
            break;
        default:
            printf("Wrong Input\n");
            break;
        }
    } while (choice != 5);
}
