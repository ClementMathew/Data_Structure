
// Linked List Familiarisation

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

int main()
{
    int n,i;
    printf("Enter the number of nodes : ");
    scanf("%d",&n);
    struct node *head = NULL, *newnode, *temp;
    for(i=0;i<n;i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data : ");
        scanf("%d",&newnode->data);
        newnode->link=0;

        if(head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->link = newnode;
            temp = newnode;
        }
    }
    printf("The data in linked list is : ");

    struct node *temp2;
    if(head == NULL)
    {
        printf("The list is empty.");
    }
    else
    {
        temp2 = head;
        while(temp2!=NULL)
        {
            printf("%d  ",temp2->data);
            temp2 = temp2->link;
        }
    }
    return 0;
}