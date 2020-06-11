#include <stdio.h>
#include<stdlib.h>
void swap(int *p,int *q)
{
    int temp=*p;
    *p=*q;
    *q=temp;
}
void maxheap(int arr[],int index)
{
 int i,no;
 i=index;
no=arr[index];
 while(i>1 && no>arr[i/2])
 {
 arr[i]=arr[i/2];
 i=i/2;
 }
 arr[i]=no;
}
void minheap(int arr[],int index)
{
 int i,no;
 i=index;
no=arr[index];
 while(i>1 && no<arr[i/2])
 {
 arr[i]=arr[i/2];
 i=i/2;
 }
 arr[i]=no;
}
void Delete_maxheap(int arr[],int index)
{
 int i,j,x,temp;
 x=arr[1];
 temp=arr[index];
 arr[1]=arr[index];
 arr[index]=x;
 i=1;
 j=i*2;
 while(j<=index-1)
 {
 if(j<index-1 && arr[j+1]>arr[j])
 j=j+1;
 if(arr[i]<arr[j])
 {
 swap(&arr[i],&arr[j]);
 i=j;
 j=2*j;
 }
 else
 break;
 }
arr[index]=x;
}
void heap_sort(int *arr,int size)
{

    int i;
    for(i=size-1;i>1;i--)
        Delete_maxheap(arr,i);
        for(i=1;i<size;i++)
            printf("%d ",arr[i]);
}
void display(int *arr,int size)
{
    for(int i=1;i<=size;i++)
    printf("%d ",arr[i]);
    printf("\n\n");
}
int main()
{
    int x,y,size,i,heapno;
    int *arr;

    while(1)
    {
        printf("Enter your choice\npress 1 for insertion of element simultaneously in minheap\npress 2 for insertion of element simultaneously in maxheap\npress 3 for insertion in maxheap or minheap after you enter whole array first\npress 4 for heapsort\npress 5 for exit   ");
        scanf("%d",&x);
        switch(x)
        {
            case 1:
            printf("Enter size of array   ");
            scanf("%d",&size);
            arr=(int *)malloc(sizeof(int)*(size+1));
            arr[0]=0;
            for(int i=1;i<=size;i++)
            {
                printf("Enter %d element\n",i);
                scanf("%d",&arr[i]);
                minheap(arr,i);
            }
            display(arr,size);
            break;
            case 2:
            printf("Enter size of array   ");
            scanf("%d",&size);
           arr=(int *)malloc(sizeof(int)*(size+1));
            for( i=1;i<=size;i++)
            {
                printf("Enter %d element\n",i);
                scanf("%d",&arr[i]);
               maxheap(arr,i);
            }
            display(arr,size);
            break;
            case 3:
            printf("Enter size of array   ");
            scanf("%d",&size);
            arr=(int *)malloc(sizeof(int)*(size+1));
            arr[0]=0;
            for( i=1;i<=size;i++)
            scanf("%d",&arr[i]);
            printf("For inserting in minheap press 1\nfor maxheap press 2  ");
            scanf("%d",&heapno);
            if(heapno==1)
            {
                for(i=1;i<=size;i++)
                minheap(arr,i);
            }
            else
            {
            for(i=1;i<=size;i++)
                maxheap(arr,i);
            }
            display(arr,size);
            break;
            case 4:
                printf("Enter size of array   ");
            scanf("%d",&size);
            arr=(int *)malloc(sizeof(int)*(size+1));
            arr[0]=0;
            for(int i=1;i<=size;i++)
            scanf("%d",&arr[i]);
               for(i=size;i>1;i--)
                Delete_maxheap(arr,i);
               display(arr,size);
               break;
            case 5:
                exit(0);

        }
    }
return 0;
}
