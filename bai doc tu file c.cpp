#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct SinhVien{
	int tuoi;
	char ten[100];
	int diem;
};
typedef struct SinhVien SinhVien;
void doctufile(FILE *f,SinhVien *a,int n)
{
	for(int i=0;i<n;i++)
	{
		fgets(a[i].ten,100,f);
		a[i].ten[strlen(a[i].ten)-1]='\0';

		
		fscanf(f,"%d",&a[i].tuoi);
		fscanf(f,"%d",&a[i].diem);
		fgetc(f);
	}
}
void xuattufile(FILE *f,SinhVien *a,int n){
		for(int i=0;i<n;i++)
	{
		fprintf(f,"ten sinh vien la : %s ",a[i].ten);
		fprintf(f,"\ntuoi sinh vien la: %d",a[i].tuoi);
		fprintf(f,"\ndiem sinh vien la : %d\n",a[i].diem);
	}
}

int main()
{
	int n;
	FILE *f,*f1;
	f1=fopen("output.txt","w");
	f=fopen("input.txt","r");
	if(f==NULL)
	{
		printf("khong the mo file");
	}
	fscanf(f,"%d",&n);
	SinhVien *a=(SinhVien*)malloc(n*sizeof(SinhVien));
	fgetc(f);
	doctufile(f,a,n);
	xuattufile(f1,a,n);
	
	
	
	
	
	
	
}
