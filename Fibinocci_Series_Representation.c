
// Fibinocci Series Representation

#include<stdio.h>

int main()
{
	int start = 0,one = 1,n,i = 0,Nextterm;
	Nextterm = start + one;
	printf("Enter the limit of the series : ");
	scanf("%d",&n);
	printf("The fibinocci series is : ");
	printf("%d %d ",start,one);
	while(i<(n-2)){
		Nextterm = start + one;
		printf("%d ",Nextterm);
		start=one;
		one=Nextterm;
		i++;
	}
	return 0;
}

