#include<bits/stdc++.h>
using namespace std;
struct node
{

    int data;
    struct node *left;
    struct node *right;
};
struct queue1
{
    struct node *address;
    struct queue1 *prev;
    struct queue1 *next;
};
struct differentiate
{
    struct queue1 *head;
    struct queue1 *last;
};
void enqueue1(struct differentiate *q,struct node *temp)
{
    struct queue1 *temp_node_in_queue1=(struct queue1 *)malloc(sizeof(struct queue1));
    temp_node_in_queue1->address=temp;
    temp_node_in_queue1->prev=temp_node_in_queue1->next=NULL;
    if(!q->head)
        q->head=q->last=temp_node_in_queue1;
    else{
        q->last->next=temp_node_in_queue1;
        temp_node_in_queue1->prev=q->last;
        q->last=temp_node_in_queue1;
    }
}
struct node *dequeue1(struct differentiate *q)
{
    struct node *temp;
    if(!q->head)
    temp=NULL;
    else
    {
       temp=q->head->address;
        q->head=q->head->next;
    }
    return temp;
}
int isempty(struct differentiate *q)
{
    return q->head==NULL?1:0;
}
void create(struct differentiate *q,struct differentiate *display_node)
{
    int data;
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->left=temp->right=NULL;
    cout<<"Enter Root data";
    cin>>temp->data;
    enqueue1(q,temp);
    while(!isempty(q))
    {
        cout<<"Do u want to enter left Node If not enter value=-1     :";
        cin>>data;cout<<endl;
        enqueue1(display_node,q->head->address);
        struct node *parent=dequeue1(q);
        if(data!=-1)
        {
            struct node *left_node=(struct node *)malloc(sizeof(struct node));
            left_node->left=left_node->right=NULL;
            left_node->data=data;
            enqueue1(q,left_node);


        }
        cout<<"Do u want to enter Right Node If not enter value=-1    :";
        cin>>data;
        cout<<endl;
        if(data!=-1)
        {
            struct node *right_node=(struct node *)malloc(sizeof(struct node));
            right_node->left=right_node->right=NULL;
            right_node->data=data;
            enqueue1(q,right_node);

        }
    }
}
void display(struct differentiate *q)
{
    cout<<endl<<endl<<endl;
   while(!isempty(q))
   {
       cout<<q->head->address->data<<"  ";
       dequeue1(q);
   }
}
int main()
{
   struct differentiate *q=(struct differentiate *)malloc(sizeof(struct differentiate));
   q->head=q->last=NULL;
     struct differentiate *p=(struct differentiate *)malloc(sizeof(struct differentiate));
   p->head=p->last=NULL;
   create(q,p);
display(p);
}
