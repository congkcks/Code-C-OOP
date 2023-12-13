#include<stdio.h>
#include<stdlib.h>

int compare(const void * a, const void * b){
   return ( *(int*)a - *(int*)b );
}//ham sap xep co san trong c

int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	for(int i=0;i<n;i++){
		scanf("%d", &a[i]);
	}
	qsort(a, n, sizeof(int), compare);
	int mid = a[n/2];
	int tongmax = 0;
	for(int i=0;i<n;i++){
		tongmax += abs(a[i] - mid);
	}
	printf("%d\n", tongmax);
	return 0;
}

