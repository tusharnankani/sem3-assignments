#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node* next;
    int data;
};
struct node* newNode(int x) //function to allocate memory to our node
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->next=NULL;
    temp->data=x;
    return temp;
}
void display(struct node* head)
{
    struct node*temp=head;
    while(temp)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
int main()
{
int c1=1,choice1,data;
while(c1)
{
printf("1.Stack\n2.Queue\n3.Exit\nEnter your choice: ");
scanf("%d",&choice1);
switch(choice1)
{
case 1:
{
struct node* head=NULL;
int c2=1,choice2;
while(c2)
{

printf("1.Insert\n2.Delete\n3.Display\n4.Peek\n5.Exit\nEnter your choice: ");
scanf("%d",&choice2);
switch(choice2)
{
case 1:
{
printf("Enter data to be inserted: ");
scanf("%d",&data);
if(!head) //if stack is empty create a new head
{
head=newNode(data);
}
else //traverse stack till the end and add a new node
{
struct node* temp=head;
while(temp->next)
{
temp=temp->next;
}
temp->next=newNode(data);
temp=temp->next;
}
printf("%d has been inserted in list\n",data);
break;
}
case 2:
{
if(!head)//UNDERFLOW condition
{
printf("Cannot delete element,Stack is empty,UNDERFLOW!!!!\n");
}
else if(!head->next)//if only 1 element is present make head as NULL,otherwise make list empty
{
printf("%d has been deleted\n",head->data);
struct node* temp=head;
head=NULL;
free(temp);
}
else//traverse till the second last element ans set its next is NULL,and free the last node
{
struct node* cur=head;
struct node* n=cur->next;
while(n->next)
{
cur=n;
n=n->next;
}
cur->next=NULL;
printf("%d has been deleted\n",n->data);
free(n);
}
break;
}
case 3:
{
if(head)
{
printf("Stack : ");
display(head);
}
else
printf("Stack is empty!!!\n");
break;
}
case 4:
{
if(head)
{
struct node* temp=head;
while(temp->next)
{
temp=temp->next;
}
printf("Peek element: %d\n",temp->data);
}
else
printf("Stack is empty!!!\n");
break;
}
case 5:
{
c2=0;
break;
}
default:
{
printf("Invalid choice,Plz try again!!!!\n");
}
}
printf("\n");
}
break;
}
case 2:
{
struct node* head=NULL;
int c2=1,choice2;
while(c2)
{

printf("1.Insert\n2.Delete\n3.Display\n4.Front\n5.Exit\nEnter your choice: ");
scanf("%d",&choice2);
switch(choice2)
{
case 1:
{
printf("Enter data to be inserted: ");
scanf("%d",&data);
if(!head) //if queue is empty create a new head
{
head=newNode(data);
}
else //traverse queue till the end and add a new node
{
struct node* temp=head;
while(temp->next)
{
temp=temp->next;
}
temp->next=newNode(data);
temp=temp->next;
}
printf("%d has been inserted in queue\n",data);
break;
}
case 2:
{
if(head)
{
printf("%d has been deleted from queue\n",head->data);
head=head->next;
}
else
printf("Queue is empty Cannot delete, Underflow!!!!\n");
break;
}
case 3:
{
if(head)
{
printf("Queue : ");
display(head);
}
else
printf("Queue is empty!!!\n");
break;
}
case 4:
{
if(head)
{
printf("Peek element: %d",head->data);
}
else
printf("Queue is empty!!!!\n");
break;
}
case 5:
{
c2=0;
break;
}
default:
{
printf("Invalid choice!!!\n");
}
}
printf("\n");
}
break;
}
case 3:
{
c1=0;
break;
}
default:
{
printf("Invalid choice!!!!\n");
}
}
}
 return 0;
}
