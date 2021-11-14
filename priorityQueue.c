#include <stdio.h>
#define N 8

int r = -1, f = -1;

struct entry
{
    int data;
    int Pr;
} PQ[N];

void enqueue(int d, int p)
{
    int i;
    if ((f == 0) && (r == N - 1))
        printf("Queue is full");
    else
    {
        if (f == -1)
        {
            f = r = 0;
            PQ[r].data = d;
            PQ[r].Pr = p;
        }
        else if (r == N - 1)
        {
            for (i = f; i <= r; i++)
            {
                PQ[i - f].data = PQ[i].data;
                PQ[i - f].Pr = PQ[i].Pr;
            }

            r = r - f;
            f = 0;

            for (i = r; i >= f; i--)
            {
                if (p > PQ[i].Pr)
                {
                    PQ[i + 1].data = PQ[i].data;
                    PQ[i + 1].Pr = PQ[i].Pr;
                }
                else
                    break;
            }

            PQ[i + 1].data = d;
            PQ[i + 1].Pr = p;
            
            r++;
        }
        else
        {
            for (i = r; i >= f; i--)
            {
                if (p > PQ[i].Pr)
                {
                    PQ[i + 1].data = PQ[i].data;
                    PQ[i + 1].Pr = PQ[i].Pr;
                }
                else
                    break;
            }
            PQ[i + 1].data = d;
            PQ[i + 1].Pr = p;
            r++;
        }
    }
}

void print()
{
    int i;
    if (f == -1 && r == -1)
        printf("Q is empty\n");
    else
    {
        for (i = f; i <= r; i++)
            printf("\nElement = %d\t Priority = %d", PQ[i].data, PQ[i].Pr);
    }
}

int dequeue()
{
    if (f == -1)
    {
        printf("Queue is Empty");
    }
    else
    {
        printf("deleted Element = %d\t Its Priority = %d", PQ[f].data, PQ[f].Pr);
        if (f == r)
            f = r = -1;
        else
            f++;
    }
}

int main()
{
    int opt, n, i, data, p;
    printf("Enter Your Choice:-");
    do
    {
        printf("\n\n1 for Insert the Data in Queue\n2 for show the Data in Queue \n3 for Delete the data from the Queue\n0 for Exit\nEnter your choice: ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            printf("\nEnter your data and Priority of data: ");
            scanf("%d %d", &data, &p);
            enqueue(data, p);
            break;
        case 2:
            print();
            break;
        case 3:
            dequeue();
            break;
        case 0:
            break;
        default:
            printf("\nIncorrect Choice");
        }
    } while (opt != 0);
    return 0;
}