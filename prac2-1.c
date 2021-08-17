/**************************
Practical 2
prg1 : Stack Implementaion using Array (Menu driven stack ops)
***************************/
#include <stdio.h> 
#define MAX 5

int stack[MAX];
int top = -1; //Stack empty if top == -1

void push() {
    int num;
    if (top == (MAX-1)){
        printf("Stack is Full-Overflow Error\n");
    }
    else{
        top = top + 1;
        printf("Enter a number: ");
        scanf("%d",&num);
        stack[top]= num;
    }
}

int pop() {
    int num;
    if (top==-1){
        printf("Stack is Empty-UnderFlow Error\n");
        return -1;
    }
    else{
        num = stack[top];
        top = top - 1;
        return(num);
    }
}

int isEmpty() {
    if (top == -1)
        return 1;
    else
        return 0;    
}

void display() {
    int i;
    for (int i = 0; i <= top; i++)
        printf("stack[%d] = %d\n",i,stack[i]);
}

void topmost() {
    printf("Top Element %d\n",stack[top]);
}

void size() {
    printf("Total Elements %d\n",top+1);
}

void main() {
    int choice;
    printf("Stack Operations\n");

    do
    {
        printf("Menu\n");
        printf("1. Push or Add Elements in the stack.\n2. Pop or Remove elements in the stack.\n3. Display Entire Stack\n4. print topmost element\n5. Size of the stack.\n6. Quit");
        printf("\nEnter a choice: ");
        scanf("%d",&choice);

        switch (choice)
        {
            case 1: push(); break;
            case 2:
                if (isEmpty() == 0)            
                    printf("The popped number is %d\n",pop());
                else
                    printf("Stack is empty");
                break;
            case 3: display(); break;
            case 4: topmost(); break;
            case 5: size(); break;
            case 6: printf("Quitting"); break;
            default: printf("Wrong Choice\n"); break;
        }
    } while (choice!=6);   
}