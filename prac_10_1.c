#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

struct node
{
    int num;
    struct node *next;
};

struct node *top = NULL;
struct node *front = NULL;
struct node *rear = NULL;

void push()
{
    int n;
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter a number: ");
    scanf("%d", &n);
    newNode->num = n;
    newNode->next = NULL;

    if (top == NULL)
    {
        top = newNode;
    }
    else
    {
        newNode->next = top;
        top = newNode;
    }
}

void pop()
{
    struct node *ptr;

    if (top == NULL)
    {
        printf("UnderFlow condition: Stack is Empty");
    }
    else
    {
        ptr = top;
        top = top->next;
        printf("The deleted number is %d\n", ptr->num);
        free(ptr);
    }
}

void enqueue()
{
    struct node *newNode;
    int n;
    printf("Enter a value: ");
    scanf("%d", &n);
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->num = n;
    newNode->next = NULL;

    if (front == NULL)
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue()
{
    struct node *ptr;
    if (front == NULL)
    {
        printf("Underflow Condition-Queue is Empty\n");
    }
    else
    {
        ptr = front;
        front = front->next;
        printf("Deleted node value is %d\n", ptr->num);
        free(ptr);
    }
}

void display(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("[%d]->", ptr->num);
        ptr = ptr->next;
    }
    printf("\n");
}

void peek(struct node *ptr)
{
    printf("The first node is %d\n", ptr->num);
}

int main()
{
    int choice, subchoice;
    do
    {
        printf("Main Menu\n1. Stack\n2. Queue\n3. Quit\n");
        printf("Enter an option: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Sub Menu of Stack\n1. Push\n2. Pop\n3. Display\n4. Peek\n");
            printf("Enter your choice: ");
            scanf("%d", &subchoice);
            switch (subchoice)
            {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display(top);
                break;
            case 4:
                peek(top);
                break;
            default:
                break;
            }
            break;
        case 2:
            printf("Sub Menu of Stack\n1. Enqueue\n2. Dequeue\n3. Display\n4. Peek\n");
            printf("Enter your choice: ");
            scanf("%d", &subchoice);
            switch (subchoice)
            {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display(front);
                break;
            case 4:
                peek(front);
                break;
            default:
                break;
            }
            break;
        case 3:
            break;
        default:
            break;
        }
    } while (choice != 3);

    return 0;
}
