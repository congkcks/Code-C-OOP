#include<bits/stdc++.h>
using namespace std;
void tron(int a[],int l,int mid,int r){
	vector<int> x(a+l,a+mid+1);
	vector<int> y(a+mid+1,a+r+1);
	int i=0;int j=0;
	while(i<x.size()&&j<y.size()){
		if(x[i]<=y[j]){
			a[l]=x[i];
			i++;
			l++;
		}
		else{
			a[l]=y[j];
			j++;
			l++;
		}
		
	}
	while(i<x.size()){
		a[l]=x[i];
		l++;
		i++;
	}
	while(j<y.size()){
		a[l]=y[j];
		l++;
		j++;
	}
}
void megesort(int a[],int l,int r){
	if(l>=r){
		return;
	}
	int mid=(l+r)/2;
	megesort(a,l,mid);
	megesort(a,mid+1,r);
	tron(a,l,mid,r);
}
int main()
{
	int a[5]={6,2,1,5,7};
	megesort(a,0,4);
	for(auto x:a){
		cout<<x<<" ";
	}
	
	
}
