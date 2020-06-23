// Below is a menu driven program for stack push and pop


#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;
void push(int x)
{
struct node *temp=(struct node *)malloc(sizeof(struct node ));
temp->data=x;
temp->next=NULL;
if(!temp)
printf("full\n");
else
{
    if(head==NULL)
head=temp;
    else
    {temp->next=head;
    head=temp;
    }
}
}
int pop()
{
    int x=head->data;
    struct node *temp=head;
    head=head->next;
    free(temp);
    return x;
}
int peek(int pos){struct node *temp=head;int count=0;while(count!=pos){count++;temp=temp->next;}}
int isempty(){
    return head==NULL;
}
void display()
{
    struct node *temp=head;while(temp!=NULL){printf("%d ",temp->data);temp=temp->next;}
}
int main()
{
     int x,y;
while(1)
    {
        printf("press 1 for push \n 2 for pop\n 3 for display\n 4 for exit");
printf("\nenter choice");
scanf("%d",&x);
switch(x)
{
case 1:
    printf("\nenter value to be pushed");
     scanf("%d",&y);
     push(y);
     break;
case 2:
    printf("%d",pop());
    break;
case 3:
    display();
    break;
case 4:
    exit(0);
    break;
}

    }return 0;}


