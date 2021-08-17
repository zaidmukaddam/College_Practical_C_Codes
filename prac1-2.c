/**************************
Practical 1
prg2 : Inventory Updating using Array of Structures
***************************/
#include <stdio.h>

struct inventory
{
    char name[20];
    float rate;
    int qty;
    float price;
};
struct inventory input_item(struct inventory a) {
    printf("Enter Item Name : ");
    scanf("%s",&a.name);
    printf("Enter Item Rate : ");
    scanf("%f",&a.rate);
    printf("Enter Item Qty : ");
    scanf("%d%*c",&a.qty);
    return a;
}

void output_item(struct inventory a) {
    printf("OUTPUT\n");
    printf("Item Name : %s\n",a.name);
    printf("Item Rate : %f\n",a.rate);
    printf("Item Qty : %d\n",a.qty);
    printf("Item Price : %f\n",a.price);
}

float calc(float a, int b) {
    return a*b;
}

void main() {
    struct inventory item[10];    //Single structure variable called item 
    int n,i,j;

    printf("Practical Prg1\n");
    printf("Inventory Updating\n");
    printf("Implementing Inventory Updating using Array of Structures\n\n");

    printf("Enter number of records: ");
    scanf("%d%*c",&n);

    for (i = 0; i < n; i++) {
        item[i] = input_item(item[i]);
        item[i].price = calc(item[i].rate,item[i].qty);
    }
    
    for (i = 0; i < n; i++) {
        output_item(item[i]);
    }
    

    printf("Enter a subscript: ");
    scanf("%d",&j);
    j-=1;
    printf("Enter a new rate: ");
    scanf("%f",&item[j].rate);
    printf("\nEnter a new qty: ");
    scanf("%d",&item[j].qty);

    item[j].price = calc(item[j].rate,item[j].qty);
    
    output_item(item[j]);
    
}