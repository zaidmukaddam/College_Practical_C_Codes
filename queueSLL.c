#include <stdio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front, *rear;

void insert(void)
{
    struct node *nn;
    nn = (struct node *)malloc(sizeof(struct node));
    printf("Enter a data: ");
    scanf("%d", &nn->data);
    nn->next = NULL;
    if (rear == NULL)
    {
        front = rear = nn;
    }
    else
    {
        rear->next = nn;
        rear = nn;
    }
    printf("%d is successfully inserted\n", nn->data);
}

void deletion(void)
{
    struct node *temp;
    int x;
    if (front == NULL)
    {
        printf("queue is empty\n");
        return;
    }
    temp = front;
    x = temp->data;
    if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        front = front->next;
    }
    free(temp);
    printf("%d is succ. deleted\n", x);
    return;
}

void display(void)
{
    struct node *temp;
    if (front == NULL)
    {
        printf("queue is empty\n");
        return;
    }
    temp = front;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    return;
}

void main()
{
    int c;
    front = rear = NULL;
    do
    {
        printf("\n1: insert\n2: delete\n3: display\n4: exit\nenter choice: ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            insert();
            break;
        case 2:
            deletion();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("program ends\n");
            break;
        default:
            printf("wrong choice\n");
        }
    } while (c != 4);
}
