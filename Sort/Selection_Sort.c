
// Selection Sort Program

#include <stdio.h>

int main()
{
    int List[100],i,small,n,j,temp;
    printf("Enter the number of element in array : ");
    scanf("%d",&n);
    printf("Enter the elements : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&List[i]);
    }
    for(i=0;i<n-1;i++)
    {
        small=i;
        for(j=i+1;j<n;j++)
        {
            if(List[small]>List[j])
            {
                small=j;
            }
        }
        temp=List[i];
        List[i]=List[small];
        List[small]=temp;
    }
    printf("The sorted elements are : ");
    for(i=0;i<n;i++)
    {
        printf("%d  ",List[i]);
    }
    return 0;
}