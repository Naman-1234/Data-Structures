#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
void swap(int *p,int *q)
{

    int temp=*p;
    *p=*q;
    *q=temp;
}
void heapify(int arr[],int n,int i)
{
    int largest=i;
    int l=2*i;
    int r=2*i+1;
    if(l<n&&arr[l]>arr[largest])
        largest=l;
    if(r<n&&arr[r]>arr[largest])
        largest=r;
    if(largest!=i)
    {
        swap(&arr[i],&arr[largest]);
        heapify(arr,n,largest);
    }

}
void display(int arr[],int n)
{
    for(int i=1;i<n;i++)
        printf("%d\n",arr[i]);
}
int main()
{
   int arr[]={0,1,2,3,4,5,6,7};
   int n=8;
   for(int i=n/2;i>=1;i--)
    heapify(arr,n,i);
    display(arr,n);

}

