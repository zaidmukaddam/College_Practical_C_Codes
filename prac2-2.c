/**************************
Practical 2
prg2 : Stack Implementaion using Array (Reverse a string using Stack)
***************************/
#include <stdio.h>
#include <string.h>
#define MAX 50

char stack[MAX];
int top = -1; //Stack empty if top == -1

void push(char s) {
    top = top + 1;

    stack[top] = s;
}

char pop() {
    return stack[top--];
}

void main() {
    char str[MAX];
    int i,len;
    printf("Enter a String: ");
    gets(str);
    len = strlen(str);

    for (i = 0; i < len; i++) {
        push(str[i]);
    }

    printf("Reversed Sting: ");

    for ( i = 0; i < len; i++) {
        printf("%c",pop());
    }
    printf("\n");
}