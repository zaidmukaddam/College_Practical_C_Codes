#include <stdio.h>

void printit(int x)
{
    if (x >= 1)
    {
        printf("*");
        x--;
        printit(x);
    }
    if (x != 1)
    {
        printf("!");
    }
}

void main()
{
    printit(6);
}
