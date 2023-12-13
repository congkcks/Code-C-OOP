#include<stdio.h>
#include<stdlib.h>


void nhap(int *a,int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",a+i*n+j);
		}
	}
}
void xuat(int *a,int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%d ",*a+i*j+n);
		}
		printf("\n");
		
	}
	
}
int main()
{
	int n;
	printf("nhap n\n");
	scanf("%d",&n);
	int *a=(int*)malloc(n*n*sizeof(int));
	nhap(a,n);
	xuat(a,n);
	
	
}
