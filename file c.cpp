#include<stdio.h>
#include<bits/stdc++.h>
#include<string.h>
struct SinhVien{
	int tuoi;
	char ten[30];
};
typedef struct SinhVien SinhVien;
int main()
{
	FILE *f,*f1;
	f=fopen("input.txt","r");
    f1=fopen("output.txt","w");
	int n;
	fscanf(f,"%d",&n);
	fgetc(f);
	SinhVien *a=(SinhVien*)malloc(n*sizeof(SinhVien));
	
	for(int i=0;i<n;i++)
	{
		fgets(a[i].ten,30,f);
		a[i].ten[strlen(a[i].ten)-1]='\0';
		fscanf(f,"%d",&a[i].tuoi);
		fgetc(f);
	}
	for(int i=0;i<n;i++)
	{
		printf("%d\n",a[i].tuoi);
		printf("%s\n",a[i].ten);
		
		
	}
	for(int i=0;i<n;i++)
	{
		fprintf(f1,"so thu t : %d %s \n",i+1,a[i].ten);
	}
	fclose(f);
	
	
	
	
}
