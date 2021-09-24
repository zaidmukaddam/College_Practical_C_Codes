#include <stdio.h>
#include <malloc.h>

struct node
{
    int num;
    struct node *next;
};

struct node *head = NULL;

void add_start()
{
    int number;
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter the number to be added: ");
    scanf("%d", &number);

    newnode->num = number;
    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        newnode->next = head;
        head = newnode;
    }
}

void add_last()
{
    int number;
    struct node *newnode;
    struct node *ptr;
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter the number to be added: ");
    scanf("%d", &number);

    newnode->num = number;
    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newnode;
    }
}

void delete_start()
{
    struct node *ptr;
    ptr = head;
    if (head == NULL)
    {
        printf("List is Empty\n");
    }
    else if (head->next == NULL)
    {
        printf("Deleted node value is %d\n", head->num);
        head = NULL;
        free(ptr);
    }
    else
    {
        head = head->next;
        printf("Deleted Node is %d\n", ptr->num);
        free(ptr);
    }
}

void delete_last()
{
    struct node *ptr, *prev;
    ptr = head;
    prev = head;

    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else if (head->next == NULL)
    {
        printf("Deleted node value is %d\n", head->num);
        head = NULL;
        free(ptr);
    }
    else
    {
        while (ptr->next != NULL)
        {
            prev = ptr;
            ptr = ptr->next;
        }

        prev->next = NULL;
        printf("Deleted node value is %d\n", ptr->num);
        free(ptr);
    }
}

void display()
{
    struct node *ptr;
    ptr = head;
    if (head == NULL)
    {
        printf("Empty list");
    }
    else
    {
        while (ptr != NULL)
        {
            printf("%d\t", ptr->num);
            ptr = ptr->next;
        }
    }
}

int main(int argc, char const *argv[])
{
    int choice;

    do
    {
        printf("\n1. Add a value at start of the Linked List\n");
        printf("2. Display the Linked List\n");
        printf("3. Add a value at last of the Linked List\n");
        printf("4. Delete value at start of the Linked List\n");
        printf("5. Delete a value at last of the Linked List\n");
        printf("6. Quit\n");
        printf("Enter a choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            add_start();
            break;
        case 2:
            display();
            break;
        case 3:
            add_last();
            break;
        case 4:
            delete_start();
            break;
        case 5:
            delete_last();
            break;
        case 6:
            break;
        default:
            printf("Wrong Input");
            break;
        }
    } while (choice != 6);

    return 0;
}
