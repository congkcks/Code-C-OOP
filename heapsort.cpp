#include<bits/stdc++.h>
using namespace std;
void swap(int *a,int *b){
	int tmp=*a;
	*a=*b;
	*b=tmp;
}
void heaptify(int a[],int n,int i){
	int left=2*i+1;
	int right=2*i+2;
	int largest=i;
	if(left<n&&a[left]>a[largest]){
		largest=left;
	}
	if(right<n&&a[right]>a[largest]){
		largest=right;
	}
	if(largest!=i){
		swap(&a[i],&a[largest]);
   	     heaptify(a,n,largest);
      }
}
void heapsort(int a[],int n){
	for(int i=n/2-1;i>=0;i--){
		heaptify(a,n,i);
	}
	for(int i=n-1;i>=0;i--){
		swap(a[0],a[i]);
		heaptify(a,i,0);
	}
}

int main(){
	
	

int a[5]={1,2,4,3,5};
heapsort(a,5);
for(int x:a){
	cout<<x<<" ";
}


}

