#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void nhap(float *a,int n)
{
	for(int i=0;i<n;i++)
	{
			scanf("%f",a+i);
		
	}
	
}
void xuat(float *a,int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%2f ",*(a+i));
	}
	
}
float nhonhat(float *a,int n)
{
	float check=a[0];
	for(int i=0;i<n;i++){
		if(a[i]<check){
			check=a[i];
		}
	}
	return check;
	
	
}
int main()
{
	int n;
	scanf("%d",&n);
	float *a=(float*)malloc(n*sizeof(float));
	nhap(a,n);
	xuat(a,n);
	printf("gia tri nho nhat cua day so la: %2f",nhonhat(a,n));
}
