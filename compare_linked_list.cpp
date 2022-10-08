#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node* input()
{
    int data1; struct Node*temp;
    printf("enter -1 to stop\n");
    int i=3;
    struct Node *first=(struct Node*)malloc(sizeof(struct Node));
    printf("enter 1st data\n");
    scanf("%d",&data1);
    first->data=data1;
    first->next=NULL;
    temp=first;
    printf("enter 2nd data\n");
    scanf("%d",&data1);
    while(data1!=-1)
    {
      struct Node* t=(struct Node*)malloc(sizeof(struct Node));
      t->data=data1;
      t->next=NULL;
      temp->next=t;
      temp=t;
        printf("enter %d data\n",i);
      scanf("%d",&data1); 
      i++;
    }
    return first;
    
}
int size(struct Node*p)
{
    if(p==NULL)
    return 0;
    else
    return size(p->next)+1;
}
int compare(struct Node *head1,struct Node *head2)
{
    if(size(head1)!=size(head2))
    return -1;
    int i=0;
    while(head2!=NULL)
    {
    if(head1->data==head2->data)
    {
        i++;
        head1=head1->next;head2=head2->next;
    }
    else
    break;
    }
    return i;
}
int main()
{
   struct Node *head1=input();
   struct Node *head2=input();
   int f=compare(head1,head2);
   if(f==size(head1))
   printf("compatible\n");
   else
   printf("not campatible\n");
}
