#include <stdio.h>
#define MAX 20

int linearsum(int a[], int n)
{
    if (n == 1)
    {
        return a[0];
    }
    else
    {
        return linearsum(a, n - 1) + a[n - 1];
    }
}
void main()
{
    int arr[MAX], n, i, sum;

    printf("Enter n: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter a number of subscript %d: ", i);
        scanf("%d", &arr[i]);
    }

    sum = linearsum(arr, n);

    printf("The linearsum sum is: %d", sum);
}