#include <stdio.h>
#define MAX 11

void countingsort(int arr[], int n, int exp)
{
    int output[n]; 
    int i, count[10] = {0};

    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

int findmax(int arr[], int n)
{
    int i;
    int max = arr[0];

    for (i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void radixsort(int arr[], int n)
{
    int max = findmax(arr, n);
    int j;

    for (j = 1; max / j > 0; j *= 10)
    {
        countingsort(arr, n, j);
    }
}

void printsort(int arr[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[MAX];
    int i, n;

    printf("Enter n: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    printf("\nThe input is: ");

    printsort(arr, n);

    radixsort(arr, n);

    printf("The sorted array is: ");

    printsort(arr, n);

    return 0;
}
