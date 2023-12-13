#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
	
	int n;cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
		
	}
	vector<int> l(n,1);
	int maxday=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			if(a[i]>a[j]){
				l[i]=max(l[i],l[j]+1);
			}
		}
	}
	sort(l.begin(),l.end());
	cout<<l.back()<<endl;
	
}
