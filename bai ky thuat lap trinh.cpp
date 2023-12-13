#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct SinhVien{
	int tuoi;
	char ten[100];
};
typedef struct SinhVien SinhVien;

void xuatfile(FILE* f,int **a,int n,int m)
{
		fprintf(f,"%d %d\n",n,m);
		for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
	{
		fprintf(f,"%d ",a[i][j]);
	}
	fprintf(f,"\n");
		
	}
}
void readfile(FILE *f,int **a,int n,int m)
{
		for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		fscanf(f,"%d",&a[i][j]);
		
	}
	
}
int main()
{
	FILE *f,*f1;
	f=fopen("input.txt","r");
	f1=fopen("output.txt","w");
	int n,m;
	fscanf(f,"%d%d",&n,&m);
	int **a=(int**)malloc(n*sizeof(int*));
	for(int i=0;i<m;i++)
	{
	 a[i]=(int*)malloc(m*sizeof(int));
	}
    readfile(f,a,n,m);
    xuatfile(f1,a,n,m);
    
	
	
	
}
