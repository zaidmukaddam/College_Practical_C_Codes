#include <stdio.h>

int power(int b, int e)
{
    int y;
    if (e == 0)
        return 1;
    else if (e % 2 == 1)
    {
        y = power(b, (e - 1) / 2);
        return b * y * y;
    }
    else
    {
        y = power(b, e / 2);
        return y * y;
    }
}

void main()
{
    int base, exponent;
    int ans;

    printf("Enter base: ");
    scanf("%d", &base);
    printf("Enter exponent: ");
    scanf("%d", &exponent);

    ans = power(base, exponent);

    printf("The ans is: %d\n", ans);
}