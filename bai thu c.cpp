#include<stdio.h>
#include<bits/stdc++.h>
#include<string.h>
struct SinhVien{
	int tuoi;
	char ten[30];
};
typedef struct SinhVien SinhVien;
void nhap(FILE *f,int **a,int n,int m)
{
		for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			fscanf(f,"%d",&a[i][j]);
		}
	}
}
void xuat(FILE *f,int **a,int n,int m)
{
		for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}
void hamya(FILE *f,int **a,int n,int m)
{
	int s=n*m;
	int sum=0;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			sum=sum+a[i][j];
			
		}
	}
	float tbc=(float)sum/s;
	sum=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(a[i][j]>tbc)
			{
				sum=sum+a[i][j];
			}
		}
	}
	if(sum==0){
		printf("khong co phan tu nao lon hon tbc cua ma tran");
	}
	else{
		printf("tong cac phan tu lon hon trung binh cong la: %d",sum);
	}
}
void hamyb(FILE *f,int **a,int n,int m)
{
	int check=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(a[i][j]<0)
			{
				check=a[i][j];
				break;	
			}
		}
	}
	if(check==0)
	{
		printf("khong co so am nao trong mang\n");
	}
	else{
			for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(a[i][j]<0)
			{
				if(a[i][j]<0&&a[i][j]>check)
				{
					check=a[i][j];
				}
			}
		}
	}
	}
	
    printf("\nso am lon nhat trong mang la %d",check);	
}
int main()
{
	FILE *f,*f1;
	f=fopen("input.txt","r");
    f1=fopen("output.txt","w");
	int n,m;
	fscanf(f,"%d %d",&n,&m);
	int **a=(int**)malloc(n*sizeof(int*));
	for(int i=0;i<n;i++)
	a[i]=(int*)malloc(m*sizeof(int));
	nhap(f,a,n,m);
	xuat(f,a,n,m);
	hamya(f,a,n,m);
	hamyb(f,a,n,m);
	fgetc(f);
	fclose(f);
	
	
	
	
}
