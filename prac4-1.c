#include <stdio.h>
#define MAX 10

void swap(int *num, int *number)
{
    int temp;
    temp = *num;
    *num = *number;
    *number = temp;
}

void reversearray(int a[], int i, int j)
{
    if (i < j)
    {
        swap(&a[i], &a[j]);
        reversearray(a, i + 1, j - 1);
    }
}

void main()
{
    int arr[MAX], n, i;

    printf("Enter n: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter a number of subscript %d: ", i);
        scanf("%d", &arr[i]);
    }

    reversearray(arr, 0, n - 1);

    printf("The reverse array is: ");

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}