
// Polynomial Addition Using Linked List

#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int Coe;
    int Pow;
    struct node * link;
};

void Create_Poly(struct node **);
void Sum_Poly(struct node *,struct node *,struct node **);
void Display_Poly(struct node **);

int main()
{
    struct node * Poly1 = NULL,* Poly2 = NULL,* Sum;
    int p1,p2;
    printf("Enter the degree of first polynomial : ");
    scanf("%d",&p1);
    for(int i=0;i<=p1;i++)
    {
        Create_Poly(&Poly1);
    }
    printf("Enter the degree of second polynomial : ");
    scanf("%d",&p2);
    for(int i=0;i<=p2;i++)
    {
        Create_Poly(&Poly2);
    }
    Sum_Poly(Poly1,Poly2,&Sum);
    printf("The sum of polynomials : ");
    Display_Poly(&Sum);
    return 0;
}

void Create_Poly(struct node ** Poly)
{
    struct node * newnode,* temp;
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter the coefficient : ");
    scanf("%d",&newnode->Coe);
    printf("Enter the power : ");
    scanf("%d",&newnode->Pow);
    newnode->link = NULL;

    if(*Poly == NULL)
    {
        *Poly = newnode;
        temp = newnode;
    }
    else
    {
        temp->link = newnode;
        temp = newnode;
    }   
}

void Sum_Poly(struct node * Poly1,struct node * Poly2,struct node ** Sum)
{
    struct node * newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->link = NULL;
    *Sum = newnode;

    while(Poly1 && Poly2)
    {
        if(Poly1->Pow > Poly2->Pow)
        {
            newnode->Pow = Poly1->Pow;
            newnode->Coe = Poly1->Coe;
            Poly1 = Poly1->link;
        }
        else if(Poly1->Pow < Poly2->Pow)
        {
            newnode->Pow = Poly2->Pow;
            newnode->Coe = Poly2->Coe;
            Poly2 = Poly2->link;
        }
        else
        {
            newnode->Pow = Poly1->Pow;
            newnode->Coe = Poly1->Coe + Poly2->Coe;
            Poly1 = Poly1->link;
            Poly2 = Poly2->link;
        }
        if(Poly1 && Poly2)
        {
            newnode->link = (struct node *)malloc(sizeof(struct node));
            newnode = newnode->link;
            newnode->link = NULL;
        }
    }
    while(Poly1 || Poly2)
    {
        newnode->link = (struct node *)malloc(sizeof(struct node));
        newnode = newnode->link;
        newnode->link = NULL;
        if(Poly1)
        {
            newnode->Pow = Poly1->Pow;
            newnode->Coe = Poly1->Coe;
            Poly1 = Poly1->link;
        }
        if(Poly2)
        {
            newnode->Pow = Poly2->Pow;
            newnode->Coe = Poly2->Coe;
            Poly2 = Poly2->link;
        }
    }
}

void Display_Poly(struct node ** Poly)
{
    struct node *temp;
    temp = *Poly;
    while(temp != NULL)
    {
        printf("%dx^%d",temp->Coe,temp->Pow);
        temp = temp->link;
        if(temp != NULL)
        {
            printf(" + ");
        }
    }
}