
// Transpose of Sparse matrix

#include <stdio.h>
#include <stdlib.h>

void readmatrix(int sparse[50][50],int,int);
void triplet_print(int sparse[50][50],int triplet[20][3],int,int);
void transpose(int triplet[20][3],int trans[20][3],int);

int main()
{
    int r,c,sparse[50][50],triplet[20][3],trans[20][3];
    printf("Enter the number of rows : ");
    scanf("%d",&r);
    printf("Enter the number of columns : ");
    scanf("%d",&c);
    readmatrix(sparse,r,c);
    triplet_print(sparse,triplet,r,c);
    transpose(triplet,trans,c);
    return 0;  
}

void readmatrix(int sparse[50][50],int r,int c)
{
    int i,j;
    printf("Enter the elements of the matrix : ");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            scanf("%d",&sparse[i][j]);
        }
    }
}

void triplet_print(int sparse[50][50],int triplet[20][3],int r,int c)
{
    int i,j,k=0;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            if(sparse[i][j]!=0){
                triplet[k][0]=i;
                triplet[k][1]=j;
                triplet[k][2]=sparse[i][j];
                k++;
            }
        }
    }
    printf("The number of non zero elements is %d ",k);
    triplet[20][2]=k;

    // printing triplet

    printf("\nThe triplet representation before transpose : ");
    printf("\nrow\tcolumn\tvalue");
    for(i=0;i<k;i++){
            printf("\n%d\t%d\t%d",triplet[i][0],triplet[i][1],triplet[i][2]);
    }
}

void transpose(int triplet[20][3],int trans[20][3],int c)
{
    int i,j,k=0,m;
    m=triplet[20][2];
    printf("\nThe triplet representation after transpose : ");
    printf("\n");
    printf("\nrow\tcolumn\tvalue");
    for(i=0;i<c;i++){
        for(j=0;j<m;j++){
            if(triplet[j][1]==i){
                trans[k][0]=triplet[j][1];
                trans[k][1]=triplet[j][0];
                trans[k][2]=triplet[j][2];
                k++;
            }
        }
    }
    for(i=0;i<k;i++){
            printf("\n%d\t%d\t%d",trans[i][0],trans[i][1],trans[i][2]);
    }
}

