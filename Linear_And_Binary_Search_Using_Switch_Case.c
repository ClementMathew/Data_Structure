
// Linear and Binary Search Using Switch Case

#include <stdio.h>

int main()
{
    int i,n,L,R,mid,num,array[100],choice;
    while(1)
    {
        int count=-1,position=-1;
        printf("Press 1 to use Linear Search\n");
        printf("Press 2 to use Binary Search\n");
        printf("Press 3 to Exit\n");
        printf("Enter your choice\n");
        printf("-------------------------\n");

        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter the number of elements in the array : ");
                    scanf("%d",&n);
                    printf("Enter the elements in the array : ");
                    for(i=0;i<n;i++){
                        scanf("%d",&array[i]);
                    }
                    printf("Enter the number you want to search : ");
                    scanf("%d",&num);
                    for(i=0;i<n;i++){
                        if(num==array[i]){
                            count=i;
                        }
                    }
                    if(count>=0){
                        printf("The number found at %d \n",count+1);
                    }
                    else{
                        printf("The number not found\n");
                    }
                    break;

            case 2: printf("Enter the number of elements in the sorted array : ");
                    scanf("%d",&n);
                    printf("Enter the elements in the array : ");
                    for(i=0;i<n;i++){
                        scanf("%d",&array[i]);
                    }
                    printf("Enter the number you want to search : ");
                    scanf("%d",&num);
                    L=0,R=n-1;
                    while(L<=R)
                    {
                        mid=(L+R)/2;
                        if(array[mid]==num){
                            position = mid;
                            break;
                        }
                        else if(num>array[mid]){
                            L=mid+1;
                        }
                        else{
                            R=mid-1;
                        }
                    }
                    if(position!=-1){
                        printf("The number found at %d \n",position+1);
                    }
                    else{
                        printf("The number not found \n");
                    }
                    break;

            case 3: printf("Good Bye!\n");
                    break;

            default : printf("You entered wrong choice\n\n");
                      break;
            
        }
        if(choice==3){
            break;
        }
    }
    return 0;
}