#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* link;
};
void createlistcircular(int n,struct node* root)
{
    struct node* temp;
    temp=root;
    for(int i=1;i<n;i++)
    {
        struct node* newnode;
        newnode=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&newnode->data);
        temp->link=newnode;
        newnode->link=NULL;
        temp=temp->link;
    }
    // temp->link=NULL;
    temp->link=root;
}
void createlistlinked(int n,struct node* root)
{
    int i;
    struct node* temp;
    temp=root;
    if(temp==NULL)
    {
        printf("Could not create a list");
        exit(0);
    }
    for(i=2;i<=n;i++)
    {
       struct node* newnode;
       newnode=(struct node*)malloc(sizeof(struct node));
       printf("Enter the data for %d node : ",i);
       scanf("%d",&newnode->data);
       temp->link=newnode;
       newnode->link=NULL;
       temp=temp->link;
    }
    temp->link=NULL;
}
int check(struct node* root)
{
    struct node* p1,*p2;
    p1=root;p2=root;
    while(p1!=NULL && p2!=NULL)
    {
        p1=p1->link;
        p2=p2->link;
        // if(p2==NULL)
        // {
        //     return 1;
        // }
        if(p2!=NULL)
        {
            p2=p2->link;
        }
        if(p1==p2)
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    struct node *root;
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    root=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&root->data);
    root->link=NULL;
    createlistcircular(n,root);
    // createlistlinked(n,root);
    if(check(root)==1)
    {
        printf("Circular linked list");
    }
    else
    {
        printf("Singly linked list");
    }
    return 0;
}