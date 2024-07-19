
// Sum of Polynomials Using Function

void Read(int [100],int );
void Sumpoly(int [100],int [100],int [100],int );

#include <stdio.h>

#define Max 100

int main()
{
    int P1[100],P2[100],Sum[100],i,d1,d2;

    // Assigning all elements in array to zero
    
    for(i=0;i<100;i++)
    {
        P1[i]=0;
    }
    for(i=0;i<100;i++)
    {
        P2[i]=0;
    }
    printf("Enter the degree of first polynomial : ");
    scanf("%d",&d1);
    Read(P1,d1);
    printf("Enter the degree of second polynomial : ");
    scanf("%d",&d2);
    Read(P2,d2);

    if(d1>d2)
    {
        Sumpoly(Sum,P1,P2,d1);
    }
    else
    {
        Sumpoly(Sum,P1,P2,d2);
    }
    return 0;
}

void Read(int P[100],int d)
{
    printf("Enter the coefficients from constants to higher degree of the matrix : ");
    for(int i=0;i<=d;i++)
    {
        scanf("%d",&P[i]);
    }
}

void Sumpoly(int Sum[100],int P1[100],int P2[100],int d)
{
    int i;
    for(i=0;i<=d;i++)
    {
        Sum[i]=P1[i]+P2[i];
    }
    printf("The added matrix is : ");
    for(i=d;i>=0;i--)
    {
        printf("%dx^%d + ",Sum[i],i);
    }
    printf("\n");
}