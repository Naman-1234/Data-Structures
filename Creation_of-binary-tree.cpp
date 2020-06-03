/*There are two codes in this first one written by me uses queue and I wanted to see some features that how they work so I have implemented
it little bit difficult but the concept is that U create a linked list of queue in which there is address of nodes of tree and Further since I
want to use it little bit more difficult so I instead of taking head globally I have taken a another structure through which I can distinguish
of which head I am talking about right now.
*/
/*Much Simpler Version At last*/
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












/*Simpler  Version*/
/*But it in c*/



#include<stdio.h>
#include<conio.h>
typedef struct node
{
  int data;
  struct node *left;
  struct node *right;
} node;

node *create()
{
    node *p;
    int x;
    printf("Enter data(-1 for no node):");
    scanf("%d",&x);

    if(x==-1)
	return NULL;

    p=(node*)malloc(sizeof(node));
    p->data=x;
    printf("Enter left child of %d:\n",x);
    p->left=create();
    printf("Enter right child of %d:\n",x);
    p->right=create();
    return p;
}

void preorder(node *t)
{
  if(t!=NULL)
  {
    printf("  %d",t->data);
    preorder(t->left);
    preorder(t->right);
  }
}
void inorder(node *t)
{
  if(t!=NULL)
  {
    inorder(t->left);
    printf("  %d",t->data);
    inorder(t->right);
  }
}
void postorder(node *t)
{
  if(t!=NULL)
  {
    postorder(t->left);
    postorder(t->right);
    printf("  %d",t->data);
  }
}
void main()
{
  node *root;
  clrscr();
  root=create();
  printf("\nThe preorder traversal of tree is: ");
  preorder(root);
  printf("\nThe inorder traversal of tree is: ");
  inorder(root);
  printf("\nThe postorder traversal of tree is: ");
  postorder(root);
  getch();
}

