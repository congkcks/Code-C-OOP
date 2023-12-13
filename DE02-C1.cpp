#include<stdio.h>
#include<stdlib.h>
void docfile(FILE *f,int **a,int n,int m){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
		{
			fscanf(f,"%d",&a[i][j]);
		}
		
	}
	
}
void xuatvaofile(FILE *f,int **a,int n,int m)
{
	fprintf(f,"%d %d\n",n ,m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			fprintf(f,"%d ",a[i][j]);
			
		}
		fprintf(f,"\n");
	}
}
int main()
{
	FILE *f=fopen("input.txt","r");
	FILE *f1=fopen("output.txt","wt");
	int n,m;
	fscanf(f,"%d%d",&n,&m);
	fgetc(f);
	int **a=(int**)malloc(n*sizeof(int*));
	for(int i=0;i<m;i++){
		a[i]=(int*)malloc(m*sizeof(int));
	}
	docfile(f,a,n,m);
	xuatvaofile(f1,a,n,m);
	

	
	
	
}
