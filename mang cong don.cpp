#include<bits/stdc++.h>
using namespace std;

void out(vector<int> v){
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
}
int main(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	while(v.size()>1){
		for(int i=0;i<v.size()-1;i++){
			v[i]=v[i]+v[i+1];
		}
			v.pop_back();
			out(v);
	}
	
	
	return 0;
}
