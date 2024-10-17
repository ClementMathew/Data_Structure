
// Implementing Circular Queue

#include <stdio.h>
#include <stdlib.h>

#define Max 5

void Enqueue(int );
void Dequeue();
void Display();

int C_Queue[Max],front=-1,rear=-1,i;

int main()
{
    int n,choice;
    printf("\nPress 1 to Enqueue\nPress 2 to Dequeue\nPress 3 to Display\nPress 4 to Exit\n");

    while(1)
    {
        printf("\nEnter choice : ");
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("\nInsert : ");
            scanf("%d",&n);
            Enqueue(n);
        }
        if(choice==2)
        {
            Dequeue();
        }
        if(choice==3)
        {
            Display();
        }
        if(choice==4)
        {
            exit(0);
        }
    }
    return 0;
}

void Enqueue(int X)
{
    if(front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        C_Queue[rear] = X;
    }
    else if((rear+1) % Max == front)
    {
        printf("\nOverflow");
    }
    else
    {
        rear = (rear+1) % Max;
        C_Queue[rear] = X;
    }
}

void Dequeue()
{
    if(front == -1 && rear == -1)
    {
        printf("Underflow");
    }
    else if(front == rear)
    {
        printf("\nDeleted");
        front = -1;
        rear = -1;
    }
    else
    {
        printf("\nDeleted");
        front = (front+1) % Max;
    }
}

void Display()
{
    if(front == -1 && rear == -1)
    {
        printf("Queue Empty");
    }
    else
    {
        printf("\nThe queue elements are : ");
        for(i=front;i<=rear;i++)
        {
            printf("%d  ",C_Queue[i]);
        }
    } 
}