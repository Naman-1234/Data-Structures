/*Code for Quadratic Probign is also gonna just replace j by j*j wherever u are writing it*/

#include<bits/stdc++.h>
using namespace std;
void linear(int arr[],int n)
{
    int i;
int weight=2*n;
int linear[weight];
memset(linear,0,sizeof(linear));
for(i=0;i<n;i++)
{

    int key=arr[i]%weight;
    int j=0;
   while(linear[(key+j)%weight]!=0)
   j++;
   linear[(key+j)%weight]=arr[i];
}
for(i=0;i<weight;i++)
    cout<<linear[i]<<"   ";
cout<<endl<<endl;
}
int main()
{

int n;
    cout<<"Enter size of Array";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    linear(arr,n);
}

