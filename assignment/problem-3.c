#include <stdio.h>

struct queue
{
    int front, rear;
    int arr[5];
} q1, q2;

void push1(int x)
{
    if (q1.front == -1)
    {
        q1.front++;
        q1.rear++;
        q1.arr[q1.rear] = x;
    }
    else
        q1.arr[++q1.rear] = x;
}

void push2(int x)
{
    if (q2.front == -1)
    {
        q2.front++;
        q2.rear++;
        q2.arr[q2.rear] = x;
    }
    else
        q2.arr[++q2.rear] = x;
}

int pop()
{
    int k;
    while (q1.front != q1.rear)
    {
        k = q1.arr[q1.front++];
        printf("%d ", k);
        push2(k);
    }
    k = q1.arr[q1.front];
    q1.front = q1.rear = -1;
    struct queue q = q1;
    q1 = q2;
    q2 = q;
    return k;
}

void display()
{
    int i;
    if (q1.front != -1)
    {
        for (i = q1.front; i <= q1.rear; i++)
            printf("%d ", q1.arr[i]);
    }
    else
    {
        printf("q1 empty.\n");
    }
    if (q2.front != -1)
    {
        for (i = q2.front; i <= q2.rear; i++)
            printf("%d ", q2.arr[i]);
    }
    else
    {
        printf("q2 empty.\n");
    }
}

int main()
{
    int i, x, op, k;
    q1.front = q1.rear = q2.front = q2.rear = -1;
    do
    {
        printf("1.) Push\n2.) Pop\n3.) display\n");
        printf("Enter choice : ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("Enter no. : ");
            scanf("%d", &x);
            push1(x);
            break;
        case 2:
            k = pop();
            printf("Popped element : %d\n", k);
            break;
        case 3:
            display();
            break;
        }
    } while (op < 4);
    return 0;
}