#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct diem{
	float x;
	float y;
};
typedef struct diem diem;




void read(FILE *f,diem *a,int n){
	for(int i=0;i<n;i++){
		fscanf(f,"%f",&a[i].x);
		fscanf(f,"%f",&a[i].y);
	}
}
void xuatfile(diem *a,int n){
	for(int i=0;i<n;i++){
		printf("%f\n",a[i].x);
		printf("%f\n",a[i].y);
	}
	
}

int main()
{
	int n;
	FILE *f;
	f=fopen("input.txt","rt");
	fscanf(f,"%d",&n);
	diem *a=(diem*)malloc(n*sizeof(diem));
	read(f,a,n);
	xuatfile(a,n);
	fclose(f);
	return 0;
}
