#include<bits/stdc++.h>
using namespace std;

void tron(int *a,int l,int m,int r){
	vector<int> x(a+l,a+m+1);
	vector<int> y(a+m+1,a+r+1);
	int i=0;int j=0;
	while(i<x.size()&&j<y.size()){
		if(x[i]<=y[j]){
			a[l]=x[i];
			i++;
			l++;
		}
		else{
			a[l]=y[j];
			j++;l++;
			
		}
	}
	while(i<x.size()){
		a[l]=x[i];
		i++;l++;
	}
	while(j<y.size()){
		a[l]=y[j];
		j++;l++;
	}
}
void megesort(int a[],int l,int r){
	if(l>=r){
		return;
	}
	int m=(l+r)/2;
	megesort(a,l,m);
	megesort(a,m+1,r);
	tron(a,l,m,r);
}
int main(){
	int a[]={1,3,5,2,7};
	megesort(a,0,4);
	for(int x:a){
		cout<<x<<" ";
	}
	
}
