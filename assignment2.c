#include<stdio.h>
#include<unistd.h>

#define MAX 50
int choice, element;

struct stack
{
    int data[MAX];
    int top;
};

void welcome()
{
    // welcome message;
    printf("\nWELCOME TO THE STACK MANIPULATION CENTER!\n");
}

void options()
{
    // Operations;
    printf("\n\nNow, enter the operation number you want to perform with this Stack: \n");
    printf("0. Push\n");
    printf("1. Pop\n");
    printf("2. Peek\n");
    printf("3. Display\n");
    printf("4. Destroy\n");
    printf("5. Exit\n");
    printf("Enter a number from 0 to 5, inclusive: \t");
    scanf("%d", &choice);
}

void initialize(struct stack *s) {
    s->top = -1;
}

int isEmpty(struct stack *s) {
    return (s->top == -1);
}

int isFull(struct stack *s) {
    return (s->top == MAX - 1);
}

void push(struct stack *s, int e)
{
    if(isFull(s))
        printf("\n The stack is full-Overflow Condition");
    else
    {
        s->data[++s->top] = e;
        printf("\n Pushed Successfully.");
    }
}

void pop(struct stack *s)
{
    int popped;
    if(isEmpty(s))
    printf("\n The stack in empty-Underflow Condition");
    else
    {
        popped = s->data[s->top--];
        printf("\n Popped Element: %d", popped);
    }
}

void peek(struct stack *s)
{
    if (isEmpty(s))
        printf("\n No elements in the stack");
    else
        printf("\n Data at peek is %d", s->data[s->top]);
}

void display(struct stack *s)
{
    int i;
    if (isEmpty(s))
        printf("\n No elements in the stack: Underflow");
    else
    {
        printf("\n The elements in the stack are: ");
        for(i = s->top; i >= 0; i--)
            printf("\n %d", s->data[i]);
    }
}

void destroy(struct stack *s)
{
    // s->top = -1;

    while(s->top != -1)
        pop(s);
}

void end()
{
    printf("\nThank you for using our services!\nSee you again!\n");
}

void main()
{
    struct stack st;
    initialize(&st);

    welcome();
    options();

    while(1)
    {
        options();
        switch(choice)
        {
            case 0:
                {
                    printf("\n Enter an element you want to push: ");
                    scanf("%d", &element);
                    push(&st, element);
                    break;
                }
            case 1:
                pop(&st);
                break;
            case 2:
                peek(&st);
                break;
            case 3:
                display(&st);
                break;
            case 4:
                destroy(&st);
                break;
            case 5:
                {
                    end();
                    exit(0);
                }
            default:
                printf("\n* Option not valid! *");
        }
    }
}
