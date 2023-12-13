#include<bits/stdc++.h>
using namespace std;


int main(){
	
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
		
	}
	stack<int> s;
	int lonnhat=0;
	int h=0;
	int w=0;
	int i=0;
	while(i<n){
		if(s.empty()||a[i]>a[s.top()]){
			s.push(i);
			i++;
		}
		else{
			h=a[s.top()];
			s.pop();
			if(s.empty()){
				w=i;
			}
			else{
				w=i-s.top()-1;
			}
			lonnhat=max(lonnhat,h*w);
		}
	}
	while(!s.empty()){
			h=a[s.top()];
			s.pop();
			if(s.empty()){
				w=i;
			}
			else{
				w=i-s.top()-1;
			}
			lonnhat=max(lonnhat,h*w);
		
	}
	cout<<lonnhat<<endl;
}
