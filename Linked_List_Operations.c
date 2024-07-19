
// Linked list Insertion, Deletion, Display

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *head = NULL, *newnode, *temp;

void Insert_Beginning();
void Insert_End();
void Insert_Position();
void Delete_Beginning();
void Delete_End();
void Delete_Position();
void Display();

int main()
{
    int i,choice;

    printf("\nEnter 1 to insert in beginning.\nEnter 2 to insert in end.\nEnter 3 to insert in position.");
    printf("\nEnter 4 to delete in beginning.\nEnter 5 to delete in end.\nEnter 6 to delete in position.");
    printf("\nEnter 7 to display\nEnter 8 to exit\n-------------------------------------");

    while(1)
    {
        printf("\nEnter Choice : ");
        scanf("%d",&choice);
        if(choice == 1)
        {
            Insert_Beginning();
        }
        if(choice == 2)
        {
            Insert_End();
        }
        if(choice == 3)
        {
            Insert_Position();
        }
        if(choice == 4)
        {
            Delete_Beginning();
        }
        if(choice == 5)
        {
            Delete_End();
        }
        if(choice == 6)
        {
            Delete_Position();
        }
        if(choice == 7)
        {
            Display();
        }
        if(choice == 8)
        {
            exit(0);
        }
    }
    return 0;
}

void Insert_Beginning()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data you want to insert : ");
    scanf("%d",&newnode->data);
    newnode->link = head;
    head = newnode;
}

void Insert_End()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data you want to insert : ");
    scanf("%d",&newnode->data);
    newnode->link=0;
    temp = head;
    while(temp->link != NULL)
    {
        temp = temp->link;
    }
    temp->link = newnode;
}

void Insert_Position()
{
    if(head == NULL)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter the data you want to insert : ");
        scanf("%d",&newnode->data);
        newnode->link = head;
        head = newnode;
    }
    else
    {
        int Pos,i=1;
        printf("\nEntry Position : ");
        scanf("%d",&Pos);
    
        newnode = (struct node *)malloc(sizeof(struct node));
        temp = head;
        while(i<(Pos-1))
        {
            temp = temp->link;
            i++;
        }
        printf("\nEnter data : ");
        scanf("%d",&newnode->data);
        newnode->link = temp->link;
        temp->link = newnode;
    }
}

void Delete_Beginning()
{
    temp = head;
    head = head->link;
    free(temp);
    printf("\nDeleted");
}

void Delete_End()
{
    struct node *temp2;
    temp = head;
    while(temp->link->link != NULL)
    {
        temp = temp->link;
    }
    temp2 = temp->link;
    free(temp2);
    temp->link = NULL;
    printf("Deleted");
}

void Delete_Position()
{
    int Pos,i=1;
    temp = head;
    struct node *temp2;
    
    printf("\nEntry Position : ");
    scanf("%d",&Pos);

    while(i<(Pos-1))
    {
        temp = temp->link;
        i++;
    }
    temp2 = temp->link;
    temp->link = temp->link->link;
    free(temp2);
    printf("Deleted");
}

void Display()
{
    if(head == NULL)
    {
        printf("\nThe list is empty.");
    }
    else
    {
        temp = head;
        while(temp != NULL)
        {
            printf("%d  ",temp->data);
            temp = temp->link;
        }
    }
}