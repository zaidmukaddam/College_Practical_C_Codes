/**************************
Practical 2
prg3 : Stack Implementaion using Array (Decimal to binary using Stack)
***************************/
#include <stdio.h>
#include <string.h>
#define MAX 50

char stack[MAX];
int top = -1; //Stack empty if top == -1

void push(int s) {
    top = top + 1;

    stack[top] = s;
}

int pop() {
    return stack[top--];
}

void main() {
    int dec,i;

    printf("Enter a decimal number: ");
    scanf("%d",&dec);

    while (dec!=0) {
        push(dec%2);
        dec=dec/2;
    }

    for (i = top; i >-1; i--) {
        printf("%d",pop());
    }
    printf("\n");
}