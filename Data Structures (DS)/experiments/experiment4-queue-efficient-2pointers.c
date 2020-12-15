#include<stdio.h>
#include<unistd.h>

#define MAX 5
int queue[MAX];
int front, rear;

int options()
{
    int choice = -1;
    printf("\n\nEnter the operation number you want to perform with this Queue: \n");
    printf("0. Enqueue (Insert)\n");
    printf("1. Dequeue (Delete)\n");
    printf("2. Traverse (Display)\n");
    printf("3. Peek (Front)\n");
    printf("4. Destroy (Reinitialize)\n");
    printf("5. Exit\n");
    printf("Enter a number from [0] to [5], inclusive: \t");
    scanf("%d", &choice);
    return choice;
}

void initialize()
{
    front = rear = 0;
}

int isEmpty()
{
    if(front == rear) {
        printf("\n** The Queue is empty - Underflow Condition. **");
        return 1;
    }
    return 0;
}

int isFull()
{
    if(rear == MAX){
        printf("\n** The Queue is full - Overflow Condition. **");
        return 1;
    }
    return 0;
}

void enqueue()
{
    if(!isFull())
    {
        int n;
        printf("\nEnter a element to enqueue:   ");
        scanf("%d", &n);
        queue[rear++] = n;
        printf("\nThe element %d is successfully inserted!", n);
    }
}

void dequeue()
{
    if(!isEmpty())
    {
        // EFFICIENT METHOD;
        printf("\nThe element %d is successfully deleted!", queue[front]);
        if(front == MAX && rear == MAX)
                initialize();
        else
            front++;
    }
}

void traverse()
{
    if(!isEmpty())
    {
        printf("\nMAX SIZE :  %d", MAX);
        printf("\nFRONT    :  %d", front);
        printf("\nREAR     :  %d", rear);

        printf("\nThe elements of the queue are: \n");
        for(int i = front ; i < rear; i++)
            printf(" %d  <-", queue[i]);
        printf("  NULL\n");
    }
}

void peek()
{
    if(!isEmpty())
        printf("\nQueue's front element is: %d", queue[front]);
}

void destroy()
{
    initialize();
    printf("\nThe queue is successfully reinitialized!");
}

int main()
{
    // welcome message;
    printf("\nWELCOME TO THE **EFFICIENT** QUEUE MANIPULATION CENTER!\n");
    initialize();
    while(1)
    {
        switch(options())
        {
        case 0:
            enqueue();
            break;
        case 1:
            dequeue();
            break;
        case 2:
            traverse();
            break;
        case 3:
            peek();
            break;
        case 4:
            destroy();
            break;
        case 5:
            exit(0);
        default:
            printf("\nINVALID OPTION.");
        }
    }

    return 0;
}
