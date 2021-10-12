#include <stdio.h>
#include <malloc.h>

// Node Structure
struct node
{
    int num;           // value of node
    struct node *next; // next node
};

// size of the Linked List
int size;

// Head of the node
struct node *head = NULL;

// Add an Element in the start of the node
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
    size++;
}

// Add an element in the end of the node
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
    size++;
}

// Delete the Element at the start of the node
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
    size--;
}

// Delete the Element from the end of the node
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
    size--;
}

// Add an element in the middle of the node
void insert_middle()
{
    int m, n;
    struct node *newNode;
    struct node *temp;

    printf("Enter m: ");
    scanf("%d", &m);
    printf("Enter n: ");
    scanf("%d", &n);
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->num = m;
    newNode->next = NULL;

    temp = head;

    while (temp->num != n)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            break;
        }
    }
    if (temp == NULL)
    {
        printf("The number %d does not exist\n", n);
    }
    else
    {
        newNode->next = temp->next;
        temp->next = newNode;
    }
    size++;
}

// Delete any Element of the node
void delete_any()
{
    int n;
    struct node *ptr, *prev;
    ptr = head;
    prev = head;

    printf("Enter the number to be deleted: ");
    scanf("%d", &n);

    while (ptr->num != n)
    {
        prev = ptr;
        ptr = ptr->next;
        if (ptr == NULL)
        {
            break;
        }
    }

    if (ptr == NULL)
    {
        printf("The number %d does not exist\n", n);
    }
    else
    {
        prev->next = ptr->next;
        printf("Deteted number %d\n", ptr->num);
        free(ptr);
    }
    size--;
}

// Display the Linked List
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

int main()
{
    int choice;

    do
    {
        printf("\n1. Add a value at start of the Linked List\n");
        printf("2. Delete value at start of the Linked List\n");
        printf("3. Add a value at last of the Linked List\n");
        printf("4. Delete a value at last of the Linked List\n");
        printf("5. Display the Linked List\n");
        printf("6. Add a value in the middle of the Linked List\n");
        printf("7. Delete any value of the Linked List\n");
        printf("8. Display Size of the Linked List\n");
        printf("9. Quit\n");
        printf("Enter a choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            add_start();
            break;
        case 2:
            delete_start();
            break;
        case 3:
            add_last();
            break;
        case 4:
            delete_last();
            break;
        case 5:
            display();
            break;
        case 6:
            insert_middle();
            break;
        case 7:
            delete_any();
            break;
        case 8:
            printf("The Size of the Linked List is: %d", size);
            break;
        case 9:
            break;
        default:
            printf("Wrong Input");
            break;
        }
    } while (choice != 9);

    return 0;
}

/* Test Case
1
1
1
2
1
3
1
4
1
5
7
2
5
8
*/