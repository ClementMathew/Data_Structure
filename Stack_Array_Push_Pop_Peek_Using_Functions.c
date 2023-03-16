
// Stack Operations - Push, Pop, Peek Using Functions

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define Max 5

void push(int [Max],int*,int*);
void pop(int [Max],int*);
void peek(int [Max],int*);
void display(int [],int*);

int main() 
{
    int stack[Max],top=-1,num,insert;
    printf("Note--\nEnter 1 to Push\nEnter 2 to Pop\nEnter 3 to Peek\nEnter 4 to Display\nEnter 5 to Exit");
    printf("\n------------------------");

    while(1)
    {
        printf("\nEnter choice : ");
        scanf("%d",&num);
        if(num == 1)
        {
            printf("\nEnter data : ");
            scanf("%d",&insert);
            push(stack,&insert,&top);
        }
        if(num == 2)
        {
            pop(stack,&top);
        }
        if(num == 3)
        {
            peek(stack,&top);
        }
        if(num == 4)
        {
            display(stack,&top);
        }
        if(num == 5)
        {
            exit(0);
        }
    }
    return 0;
}

void push(int stack[Max],int *insert,int *top)
{
    if(*top+1<Max)
    {
        *top=*top+1;
        stack[*top]=*insert;
    }
    else
    {
        printf("\nOVERFLOW");
    }
}

void pop(int stack[Max],int *top)
{
    if(*top==-1)
    {
        printf("\nUNDERFLOW");
    }
    else
    {
        *top=*top-1;
    }
}

void peek(int stack[Max],int *top)
{
    if(*top!=-1)
    {
        printf("\nThe peek : %d",stack[*top]);
    }
}

void display(int stack[Max],int *top)
{
    printf("\nThe stack elements are : ");
    for(int j=0;j<=*top;j++)
    {
        printf("%d ",stack[j]);
    }
}