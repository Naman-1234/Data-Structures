#include<stdio.h>
#include<stdlib.h>
struct graph
{
    int v;
    int e;
    int **arr;
};
struct node
{
    int vertex;
    struct node *next;
};
struct list
{
    int v;
    int e;
    struct node *arr;
};
void display_adjacency_matrix(int **arr,int v)
{
    int i,j;
    for(i=1;i<=v;i++)
    {if(i==1){printf("  V");printf("%d",i);}else{printf("  V");printf("%d",i);}}printf("\n");
    printf("-------------------------------\n");
    for(i=1;i<=v;i++)
    {
        printf("V");printf("%d",i);printf(" | ");
        for(j=1;j<=v;j++)
        printf("%d  ",arr[i][j]);
        printf("|\n");
    }
     printf("-------------------------------\n");
}
void adjacency_matrix(int z)
{
    int i,j,count=0,choice,x,y;
    struct graph *t=(struct graph *)malloc(sizeof(struct graph));
    printf("enter number of vertices ");
    scanf("%d",&t->v);
    printf("\n");
    t->arr=(int **)malloc(sizeof(int)*(t->v+1)*(t->v+1));
    for(i=0;i<=t->v;i++)
    t->arr[i]=(int *)malloc(sizeof(int)*t->v);
    for(i=0;i<=t->v;i++)
        for(j=0;j<=t->v;j++)
        t->arr[i][j]=0;
   while(1&&count<(((t->v*t->v)-t->v)/2+t->v))
    {
        printf("Enter your choice\npress 1 if u want to add edge\npress 2 if you do not want to insert more\n");
        scanf("%d",&choice);
        if(choice==1)
                {printf("Enter Vertices between which u want to insert");
                scanf("%d%d",&x,&y);
                printf("\n");
                t->arr[x][y]=1;
                if(z==2)t->arr[y][x]=1;
                count++;
                }
            if(choice==2){
            int choice2;
            printf("Do u want to display it\n1 for yes\n");
            scanf("%d",&choice2);
             printf("\n");
            if(choice2==1)
            display_adjacency_matrix(t->arr,t->v);
                break;}

    }
}
void display_incidence_matrix(int **arr,int v,int e)
{
    int i,j;
    for(i=1;i<=e;i++)
    {if(i==1){printf(" V");printf("%d",i);}else{printf(" V");printf("%d",i);}}printf("\n");
    printf("-------------------------------\n");
    for(i=1;i<=v;i++)
    {
        printf("V");printf("%d",i);printf(" | ");
        for(j=1;j<=e;j++)
        printf("%d ",arr[i][j]);
        printf("|\n");
    }
     printf("-------------------------------\n");
}
void incidence_matrix(int z)
{
      int i,j,count=0,choice,x,y,choice2;
    struct graph *t=(struct graph *)malloc(sizeof(struct graph));
    printf("enter number of vertices and number of edges  ");
    scanf("%d %d",&t->v,&t->e);
    printf("\n");
    t->arr=(int **)malloc(sizeof(int)*(t->v+1)*(t->e+1));
    for(i=0;i<=t->v;i++)
    t->arr[i]=(int *)malloc(sizeof(int)*t->e);
    for(i=0;i<=t->v;i++)
        for(j=0;j<=t->e;j++)
        t->arr[i][j]=0;
        if(z==1)
        {
            for(int k=1;k<=t->e;k++)
            {
                printf("Enter vertices between which edge would be there  ");
                scanf("%d %d",&i,&j);
                t->arr[i][k]=-1;
                t->arr[j][k]=1;
                printf("\n");
            }
        }
        else if (z==2)
        {
            for(int k=1;k<=t->e;k++)
            {
                printf("Enter vertices between which edge would be there  ");
                scanf("%d %d",&i,&j);
                t->arr[i][k]=-1;
                t->arr[j][k]=1;
                printf("\n");
            }
        }
        printf("Do u want to display\npress 1 for yes\n");
        scanf("%d",&choice2);
         printf("\n");
        if(choice2==1)
        display_incidence_matrix(t->arr,t->v,t->e);
}
void display_adjacency_list(struct node *arr,int v,int e)
{
    int i;
    for(i=0;i<v;i++)
    {
        struct node *temp=arr+i;
        do
        {
            printf("%d->",temp->vertex);
            temp=temp->next;
        }while(temp!=arr+i);
        printf("\n");
    }
}
void adjacency_list(int z)
{
    struct list *p=(struct list *)malloc(sizeof(struct list));
    int x,y,i;
printf("Enter Number of vertices and edges  ");
scanf("%d %d",&p->v,&p->e);
printf("\n");
p->arr=(struct node *)malloc(p->v*sizeof(struct node));
for(i=0;i<p->v;i++)
    p->arr[i].vertex=i+1;
for(i=0;i<p->v;i++)
p->arr[i].next=p->arr+i;
for(i=0;i<p->e;i++)
{
    printf("Enter Vertices between which edge would be there ");
    scanf("%d %d",&x,&y);
     printf("\n");
    struct node *temp=(struct node *)malloc(sizeof(struct node ));
    temp->vertex=y;
    temp->next=p->arr+x-1;
    struct node *temp1=p->arr+x-1;
    while(temp1->next!=p->arr+x-1)
    temp1=temp1->next;
    temp1->next=temp;
    if(z==2)
    {
        struct node *temp2=(struct node *)malloc(sizeof(struct node));
        temp2->next=p->arr+y-1;
        temp2->vertex=x;
        struct node *temp4=p->arr+y-1;
        while(temp4->next!=p->arr+y-1)
        temp4=temp4->next;
        temp4->next=temp2;
    }

}
printf("Do u want to display Adjacency list\npress 1 for Yes\n");
scanf("%d",&x);
 printf("\n");
if(x==1)
display_adjacency_list(p->arr,p->v,p->e);
}
int main(){
    int x,y;
    while(1)
    {
        printf("Enter your choice\npress1 for Directed graph\n2for Indirected graph\n3for exit\n");
        scanf("%d",&x);
        switch(x)
        {
            case 1:
            printf("Enter your choice for representation of graph\npress 1 for Incidence matrix\n2 for Adjacenecy matrix\n3for Adjacency List\n ");
            scanf("%d",&y);
            switch(y)
            {
                case 1:
                incidence_matrix(x);
                break;
                case 2:
                adjacency_matrix(x);
                break;
                case 3:
                adjacency_list(x);
            }
            break;
            case 2:
             printf("Enter your choice for representation of graph\npress 1 for Incidence matrix\n2 for Adjacenecy matrix\n3for Adjacency List\n ");
            scanf("%d",&y);
            switch(y)
            {
                case 1:
                incidence_matrix(x);
                break;
                case 2:
                adjacency_matrix(x);
                break;
                case 3:
                adjacency_list(x);
            }
            break;
            case 3:
            exit(0);

        }
    }
    return 0;

}

