#include<iostream>
#include<string>
using namespace std;
#define v  6
#define e 7
void join(int s[],int a,int b)
{
    if(s[a]<s[b])
    {

        s[a]=s[a]+s[b];
        s[b]=a;
    }
    else
    {

        s[b]=s[b]+s[a];
        s[a]=b;
    }
}
int find(int set[],int a)
{
    int x=a,temp=0;
 while(set[x]>0)
 {
 x=set[x];
 }
 while(a!=x)
 {
 temp=set[a];
 set[a]=x;
 a=temp;
 }
 return x;
}
void kruskal(int edges[][3],int visited[],int set[])
{
    int answer[v-1][3];
    int i=0,index,j,temp1,temp2;
    while(i<v-1)
    {
        int min=32766;
        for(j=0;j<e;j++)
        {

            if(min>edges[j][2]&&visited[j]==0)
            {

                min=edges[j][2];
                index=j;
                temp1=edges[j][0];
                temp2=edges[j][1];
            }
        }
        if(find(set,temp1)!=find(set,temp2))
        {
            answer[i][0]=temp1;
            answer[i][1]=temp2;
            answer[i][2]=min;
            join(set,find(set,temp1),find(set,temp2));
            i++;
        }
        visited[index]=1;
    }
    for(i=0;i<v-1;i++)
        cout<<answer[i][0]<<" "<<answer[i][1]<<" "<<answer[i][2]<<endl;
}

int main()
{
    int i;
    int edges[e][3]={{1,2,5},{2,3,12},{3,4,18},{4,6,16},{4,5,10},{5,1,11}};
    int visited[e];
    for(i=0;i<e;i++) visited[i]=0;
    int set[v+1];
    for(i=0;i<=v;i++)set[i]=-1;
    kruskal(edges,visited,set);

}
