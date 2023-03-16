
// Binary Search Program

#include <stdio.h>

int main()
{
    int i,n,L,R,Mid,num,Array[100],Position=-1;
    printf("Enter the number of elements in the sorted array : ");
    scanf("%d",&n);
    printf("Enter the elements in the array : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&Array[i]);
    }
    printf("Enter the number you want to search : ");
    scanf("%d",&num);
    L=0,R=n-1;
    while(L<=R)
    {
        Mid=(L+R)/2;
        if(Array[Mid] == num)
        {
            Position = Mid;
            break;
        }
        else if(num>Array[Mid])
        {
            L=Mid+1;
        }
        else
        {
            R=Mid-1;
        }
    }
    if(Position!=-1)
    {
        printf("The number found at %d ",Position+1);
    }
    else
    {
        printf("The number not found ");
    }
    return 0;
}