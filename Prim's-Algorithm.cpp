#include<bits/stdc++.h>
using namespace std;
#define maximum 33333
int get(int weight[],int visited[],int v)
{

   int vertex=-1;
   for(int i=1;i<=v;i++)
   {if(visited[i]==0&&(vertex==-1||weight[i]<weight[vertex]))
   {


       vertex=i;
   }}
    return vertex;
}
int prim(int v,int **arr,int start)
{
    int weight[v+1];
    int visited[v+1];
    memset(visited,0,sizeof(visited));
    memset(weight,maximum,sizeof(weight));
    int parent[v+1];
    parent[1]=-1;
    weight[1]=0;
    int minimum,vertex,i,j,sum=0;
    for(i=1;i<=v;i++)
{
      //Calculating minimum vertex
     int vertex=get(weight,visited,v);
        visited[vertex]=1;
        for(j=1;j<=v;j++)
        {
            if(arr[vertex][j]&&visited[j]==0)
            {

                if(arr[vertex][j]<weight[j])
                    {
                        weight[j]=arr[vertex][j];
                        parent[j]=vertex;
                    }

            }

        }

    }
    
    for(i=1;i<=v;i++)
        sum=sum+weight[i];
        for(i=1;i<=n;i++)
        {
        if(parent[i]<i)
        cout<<parent[i]<<" "<<i<<" "<<weight[i]<<endl;
        else 
        cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;}
    return sum;

}
int main()
{
    int v,e,i,j,a,b,weight;
    cout<<"Enter vertices and Edges: ";
    cin>>v>>e;
    int **arr=new int*[v+1];
    for(i=0;i<=v;i++)
        arr[i]=new int[v+1];
        for(i=0;i<=v;i++)
{
    for(j=0;j<=v;j++)
        arr[i][j]=0;
}
    for(i=0;i<e;i++)
    {

        cout<<"enter vertex no b/w which edge have to be inserted and weight";
        cin>>a>>b>>weight;
        arr[a][b]=arr[b][a]=weight;
    }
    cout<<prim(v,arr,1);

}
