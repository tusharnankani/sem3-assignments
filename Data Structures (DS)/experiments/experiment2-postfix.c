#include<stdio.h>
#include<stdlib.h>

#define MAX 50

char ch, infix[MAX], postfix[MAX], stack[MAX];

int priorityCheck(char c)
{
    if(c == '$' || c == '^')
        return 3;

    if(c == '*' || c == '/' || c == '%')
        return 2;

    if(c == '+' || c == '-')
        return 1;

    return 0;
}

// debugging stack;
void display(int top)
{
    int i;

    printf("\n %c\t\t\t", ch);

    if (top == -1)
        printf("Empty");

    else
    {
        for(i = top; i >= 0; i--)
            printf("%c", stack[i]);
    }
    printf("\t\t\t%s", postfix);
}


int main()
{
    int top = -1, i = -1, j = 0;

    printf("Enter the Infix Expression:\t");
    scanf("%s", infix);

    printf("\n\nSYMBOL\t\t\tSTACK\t\t\tPOSTFIX\n");

    while(infix[++i] != '\0')
    {
        ch = infix[i];

        // if `ch` is any of the following: + - * / % ^ $;
        if(priorityCheck(ch))
        {
            if(priorityCheck(ch) <= priorityCheck(stack[top]))
            {
                while(priorityCheck(ch) <= priorityCheck(stack[top]))
                    postfix[j++] = stack[top--];
            }

            stack[++top] = ch;
        }

        else if(ch == '(')
        {
            stack[++top] = ch;
        }

        else if(ch == ')')
        {
            while(stack[top] != '(')
            {
                postfix[j++] = stack[top--];
            }
            --top;
        }

        // when it is not an operator, it is a number;
        else
        {
            postfix[j++] = ch;
        }

        // debugging stack;
        display(top);


    }

    while(top != -1)
    {
        postfix[j++] = stack[top--];
    }


    // very important step, tends to be missed;
    postfix[j] = '\0';

    printf("\n\n\nThe Postfix expression is:\t %s\n", postfix);

    return 0;
}
