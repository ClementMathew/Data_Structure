
// Sparse Matrix Transpose by directly reading triplet

#include<stdio.h>
#define Max 100

typedef struct sparse
{
    int row;
    int col;
    int value;
} term;

term a[Max],b[Max];

void Transpose()
{
    int temp,currentb;
    temp = a[0].value;
    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].value = temp;
    if(temp>0)
    {
        currentb = 1;
        for(int i=0;i<=(a[0].col-1);i++)
        {
            for(int j=1;j<=temp;j++)
            {
                if(a[j].col==i)
                {
                    b[currentb].row = a[j].col;
                    b[currentb].col = a[j].row;
                    b[currentb].value = a[j].value;
                    currentb++;
                }
            }
        }
    }
}

int main()
{
    int n,r,c;
    printf("Enter the number of rows and columns of sparse matrix : ");
    scanf("%d %d",&r,&c);
    a[0].row = r;
    a[0].col = c;
    printf("Enter the number of non zero elements : ");
    scanf("%d",&n);
    a[0].value = n;
    printf("Enter the row , column , value of non zero elements : ");
    for(int i=1;i<=n;i++)
    {
        scanf("%d %d %d",&a[i].row,&a[i].col,&a[i].value);
    }
    printf("\nThe triplet representation before transpose is : ");
    for(int i=0;i<=n;i++)
    {
        printf("\n");
        printf("%d %d %d", a[i].row, a[i].col, a[i].value);
    }
    Transpose();
    printf("\nThe triplet representation after transpose is : ");
    for(int i=0;i<=n;i++)
    {
        printf("\n");
        printf("%d %d %d", b[i].row, b[i].col, b[i].value);
    }
    return 0;
}