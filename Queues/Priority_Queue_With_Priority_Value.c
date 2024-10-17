
// Implementing Priority Queue with Priority Values

#include <stdio.h>
#include <stdlib.h>

#define Max 5

int Value_Q[Max], Priority_Q[Max], front = -1, rear = -1;

void Insert(int ,int );
void Delete();
void Display();

void main()
{
    int p,v,n;

    printf("\n1 - Insert");
    printf("\n2 - Delete");
    printf("\n3 - Display");
    printf("\n4 - Exit");

    while (1)
    {
        printf("\nEnter your choice : ");    
        scanf("%d", &n);
 
        switch (n)
        {
            case 1: printf("\nEnter value to be inserted : ");
                    scanf("%d",&v);
                    printf("\nEnter priority of value : ");
                    scanf("%d",&p);
                    Insert(v,p);
                    break;

            case 2: Delete();
                    break;

            case 3: Display();
                    break;

            case 4: exit(0);

            default: printf("\nChoice is incorrect, enter a correct choice");
        }
    }
}

void Insert(int v,int p)
{
    int temp;
    if(rear == Max-1)
    {
        printf("OVERFLOW");
    }
    else if(front == rear)
    {
        rear++;
        Value_Q[rear] = v;
        Priority_Q[rear] = p;
    }
    else if(Priority_Q[rear] >= p)
    {
        rear++;
        Priority_Q[rear] = p;
        Value_Q[rear] = v;
    }
    else
    {
        temp = rear;
        rear++;
        while(Priority_Q[temp] <= p && temp >= 0)
        {
            Priority_Q[temp+1] = Priority_Q[temp];
            Value_Q[temp+1] = Value_Q[temp];
            temp--;
        }
        Priority_Q[temp+1] = p;
        Value_Q[temp+1] = v;
    }
}

void Delete()
{
    if(front == rear)
    {
        printf("UNDERFLOW");
    }
    else
    {
        front++;
    }
}

void Display()
{
    int i;
    for(i = front+1; i <= rear ; i++)
    {
        printf("%d ",Value_Q[i]);
    }
}