
// Implementation of Double Ended Queue

#include <stdio.h>
#include <stdlib.h>

#define Max 5

int front = -1, rear = -1, DEQueue[Max];    
   
void Insert_Front(int x)  
{    
    if((front == 0 && rear == Max-1) || (front == rear+1))
    {    
        printf("\nOVERFLOW");
    }    
    else if((front == -1) && (rear == -1))
    {
        front = rear = 0;
        DEQueue[front] = x;
    }
    else if(front == 0)
    {
        front = Max-1;
        DEQueue[front] = x;
    }
    else    
    {    
        front = front-1;    
        DEQueue[front] = x;    
    }    
}    
   
void Insert_Rear(int x)    
{    
    if((front == 0 && rear == Max-1) || (front == rear+1))    
    {    
        printf("\nOVERFLOW");    
    }    
    else if((front == -1) && (rear == -1))    
    {    
        rear = 0;
        DEQueue[rear] = x;
    }    
    else if(rear == Max-1)    
    {
        front = rear = 0;
        DEQueue[rear] = x;    
    }    
    else    
    {    
        rear++;    
        DEQueue[rear] = x;    
    }    
    
}    
   
void Display()    
{    
    int i=front;    
    printf("\nElements in double ended queue are: ");    
        
    while(i != rear)    
    {
        printf("%d ",DEQueue[i]);    
        i = (i+1) % Max;    
    }    
    printf("%d",DEQueue[rear]);    
}    

void Delete_Front()    
{    
    if((front == -1) && (rear == -1))    
    {    
        printf("\nDouble ended queue is empty");    
    }    
    else if(front == rear)    
    {    
        printf("\nThe deleted element is %d", DEQueue[front]);    
        front = -1;    
        rear = -1;    
            
    }    
    else if(front == (Max-1))    
    {    
        printf("\nThe deleted element is %d", DEQueue[front]);    
        front = 0;    
    }    
    else    
    {    
        printf("\nThe deleted element is %d", DEQueue[front]);    
        front = front+1;    
    }    
}    
  
void Delete_Rear()    
{    
    if((front == -1) && (rear == -1))    
    {    
        printf("\nDouble ended queue is empty");    
    }    
    else if(front == rear)    
    {    
        printf("\nThe deleted element is %d", DEQueue[rear]);    
        front = -1;    
        rear = -1;    
            
    }    
     else if(rear == 0)    
     {    
         printf("\nThe deleted element is %d", DEQueue[rear]);    
         rear = Max-1;    
     }    
     else    
     {    
          printf("\nThe deleted element is %d", DEQueue[rear]);    
          rear = rear-1;    
     }    
}    
    
int main()    
{    
    int n, ch;

    printf("\n1 - Insert at Front");
    printf("\n2 - Insert at Rear");
    printf("\n3 - Delete at Front");
    printf("\n4 - Delete at Rear");
    printf("\n5 - Display elements");
    printf("\n6 - Exit");

    while (1)
    {
        printf("\nEnter your choice : ");    
        scanf("%d", &ch);
 
        switch (ch)
        {
            case 1: printf("\nEnter value to be inserted : ");
                    scanf("%d",&n);
                    Insert_Front(n);
                    break;

            case 2: printf("\nEnter value to be inserted : ");
                    scanf("%d",&n);
                    Insert_Rear(n);
                    break;

            case 3: Delete_Front();
                    break;

            case 4: Delete_Rear();
                    break;

            case 5: Display();
                    break;

            case 6: exit(0);

            default: printf("\nChoice is incorrect, enter a correct choice");
        }
    }   
    return 0;    
}  