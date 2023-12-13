#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct SinhVien{
	int tuoi;
	char ten[100];
};
typedef struct SinhVien SinhVien;

void readfile(FILE* f,SinhVien *a,int n)
{
		for(int i=0;i<n;i++)
	{
		fgets(a[i].ten,100,f);
		a[i].ten[strlen(a[i].ten)-1]='\0';
		fscanf(f,"%d",&a[i].tuoi);
		fgetc(f);
		
	}
}
void xuatfile(FILE *f,SinhVien *a,int n)
{
		for(int i=0;i<n;i++)
	{
		fprintf(f,"ten sinh vien la:%s",a[i].ten);
		fprintf(f,"\ntuoi sinh vien la:%d\n",a[i].tuoi);
		
	}
	
}



int main()
{
	FILE *f,*f1;
	f=fopen("input.txt","r");
	f1=fopen("output.txt","w");
	int n;
	fscanf(f,"%d",&n);
	fgetc(f);
	SinhVien *a=(SinhVien*)malloc(n*sizeof(SinhVien));
    readfile(f,a,n);
    xuatfile(f1,a,n);
    
	
	
	
}
