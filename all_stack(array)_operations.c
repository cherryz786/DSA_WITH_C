// CREATED BY PHOENIXX-3
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int MAX;
int st[], top = -1;
void push(int st[], int val);
int pop(int st[]);
int peek(int st[]);
void display(int st[]);
int main(int argc, char *argv[])
{
    printf("Enter the MAX size of the stack: ");
    scanf("%d", &MAX);
    int val, option;
    do
    {
        printf("\n\n ===== MAIN MENU =====");
        printf("\n 1. PUSH");
        printf("\n 2. POP");
        printf("\n 3. PEEK");
        printf("\n 4. DISPLAY");
        printf("\n 5. EXIT");
        printf("\n Enter your option: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("\n Enter the number to be pushed on stack: ");
            scanf("%d", &val);
            push(st, val);
            break;
        case 2:
            val = pop(st);
            if (val != -1)
                printf("\n The value deleted from stack is: %d", val);
            break;
        case 3:
            val = peek(st);
            if (val != -1)
                printf("\n The value stored at top of stack is: %d", val);
            break;
        case 4:
            display(st);
            break;
        }
    } while (option != 5);
    return 0;
}

void push(int st[], int val)
{
    if (top == MAX - 1) // condition to check if the stack is full
    {
        printf("\n STACK OVERFLOW (top == MAX - 1)");
    }
    else
    {
        top++; // top must be incremented before adding values in push operation
        st[top] = val;
    }
}
int pop(int st[])
{
    int val;
    if (top == -1)
    {
        printf("\n STACK UNDERFLOW (top == - 1)"); // condition to check whether the stack is empty
        return -1;
    }
    else
    {
        val = st[top]; // value must be popped before reducing size of the array
        top--;
        return val;
    }
}
void display(int st[])
{
    int i;
    if (top == -1)
        printf("\n STACK IS EMPTY (index = - 1");
    else
    {
        for (i = top; i >= 0; i--)
            printf("\n %d", st[i]);
        printf("\n"); // Added for formatting purposes
    }
}
int peek(int st[])
{
    if (top == -1)
    {
        printf("\n STACK IS EMPTY (index = - 1)");
        return -1;
    }
    else
        return (st[top]);
}
