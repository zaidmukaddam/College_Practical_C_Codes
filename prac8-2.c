#include <stdio.h>
#define MAX 10

struct queue
{
    int front, rear;
    int item[MAX];
};

void enqueue(struct queue *qptr, int val)
{
    qptr->rear++;
    qptr->item[qptr->rear] = val;
}

int dequeue(struct queue *qptr)
{
    int val;
    val = qptr->item[qptr->front];
    qptr->front++;
    return val;
}

int findmax(int arr[], int n)
{
    int i;
    int max = arr[0];

    for (i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

void print(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int empty(struct queue *qptr)
{
    if (qptr->rear < qptr->front)
        return 1;
    return 0;
}

int radixsort(int arr[], int count, int n)
{
    struct queue qu[MAX];
    int i, j, k, rem, place = 1;

    for (i = 1; i <= count; i++, place *= 10)
    {
        for (j = 0; j < MAX; j++)
        {
            qu[j].front = 0;
            qu[j].rear = -1;
        }

        for (j = 0; j < n; j++)
        {
            rem = arr[j] % (place * 10);
            rem = rem / place;
            enqueue(&qu[rem], arr[j]);
        }

        for (j = 0, k = 0; j < MAX; j++)
        {
            while (empty(&qu[j]) == 0)
            {
                arr[k] = dequeue(&qu[j]);
                k++;
            }
        }
        printf("Interation of %d place: \n", place);
        print(arr, n);
    }
}

int main()
{
    int a[MAX];
    int maximum, count = 0, n, i;

    printf("Enter n: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter a[%d] = ", i);
        scanf("%d", &a[i]);
    }

    maximum = findmax(a, n);

    while (maximum > 0)
    {
        maximum = maximum / 10;
        count++;
    }

    radixsort(a, count, n);
    printf("The Sorted array: \n");
    print(a, n);

    return 0;
}
