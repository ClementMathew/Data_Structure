
// Sum of Sparse Matrices

#include <stdio.h>
#include <stdlib.h>

void readmatrix(int [50][50],int,int);
void triplet_print(int [50][50],int [20][3],int,int);
void sum_sparse(int [50][50],int [50][50],int [20][3],int [20][3],int[20][3]);

int main()
{
    int r1,c1,r2,c2,sparse_1[50][50],sparse_2[50][50],triplet_1[20][3],triplet_2[20][3],Sum[20][3];
    printf("Enter the number of rows and columns of 1st matrix : ");
    scanf("%d %d",&r1,&c1);
    readmatrix(sparse_1,r1,c1);
    printf("Enter the number of rows and columns of 2nd matrix : ");
    scanf("%d %d",&r2,&c2);
    readmatrix(sparse_2,r2,c2);

    printf("\nThe triplet representation of 1st matrix : ");
    triplet_print(sparse_1,triplet_1,r1,c1);
    printf("\nThe triplet representation of 2nd matrix : ");
    triplet_print(sparse_2,triplet_2,r2,c2);

    if(r1==r2 && c1==c2)
    {
        printf("\nThe sum of two sparse matrices is : ");
        sum_sparse(sparse_1,sparse_2,triplet_1,triplet_2,Sum);
    }
    else
    {
        printf("\nerror!");
    }
    return 0;
}

void readmatrix(int sparse[50][50],int r,int c)
{
    int i,j;
    printf("Enter the elements of the matrix : ");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&sparse[i][j]);
        }
    }
}

void triplet_print(int sparse[50][50],int triplet[20][3],int r,int c)
{
    int i,j,k=0;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(sparse[i][j]!=0)
            {
                triplet[k][0]=i;
                triplet[k][1]=j;
                triplet[k][2]=sparse[i][j];
                k++;
            }
        }
    }
    printf("\nThe number of non zero elements is %d ",k);
    sparse[50][50]=k;

    // printing triplet

    printf("\nrow\tcolumn\tvalue");
    for(i=0;i<k;i++)
    {
            printf("\n%d\t%d\t%d",triplet[i][0],triplet[i][1],triplet[i][2]);
    }
}

void sum_sparse(int sparse_1[50][50],int sparse_2[50][50],int triplet_1[20][3],int triplet_2[20][3],int Sum[20][3])
{
    int i=0,j=0,k=0;
    int m=sparse_1[50][50],n=sparse_2[50][50];
    while(i<=m && j<=n)
    {
        if(triplet_1[i][0]<triplet_2[j][0] || (triplet_1[i][0]==triplet_2[j][0] && triplet_1[i][1]<triplet_2[j][1]))
        {
            Sum[k][0]=triplet_1[i][0];
            Sum[k][1]=triplet_1[i][1];
            Sum[k][2]=triplet_1[i][2];
            k++;
            i++;
        }

        else if(triplet_1[i][0]>triplet_2[j][0] || (triplet_1[i][0]==triplet_2[j][0] && triplet_1[i][1]>triplet_2[j][1]))
        {
            Sum[k][0]=triplet_2[j][0];
            Sum[k][1]=triplet_2[j][1];
            Sum[k][2]=triplet_2[j][2];
            k++;
            j++;
        }

        else
        {
            Sum[k][0]=triplet_1[i][0];
            Sum[k][1]=triplet_1[i][1];
            Sum[k][2]=triplet_1[i][2] + triplet_2[j][2];
            i++;
            k++;
            j++;
        }
    }

    while(i<=m)
    {
            Sum[k][0]=triplet_1[i][0];
            Sum[k][1]=triplet_1[i][1];
            Sum[k][2]=triplet_1[i][2];
            k++;
            i++;
    }

    while(j<=n)
    {
            Sum[k][0]=triplet_2[j][0];
            Sum[k][1]=triplet_2[j][1];
            Sum[k][2]=triplet_2[j][2];
            k++;
            j++;
    }

    if(m>n)
    {
        printf("\nrow\tcolumn\tvalue");
        for(i=0;i<m;i++)
        {
            printf("\n%d\t%d\t%d",Sum[i][0],Sum[i][1],Sum[i][2]);
        }
    }
    
    else
    {
        printf("\nrow\tcolumn\tvalue");
        for(i=0;i<n;i++)
        {
            printf("\n%d\t%d\t%d",Sum[i][0],Sum[i][1],Sum[i][2]);
        }
    }
}