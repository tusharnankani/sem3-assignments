#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node* next;
    struct node* prv;
    int data;
};

struct node* newNode(int x) //function to allocate memory to our node
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->next=NULL;
    temp->prv=NULL;
    temp->data=x;
    return temp;
}

struct node* insert_beg(struct node* head)
{
    int data;
    printf("Enter data to be inserted: ");
    scanf("%d",&data);
    struct node* temp=newNode(data);
    if(head)
    {
        head->prv=temp;
        temp->next=head;
        return temp;
    }
    else
    {
        return temp;
    }
}
struct node* insert_after(struct node* head)
{
    int data,val;
    printf("Enter the data: ");
    scanf("%d",&data);
    printf("Enter the value after which data has to be inserted: ");
    scanf("%d",&val);
    struct node* temp=newNode(data);
    struct node* ptr=head;
    while(ptr->data!=val)
    {
        ptr=ptr->next;
    }
    if(ptr->next)
    {
        temp->prv=ptr;
        temp->next=ptr->next;
        ptr->next->prv=temp;
        ptr->next=temp;
    }
    else
    {
        temp->prv=ptr;
        ptr->next=temp;
    }
    return head;
}
struct node* delete_beg(struct node* head)
{
    if(head)
    {
        struct node* ptr=head;
        head=head->next;
        head->prv=NULL;
        free(ptr);
        return head;
    }
    else
    {
        printf("UNDERFLOW CONDITION! LIST IS EMPTY CANT DELETE!\n");
        return NULL;
    }
}

struct node* delete_after(struct node* head)
{
    struct node *ptr,*temp;
    int val;
    printf("Enter the value after which the node has to be deleted: ");
    scanf("%d",&val);
    ptr=head;
    while(ptr->data!=val)
        ptr=ptr->next;
    temp=ptr->next;
    if(temp->next)
    {
        ptr->next=temp->next;
        temp->next->prv=ptr;
        free(temp);
        return head;
    }
    else
    {
        ptr->next=NULL;
        free(temp);
        return head;
    }
}
void display(struct node* head)
{
    if(!head)
    {
        printf("List is Empty!\n");
        return;
    }
    printf("Doubly Linked List: ");
    struct node* ptr=head;
    while(ptr)
    {
        printf("%d->",ptr->data);
        ptr=ptr->next;
    }
    printf("NULL\n");
}

int main()
{
    struct node* head=NULL;
    int c=1,choice;
    while(c)
    {
        printf("1.Insert at Beginning\n2.Insert After a given Node\n3.Deletefrom beginning\n4.Delete a node after a given node\n5.Display\n6.Exit\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                head=insert_beg(head);
                break;
            }
            case 2:
            {
                head=insert_after(head);
                break;
            }
            case 3:
            {
                head=delete_beg(head);
                break;
            }
            case 4:
            {
                head=delete_after(head);
                break;
            }
            case 5:
            {
                display(head);
                break;
            }
            case 6:
            {
                c=0;
                break;
            }
        }
        printf("\n");
    }
    return 0;
}
