/**************************
Practical 1
prg3 : Pointer to a Structure Variable
***************************/
#include <stdio.h>

struct inventory
{
    char name[20];
    float rate;
    int qty;
    float price;
};
struct inventory input_item(struct inventory *a)
{
    printf("Enter Item Name : ");
    scanf("%s", &a->name);
    printf("Enter Item Rate : ");
    scanf("%f", &a->rate);
    printf("Enter Item Qty : ");
    scanf("%d", &a->qty);
}

void output_item(struct inventory a)
{
    printf("OUTPUT\n");
    printf("Item Name : %s\n", a.name);
    printf("Item Rate : %f\n", a.rate);
    printf("Item Qty : %d\n", a.qty);
    printf("Item Price : %f\n", a.price);
}

struct inventory calculate_price(struct inventory *item)
{
    item->price = item->rate * item->qty;
}

void main()
{
    struct inventory item; //Single structure variable called item

    printf("Practical Prg3\n");
    printf("Inventory Updating\n");
    printf("Implementing Pointer to a Structure Variable\n\n");

    input_item(&item);
    calculate_price(&item);

    output_item(item);

    printf("Enter a new rate: ");
    scanf("%f", &item.rate);
    printf("\nEnter a new qty: ");
    scanf("%d", &item.qty);

    calculate_price(&item);

    output_item(item);
}