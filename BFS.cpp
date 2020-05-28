#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
}*head=NULL,*last=NULL;
struct node *create(int data)
{

    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    return temp;
};
void enqueue(int data)
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
int dequeue()
{
    int x;
    if(head==NULL)
    return 0;
    else
    {

        x=head->data;
        struct node *temp=head;
        head=head->next;
        free(temp);
    }
    return x;
}
int isempty()
{
    return head==NULL?1:0;
}
void bfs(int v,int** adjacency_matrix,int start,int visited[])
{
    visited[start]=1;
    enqueue(start);
    cout<<start<<" ";
    while(!isempty())
    {
        int x=dequeue();
    for(int i=1;i<=v;i++)
    {

        if(adjacency_matrix[x][i]==1&&visited[i]==0)
        {

            cout<<i<<" ";
            visited[i]=1;
            enqueue(i);
        }
    }

}
}
int main()
{
int v,e,i,j,a,b;
cout<<"Enter number of vertices and edges";
cin>>v>>e;
cout<<endl;
int **adjacency_matrix=new int*[v+1];
for(i=0;i<=v;i++)
    adjacency_matrix[i]=new int[v+1];
for(i=0;i<=v;i++)
        for(j=0;j<=v;j++)
        adjacency_matrix[i][j]=0;
for(i=0;i<e;i++)
   {
cout<<"Enter edges";
cin>>a>>b;
adjacency_matrix[a][b]=adjacency_matrix[b][a]=1;
}
int visited[v+1];
for(i=0;i<=v;i++)
    visited[i]=0;
bfs(v,adjacency_matrix,2,visited);
}
