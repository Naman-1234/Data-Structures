/*Basically u have to call for heapigy method for each non leaf node 
Characterstic of a leaf node is taken by complete binary tree which is that leaf nodes are from floor(n/2)+1 to n
so everytime u call for heapify u take the index called to be largest then we try to check if either of its left and right element 
is greater than it, and in case that they are then update the value of largest to that index
Then we check if largest has been updated that simply mean that the value have been swapped then we call heapify for that updatedn index 
to ensure that it is largest  than all the elements below.



*/

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

