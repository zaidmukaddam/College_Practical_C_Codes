#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;
struct node *tail = NULL;

struct node *current = NULL;
struct node *new_node = NULL;

int length()
{
    int length = 0;
    struct node *current;
    for (current = head; current != NULL; current = current->next)
    {
        length++;
    }
    return length;
}

void displayForward()
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

void displayBackward()
{
    struct node *ptr = tail;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->prev;
    }
}

void insertFirst(int new_data)
{
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->prev = NULL;
    if (head != NULL)
        head->prev = new_node;
    else
        tail = new_node;
    new_node->next = head;
    head = new_node;
}

void insertLast(int new_data)
{
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = NULL;
    if (head == NULL)
    {
        new_node->prev = NULL;
        head = new_node;
    }
    else
    {
        tail->next = new_node;
        new_node->prev = tail;
    }
    tail = new_node;
}

void insertBefore(int key, int new_data)
{
    struct node *next_node = head;
    if (head == NULL)
    {
        printf("List empty");
    }
    else
    {
        while (next_node->data != key)
        {
            if (next_node->next == NULL)
                insertFirst(key);
            else
                next_node = next_node->next;
        }
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = new_data;
        new_node->prev = next_node->prev;
        next_node->prev = new_node;
        new_node->next = next_node;
        if (new_node->prev != NULL)
            new_node->prev->next = new_node;
        else
            head = new_node;
    }
}

void insertAfter(int key, int new_data)
{
    struct node *prev_node = head;
    if (head == NULL)
    {
        printf("List Empty");
    }
    else
    {
        while (prev_node->data != key)
        {
            if (prev_node->next == NULL)
                insertLast(key);
            else
                prev_node = prev_node->next;
        }
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = new_data;
        new_node->next = prev_node->next;
        prev_node->next = new_node;
        new_node->prev = prev_node;
        if (new_node->next != NULL)
            new_node->next->prev = new_node;
    }
}

void delete1(int key)
{
    struct node *del = head;
    if (head == NULL)
    {
        printf("List Empty");
    }
    else if (head->next == NULL || tail->prev == NULL)
    {
        head = tail = NULL;
        free(del);
        printf("\nDeleted the last node\n");
    }
    else
    {
        while (del->data != key)
            del = del->next;
        if (del != NULL)
        {
            if (head == del)
                head = del->next;
            if (tail == del)
                tail = tail->prev;
            if (del->next != NULL)
                del->next->prev = del->prev;
            if (del->prev != NULL)
                del->prev->next = del->next;
            free(del);
        }
        else
            printf("Node not found");
    }
}

int main()
{
    insertFirst(10);
    insertFirst(20);
    insertFirst(30);
    insertFirst(40);
    insertFirst(50);
    printf("\nList (First to Last): ");
    displayForward();
    printf("\n");
    printf("\nList (Last to first): ");
    displayBackward();
    printf("\n\nInsert at the end : ");
    printf("\nList (First to Last): ");
    insertLast(100);
    displayForward();
    printf("\n\nInsert Before : ");
    printf("\nList (First to Last): ");
    insertBefore(40, -40);
    displayForward();
    printf("\n\nInsert Before BUT BEFORE FIRST NODE: ");
    printf("\nList (First to Last): ");
    insertBefore(50, -50);
    displayForward();
    printf("\n\nInsert After : ");
    printf("\nList (First to Last): ");
    insertAfter(50, 500);
    displayForward();
    printf("\n\nInsert After BUT AFTER LAST NODE: ");
    printf("\nList (First to Last): ");
    insertAfter(100, 1000);
    displayForward();
    printf("\n\nList after deleting first record: ");
    delete1(-50);
    displayForward();
    printf("\n\nList after deleting last record: ");
    delete1(1000);
    displayForward();
    printf("\n\nList after delete key(40) : ");
    delete1(40);
    displayForward();
    printf("\n\nList after certain deletes : ");
    delete1(500);
    delete1(100);
    delete1(50);
    delete1(10);
    delete1(-40);
    delete1(20);
    displayForward();
    delete1(30);
    displayForward();
    insertLast(100);
    displayForward();
    return 0;
}