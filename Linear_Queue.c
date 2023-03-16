
// Implementing Linear Queue Operations

#include <stdio.h>
#include <stdlib.h>

#define Max 4

void Enqueue(int [Max],int ,int *);
void Dequeue(int *,int *);
void Display(int [],int *,int *);

int main()
{
	int queue[Max],front=-1,rear=-1,num;
	printf("\nPress 1 to enqeue\nPress 2 to deqeue\nPress 3 to display\nPress 4 to exit");
	printf("\n--------------------------");

	while(1)
	{
		int choice=0;
		printf("\nEnter choice : ");
		scanf("%d",&choice);
		if(choice == 1)
		{
			printf("\nInsert : ");
			scanf("%d",&num);
			Enqueue(queue,num,&rear);
		}
		if(choice == 2)
		{
			Dequeue(&rear,&front);
            printf("\nDeleted");
		}
		if(choice == 3)
		{
			Display(queue,&front,&rear);
		}
		if(choice == 4)
		{
			exit(0);
		}
	}
	
	return 0;
}

void Enqueue(int queue[Max],int item,int *rear)
{
	if(*rear==(Max-1))
	{
		printf("\nQUEUE FULL");
	}
	else
	{
		queue[++*rear]=item;
	}
}

void Dequeue(int *rear,int *front)
{
	if(*rear==*front)
	{
		printf("\nQUEUE EMPTY");
	}
	else
	{
		++*front;
	}
}

void Display(int queue[Max],int *front,int *rear)
{
	printf("\nThe queue is : ");
	for(int j=*front+1;j<=*rear;j++)
	{
		printf("%d  ",queue[j]);
	}
}