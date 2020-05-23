#include <stdio.h>
#include<stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
}*head=NULL;
int count()
{
    int countn=0;struct node *p=head;while(p){countn++;p=p->next;}return countn;}
struct node *create(int key)
{
    struct node *t=(struct node *)malloc(sizeof(struct node));
    t->data=key;
    t->prev=t->next=NULL;
    return t;
}
void insert(int pos,int key)
{
    if(pos<0||pos>count())
    return ;
    struct node *t=create(key);
    if(pos==0)
    {
        if(head==NULL)
        head=t;
        else 
        {
            t->next=head;
            head->prev=t;
            head=t;
        }
        return ;
    }
    else 
    {
        int count1=0;
        struct node *p=head;
        while(count1!=pos-1)
        {
            count1++;
            p=p->next;
        }
        t->next=p->next;
        if(p->next)
        p->next->prev=t;
       t->prev=p;
       p->next=t;
    }}
void display()
{
        struct node *p=head;while(p){printf("%d ",p->data);p=p->next;}printf("\n");}
void Delete(int pos)
{
            if(pos<=0||pos>count())
            {printf("Invalid index\n");return ;}
            if(pos==1)
            {
               struct node *temp=head;
               head=head->next;
               if(head)
               head->prev=NULL;
               free(temp);
            }
            else if(pos>1)
            {
                int count=0;
                struct node *p=head;
                while(count!=pos-1)
                {
                    count++;
                    p=p->next;
                }
p->prev->next=p->next;
if(p->next)
p->next->prev=p->prev;
free(p);
            }
        }
        void reverse()
        {
            struct node *p=head,*temp,*r;
            while(p!=NULL)
            {
                r=p;
                temp=p->next;
                p->next=p->prev;
                p->prev=temp;
                p=p->prev;
            }
            head=r;
        }
int main()
{
    int x,y,z;
while(1)
    {
        printf("press 1 for insert\n 2 for delete\n 3 for display\n 4 for reverse\n 5 for exit\n");
printf("\nenter choice");
scanf("%d",&x);
switch(x)
{
case 1:
    printf("\nenter position and value");
     scanf("%d %d",&y,&z);
     printf("\n");
     insert(y,z);
     break;
case 2:
      printf("\nenter position ");
      scanf("%d",&y);
     Delete(y);
     printf("\n");
        break;
case 3:
    display();
    break;
case 4:
    exit(0);
    break;
}}


    
    return 0;}



