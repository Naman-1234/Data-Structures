#include<bits/stdc++.h>
using namespace std;
#define m -214824
struct node
{
    int data;
    struct node *next;
}*head=NULL,*last=NULL;
int count_(struct node *p)
{
    if(!p)
        return 0;
    else return 1+count_(p->next);
}
struct node *create(int data)
{
 struct node *temp=(struct node *)malloc(sizeof(struct node));
 temp->data=data;
 temp->next=NULL;
 return temp;
}
void insert1(int data,int pos)
{
    struct node *temp=create(data);
    if(pos<0||pos>count_(head))
    {
        cout<<"iv";
        return ;
    }
    if(pos==0)
    {
        if(head==NULL)
            head=temp;
        else
        {
            temp->next=head;
            head=temp;
        }
    }
    else
    {

   int reach=0;
struct node *temp1=head;
while(reach!=pos-1)
    {
        reach++;
        temp1=temp1->next;
    }
temp->next=temp1->next;
temp1->next=temp;

    }
}
void display(struct node *p)
{
    if(p)
    {
        cout<<p->data<<" ";
        display(p->next);
    }
}
int max1(struct node *p)
{
    if(p==NULL)
        return m;
        else
        {
        int x=max1(p->next);
        if(x>p->data)
            return x;
        else
            return p->data;
}
}
void insertion_last(int data)
{
        struct node *temp=create(data);
    if(head==NULL)
    head=last=temp;
    else
    {

        last->next=temp;
        last=temp;
    }


}
//I am allowing duplicates in below sorted insertion function but if u want u may not
void insertion_in(int data)
{
    struct node *temp=head,*prev=NULL;
    if(head==NULL)
    {
    head=create(data);
    return ;
    }
    if(head->data>data)
    {
        struct node *temp=create(data);
        temp->next=head;
        head=temp;
        return ;
    }
    while(temp&&data>=temp->data)
    {
        prev=temp;
        temp=temp->next;
    }
    struct node *t=create(data);
    t->next=temp;
    prev->next=t;
}
void remove_duplicates()
{
    struct node *p=head;
    while(p->next&&p)
    {
struct node *q=p->next,*prev=p;
while(q)
{
    if(p->data==q->data)
    {
     prev->next=q->next;
     q=q->next;
    }
    else
    {
        prev=q;
        q=q->next;
    }
}
}
}
void reverse_ll()
{
    struct node *prev=NULL,*curr=head,*next=head;
    while(curr)
    {

        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head=prev;
}
/*Reverse sunte hi ek baat to yaad aa gyi hogi ki backtracking me ulta hi order hota h*/
void rreverse(struct node *p,struct node *q)
{
    if(q)
    {
        rreverse(q,q->next);
        q->next=p;
    }else
    head=p;

}
/*Imp point to note is that in concatentaion since two linked lists are required u will have to form a another structure \
which only conatins heads OR u can start passing heads as a parameter to function of insertion or deletion*/
void concatenation(struct node *head1,struct node *head2)
{

    struct node *temp=head1;
    while(temp->next)
        temp=temp->next;
    temp->next=head2;
    head2=NULL;
}
void merging()
{
struct node *last=NULL,*head=NULL;
struct node *temp1=head1,*temp2=head2;
while(temp1&&temp2)
{
   if(temp1->data<temp2->data)
    {
        if(last==NULL)
        {
            last=head=temp1;
            last->next=NULL;
        }
        else
        {
            last->next=temp1;
            last=temp1;
            last->next=NULL;
        }
        temp1=temp1->next;
    }
    else
    {
       if(last==NULL){
            last=head=temp2;last->next=NULL;
        }
        else
        {
            last->next=temp2;
            last=temp2;
            last->next=NULL;
        }
         temp2=temp2->next;
    }

}
if(head1)
    last->next=head1;
else
    last->next=head2;
}
bool isloop()
{

    struct node *slow=head;
    struct node *fast=head;
    //In this we have used do loop and it is quite necessary else our condition will go false initially and it will never enter in loop
    do
    {
        slow=slow->next;
        fast=fast->next;
        if(fast)
            fast=fast->next;
        else
            return false;
    }while(fast!=slow&&fast&&loop);
    if(fast==slow)
        return true;
    return false;
}
int main()
{

    int x,y,z;
    while(1)
    {

        cout<<"enter your task\n1 for insert\n2for display\n3 for max\n4for insertion at last\n5 for sorted insert\n6for duplicates removal\n7 for reversing\n8 for recursive reverse\n9 for exit";
        cin>>x;
        switch(x)
        {

            case 1:
            cout<<"You have choosen insertion\nEnter position";
            cin>>z;
            cout<<"\n"<<"Now enter value";
            cin>>y;
            cout<<endl;
            insert1(y,z);
            break;
            case 2:
                cout<<endl<<endl<<endl;
            display(head);
            cout<<endl<<endl<<endl;
            break;
            case 3:
            cout<<max1(head);
            case 4:
            int y;
            cin>>y;
            insertion_last(y);
            break;
            case 5:
                cout<<"Enter  data to insert";
                cin>>y;
                insertion_in(y);
                cout<<endl;
                break;
            case 6:
               remove_duplicates();
               break;
            case 7:
                reverse_ll();
                break;
            case 8:
                rreverse(NULL,head);
                break;
            case 9:
                exit(0);

        }
    }
}
