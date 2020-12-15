#include <stdio.h>
#include <stdlib.h>
struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
}*root=NULL;

struct Node* newNode(int data)
{
    struct Node* temp=(struct Node *)malloc(sizeof(struct Node));
    temp->data=data;
    temp->lchild=temp->rchild=NULL;
    return temp;
}

void Inorder(struct Node *p)
{
    if(p)
    {
        Inorder(p->lchild);
        printf("%d ",p->data);
        Inorder(p->rchild);
    }
}

struct Node * Search(int key)
{
    struct Node *t=root;
    while(t!=NULL)
    {
        if(key==t->data)
            return t;
        else if(key<t->data)
            t=t->lchild;
        else
            t=t->rchild;
    }
    return NULL;
}

struct Node *RInsert(struct Node *p,int key)
{
    struct Node *t=NULL;
    if(p==NULL)
    {
        t=newNode(key);
        return t;
    }
    if(key < p->data)
        p->lchild=RInsert(p->lchild,key);
    else if(key > p->data)
        p->rchild=RInsert(p->rchild,key);
    return p;
}

int Height(struct Node *p)
{
    int x,y;
    if(p==NULL)
        return 0;
    x=Height(p->lchild);
    y=Height(p->rchild);
        return x>y?x+1:y+1;
}

struct Node *InPre(struct Node *p)
{
    while(p && p->rchild!=NULL)
        p=p->rchild;
    return p;
}

struct Node *InSucc(struct Node *p)
{
    while(p && p->lchild!=NULL)
        p=p->lchild;
    return p;
}

struct Node *Delete(struct Node *p,int key)
    {
    struct Node *q;
    if(p==NULL)
        return NULL;
    if(p->lchild==NULL && p->rchild==NULL)
        {
        if(p==root)
        root=NULL;
        free(p);
        return NULL;
        }
    if(key < p->data)
        p->lchild=Delete(p->lchild,key);
    else if(key > p->data)
        p->rchild=Delete(p->rchild,key);
    else
        {
        if(Height(p->lchild)>Height(p->rchild))
        {
            q=InPre(p->lchild);
            p->data=q->data;
            p->lchild=Delete(p->lchild,q->data);
        }
        else
        {
            q=InSucc(p->rchild);
            p->data=q->data;
            p->rchild=Delete(p->rchild,q->data);
        }
    }
    return p;
}

int main()
{
    int c=1,choice,data;
    while(c)
    {
        printf("1. Insert\n2. Delete\n3. Search\n4. Sorted Display\n5. Exit\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                printf("Enter data to be inserted: ");
                scanf("%d",&data);
                root=RInsert(root,data);
                break;
            }
            case 2:
            {
                printf("Enter data to be Deleted: ");
                scanf("%d",&data);
                Delete(root,data);
                break;
            }
            case 3:
            {
                printf("Enter data to be Searched: ");
                scanf("%d",&data);
                struct Node* temp=Search(data);
                if(temp!=NULL)
                    printf("Element %d is found\n",temp->data);
                else
                    printf("Element is not found\n");
                break;
            }
            case 4:
            {
                printf("Sorted list is: ");
                Inorder(root);
                printf("\n");
                break;
            }
            case 5:
            {
                c=0;
                break;
            }
            default:
            {
                printf("Invalid choice!!!!");
            }
        }
        printf("\n");
    }
    return 0;
}