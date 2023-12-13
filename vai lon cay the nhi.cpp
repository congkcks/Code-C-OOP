#include<stdio.h>
#include<stdlib.h>
void nhap(int a[],int n,int m)
{
		for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",a+i*n+j);
		}
	}
	
	
}
void in(int a[],int n,int m)
{
		for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%d ",*a+i*n+j);
		}
		printf("\n ");
	}
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int *a=(int*)malloc(500*500*sizeof(int));
	int *b=(int*)malloc(500*500*sizeof(int));
	int *c=(int*)malloc(500*500*sizeof(int));
	nhap(a,n,m);
	nhap(b,n,m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			c[i*n+j]=b[i*n+j]+a[i*n+j];
		}
	}
	in(c,n,m);
	
	return 0;	
}
