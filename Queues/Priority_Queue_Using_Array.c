
// Implementing Priority Queue

#include <stdio.h>
#include <stdlib.h>

#define Max 5

void Insert_By_Priority(int);
void Delete_By_Priority();
void Check(int);
void Display_PQueue();

int PQueue[Max];
int front=-1, rear=-1;

void main()
{
    int n, ch;

    printf("\n1 - Insert an element into queue");
    printf("\n2 - Delete an element from queue");
    printf("\n3 - Display queue elements");
    printf("\n4 - Exit");

    while (1)
    {
        printf("\nEnter your choice : ");    
        scanf("%d", &ch);
 
        switch (ch)
        {
            case 1: printf("\nEnter value to be inserted : ");
                    scanf("%d",&n);
                    Insert_By_Priority(n);
                    break;

            case 2: Delete_By_Priority();
                    break;

            case 3: Display_PQueue();
                    break;

            case 4: exit(0);

            default: printf("\nChoice is incorrect, enter a correct choice");
        }
    }
}

void Insert_By_Priority(int data)
{
    if (rear >= Max - 1)
    {
        printf("\nQUEUE OVERFLOW");
        return;
    }
    if ((front == -1) && (rear == -1))
    {
        front++;
        rear++;
        PQueue[rear] = data;
        return;
    }    
    else
        Check(data);
    rear++;
}

void Check(int data)
{
    int i,j;
 
    for (i = 0; i <= rear; i++)
    {
        if (data >= PQueue[i])
        {
            for (j = rear + 1; j > i; j--)
            {
                PQueue[j] = PQueue[j - 1];
            }
            PQueue[i] = data;
            return;
        }
    }
    PQueue[i] = data;
}

void Delete_By_Priority()
{
    int i;
 
    if ((front==-1) && (rear==-1))
    {
        printf("\nQUEUE UNDERFLOW");
        return;
    }
    else
    {
        for (i = 0; i <= rear; i++)
        {
            PQueue[i] = PQueue[i + 1];
        }
        rear--;
        if (rear == -1)
        {
            front = -1;
        }
    }
    printf("\nDeleted");
}

void Display_PQueue()
{
    if ((front == -1) && (rear == -1))
    {
        printf("\nQueue is empty");
        return;
    }
 
    for (; front <= rear; front++)
    {
        printf(" %d ", PQueue[front]);
    }
    front = 0;
}