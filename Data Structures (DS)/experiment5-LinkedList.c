#include<stdio.h>
#include<unistd.h>
#include <malloc.h>

struct Node {
   int data;
   struct Node *next;
};

struct Node* head = NULL, *temp_node = 0;
int data;

int options()
{
    int choice = -1;
    printf("\n\nEnter the operation number you want to perform with this Circular Queue: \n");
    printf("1. Insert\n");
    // printf("1. Delete\n");
    printf("2. Display\n");
    printf("3. Count\n");
    printf("4. Exit\n");
    printf("Enter a number from [1] to [4], inclusive: \t");
    scanf("%d", &choice);
    return choice;
}

void insert() {
    int new_data;
    printf("\nEnter Element for Insert Linked List : ");
    scanf("%d", &new_data);
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = head;
    head = new_node;
}

void display()
{
    temp_node = head;
    while (temp_node != 0) {
        printf("%d ", temp_node->data);
        temp_node = temp_node->next;
    }
}

void count() {
    int count = 0;
    temp_node = head;
    while (temp_node != 0) {
        count++;
        temp_node = temp_node -> next;
    }
    printf("\nNo Of Items In LinkedList : %d\n", count);
}


int main()
{
    // welcome message;
    printf("\nWELCOME TO THE LINKED LIST MANIPULATION CENTER!\n");
    while(1)
    {
        switch(options())
        {
        case 1:
            insert();
            break;
        case 2:
            display();
            break;
        case 3:
            count();
            break;
        case 4:
            exit(0);
        default:
            printf("\nINVALID OPTION.");
        }
    }
    return 0;
}
