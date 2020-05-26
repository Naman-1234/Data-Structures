#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
struct node *create(int data)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    return temp;
};
void make(int original[],int n)
{
  struct node* arr[10];
  int i;
  for(i=0;i<10;i++)
        arr[i]=NULL;
  for(i=0;i<n;i++)
  {
      int index=original[i]%10;
      struct node *put=create(original[i]);
      struct node *temp=arr[index];
      if(arr[index]==NULL)
        arr[index]=put;
      else {
      while(temp->next)
        temp=temp->next;
      temp->next=put;
  }}
  for(i=0;i<10;i++)
  {

      struct node *temp=arr[i];
      cout<<i<<"-->"<<" ";
      while(temp)
      {
        cout<<temp->data<<" ";
        temp=temp->next;
  }
  cout<<endl;
}}

int main()
{
    int n,i;
    cout<<"Enter size of array";
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)
    cin>>arr[i];
    make(arr,n);
}
