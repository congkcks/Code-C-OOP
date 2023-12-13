#include<stdio.h>
#include<stdlib.h>
void nhap(int **a,int n)

{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
}
void xuat(int **a,int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
		
	}
	
}
int hamyb(int **a,int n)
{
	 int max = -1; 
    for (int i = 1; i < n; i++)
    {
        for (int j =n-1 ; j > n - i; j--)
        {
            if (a[i][j] % 2 != 0 && a[i][j] > max)
            {
                max= a[i][j];
            }
        }
    }

    if (max != -1)
    {
        printf("Gia tri lon nhat trong cac phan tu le duoi duong cheo phu: %d\n", max);
    }
    else
    {
        printf("Khong co phan tu le duoi duong cheo phu.\n");
    }
    return max;
}
int hamyc(int **a,int n,int max)
{
	if(max==-1)
	{
		printf("khong co gia tri nao thoa man y b");
		return 0;
	}
    for (int i = 0; i < n - 1; i++)
    {
      for(int j=0;j<n-i;j++)
      {
      	if(a[i][j]==max)
      	{
      		printf("gia tri thoa man y b la %d",a[i][j]);
      		
		}
	  }
    }
    printf("\n");
}
int main()
{
	int n;
	printf("nhap n");
	scanf("%d",&n);
	int **a= (int**)malloc(n*sizeof(int *));
	for(int i=0;i<n;i++)
	{
		a[i]=(int*)malloc(n*sizeof(int));
	}
	nhap(a,n);
	xuat(a,n);
	hamyb(a,n);
	int max=hamyb(a,n);
	hamyc(a,n,max);
	return 0;
}
