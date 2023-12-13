#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int *a=(int*)malloc(n*m*sizeof(int));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",a+i*n+j);
		}
	}
		for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%d ",*a+i*n+j);
		}
		printf("%\n");
	}
	 return 0;	
}
