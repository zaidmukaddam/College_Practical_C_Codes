#include <stdio.h>
#define MAX 10

float binarysum(float a[], int i, int n)
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

float main()
{
    float arr[MAX], sum;
    int i,n;
    printf("Enter n: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter a number of subscript %d: ", i);
        scanf("%f", &arr[i]);
    }

    sum = binarysum(arr, 0, n);

    printf("The binary sum is: %f", sum);

    return 0;
}
/* Output
Enter n: 4 
Enter a number of subscript 0: 23.5
Enter a number of subscript 1: 12.2
Enter a number of subscript 2: 13.5
Enter a number of subscript 3: 3.1
The binary sum is: 52.300003
*/