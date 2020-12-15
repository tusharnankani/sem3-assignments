#include<stdio.h>
#include<stdlib.h>

#define MAX 50

char ch, postfix[MAX];
int stack[MAX], top, ans;

int priorityCheck(char c)
{
    return (c == '$' || c == '^' || c == '*' || c == '/' || c == '%' || c == '+' || c == '-');
}

void push(int temp)
{

    if(top == MAX-1)
        printf("\nStack full! Increase Stack Size.");
    else
        stack[++top] = temp;
}

void eval(char op,int num1, int num2)
{
    int result;

    switch(op)
    {
        case '+' :
            result = num1 + num2;
            break;
        case '-' :
            result=num1 - num2;
            break;
        case '*' :
            result=num1 * num2;
            break;
        case '/' :
            result=num1 / num2;
            break;
        case '%' :
            result=num1 % num2;
            break;
        case '^':
        case '$':
            result=pow(num1,num2);
    }
    push(result);
}

int pop()
{
    int x;

    if(top == -1)
        printf("Stack-underflow condition!");
    else
        x = stack[top--];

    return x;
}

int main()
{
    int n1, n2, i = -1;
    top = -1, ans = 0;

    printf("\nEnter the Postfix expression: \t");
    scanf("%s", postfix);

    while(postfix[++i] != '\0')
    {
        if(priorityCheck(postfix[i]))
        {
            n2=pop();
            n1=pop();
            eval(postfix[i],n1,n2);
        }
        else
        {
            ch = postfix[i] - '0';
            push(ch);
        }
    }

    printf("\nEvaluation of Postfix expression is: %d\n", pop());
    return 0;
}
