#include <stdio.h>
#include <stdlib.h>
#define MAX 5

void display(int arr[])
{
    for (int i = 0; i < MAX; i++)
    {
        printf("%d ", arr[i]);
    }
}

void swap(int *num, int *number)
{
    int temp;
    temp = *num;
    *num = *number;
    *number = temp;
}

void selection_sort(int arr[])
{
    int i, j, temp;

    for (i = 0; i < MAX - 1; i++)
    {
        for (j = i + 1; j < MAX; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(&arr[i], &arr[j]);
            }
        }
    }

    printf("After Selection sort Elements are : ");

    display(arr);
}

void insertion_sort(int arr[])
{

    int i, j, min;

    for (i = 1; i < MAX; i++)
    {
        min = arr[i];

        for (j = i - 1; min < arr[j] && j >= 0; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = min;
    }
    printf("After Insertion sort Elements are : ");

    display(arr);
}

void takeinput(int arr[])
{
    int i;
    for (i = 0; i < MAX; i++)
    {
        printf("Enter Element %d : ", i + 1);
        scanf("%d", &arr[i]);
    }
}

int main()
{
    int choice, i;

    int arr[MAX];

    do
    {

        printf("\nPlease select any option Given Below for Sorting : \n");

        printf("\n1. Insertion Sort\n2. Selection Sort\n3. Display Array.\n4. Exit the Program.\n");

        printf("\nEnter your Choice : ");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            takeinput(arr);
            selection_sort(arr);
            break;
        case 2:
            takeinput(arr);
            insertion_sort(arr);
            break;
        case 3:
            display(arr);
            break;
        case 4:
            break;
        default:
            printf("\nPlease Select only 1-4 option ----\n");
        }
    } while (choice != 4);
}
