#include <stdio.h>
#define MAX 10

int binarysum(int a[], int i, int n)
{
    if (n == 1)
    {
        return a[i];
    }
    else
    {
        if (n % 2 == 0)
        {
            return binarysum(a, i, n / 2) + binarysum(a, i + n / 2, n / 2);
        }
        else
        {
            return binarysum(a, i, n / 2) + binarysum(a, i + n / 2, n / 2 + 1);
        }
    }
}

int main()
{
    int arr[MAX], n, i, sum;

    printf("Enter n: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter a number of subscript %d: ", i);
        scanf("%d", &arr[i]);
    }

    sum = binarysum(arr, 0, n);

    printf("The binary sum is: %d", sum);

    return 0;
}
