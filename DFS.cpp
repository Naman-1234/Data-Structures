#include<iostream>
using namespace std;
void dfs(int v,int **adjacency_matrix,int start,int visited[])
{


        visited[start]=1;
        cout<<start<<" ";
        for(int i=1;i<=v;i++)
{
                if(visited[i]==0&&adjacency_matrix[start][i]==1)
{

                dfs(v,adjacency_matrix,i,visited);
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
dfs(v,adjacency_matrix,1,visited);
}
