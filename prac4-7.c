#include <stdio.h>

int mystery(int x, int y)
{
    if (x == y)
        return 0;
    else
        return mystery(x - 1, y) + 1;
}

int main()
{
    printf("%d", mystery(8, 3));
    return 0;
}
