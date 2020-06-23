#include <stdio.h>
#include<stdlib.h>

struct stack
{
    int size;
    int *arr;
    int top;

};
    void creation(struct stack *st)
    {
        printf("enter size");
        scanf("%d",&st->size);
        st->arr=(int *)malloc(sizeof(int )*st->size);
        st->top=-1;
    }
    void doublea(struct stack *st)
    {
        st->size*=2;
        st->arr=realloc(st->arr,st->size*sizeof(int));
    }
    void push(struct stack *st,int x)
    {
        if(st->top==st->size-1)
        {int x=0;printf("full\n but if u want we could reallocate memory if yes press 9 otherwise press 0");if(x==9)doublea(st);else exit(0);}
        st->arr[++st->top]=x;
    }
    int pop(struct stack *st){if(st->top==-1) return -1; else {int x=st->arr[st->top]; st->top--;return x;}}
    int peek(struct stack *st,int pos)
    {
        if(st->top-pos+1<0)
        return -1;
        else return st->arr[st->top-pos+1];
    }
    int isempty(struct stack *st)
    {
        return st->top==-1?1:0;
    }
    int top(struct stack *st){if(st->top==-1)return -1;else return st->arr[st->top];}
    void display(struct stack obj)
    {
int x=0;
while(x<=obj.top){printf("%d ",obj.arr[x]);x++;}
    }
    int main()
{
   struct stack obj;
   creation(&obj);
   int x,y;
while(1)
    {
        printf("press 1 for push \n 2 for pop\n 3 for display\n 4 for exit");
printf("\nenter choice");
scanf("%d",&x);
switch(x)
{
case 1:
    printf("\nenter value to be pushed");
     scanf("%d",&y);
     push(&obj,y);
     break;
case 2:
    printf("%d",pop(&obj));
    break;
case 3:
    display(obj);
    break;
case 4:
    exit(0);
    break;
}

    }return 0;}
