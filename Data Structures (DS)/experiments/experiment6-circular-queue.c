#include<stdio.h>
#include<unistd.h>

#define MAX 5
int queue[MAX];
int front, rear;

int options()
{
    int choice = -1;
    printf("\n\nEnter the operation number you want to perform with this Circular Queue: \n");
    printf("0. Enqueue (Insert)\n");
    printf("1. Dequeue (Delete)\n");
    printf("2. Traverse (Display)\n");
    printf("3. Peek\n");
    printf("4. Destroy (Reinitialize)\n");
    printf("5. Exit\n");
    printf("Enter a number from [0] to [5], inclusive: \t");
    scanf("%d", &choice);
    return choice;
}

void initialize()
{
    front = rear = -1;
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
    if((rear + 1) % MAX == front){
        printf("\n** The Queue is in full - Overflow Condition. **");
        return 1;
    }
    return 0;
}

void enqueue()
{
    if(front == -1 && rear == -1)
        front = rear = 0;

    if(!isFull())
    {
        int n;
        printf("\nEnter a element to enqueue:   ");
        scanf("%d", &n);
        queue[rear] = n;
        rear = (rear + 1) % MAX;
        printf("\nThe element %d is successfully inserted!", n);
    }
}

void dequeue()
{
    if(!isEmpty())
    {
        printf("\nThe element %d is successfully deleted!", queue[front]);
        if(front == rear)
            initialize();
        else
            front = (front + 1) % MAX;
    }
}

void traverse()
{
    int i;
    if(!isEmpty())
    {
        printf("\nMAX SIZE :  %d", MAX);
        printf("\nFRONT    :  %d", front);
        printf("\nREAR     :  %d", rear);
        printf("\nThe elements of the queue are: \n");
        for(i = front ; i != rear; i = ((i + 1) % MAX)) {
            printf(" %d  ", queue[i]);
        }
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
    printf("\nWELCOME TO THE CIRCULAR QUEUE MANIPULATION CENTER!\n");
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
