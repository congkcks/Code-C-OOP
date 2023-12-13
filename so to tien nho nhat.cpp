#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int thamlam(int a[],int n,int s){
	int check=0;
	for(int i=n-1;i>=0;i--)
	{
		check+=s/a[i];
		s=s%a[i];
	}
	return check;
	
}
int main(){
	int n;
	int s;
	cin>>n>>s;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	cout<<"so to tien it nhat la:  "<<thamlam(a,n,s)<<endl;
}
