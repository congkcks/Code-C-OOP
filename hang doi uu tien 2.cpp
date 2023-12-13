#include<bits/stdc++.h>
#include<iostream>
using namespace std;


int main(){
	int k;
	cin>>k;
	cin.ignore();
	string s;cin>>s;
	map<char,int> mp;
	for( char x:s){
		mp[x]++;	
	}
	priority_queue<int> q;
	for(auto x : mp){
		cout<<x.second<<endl;
		q.push(x.second);
	}
	while(k>0){
		int top=q.top();q.pop();
		top--;
		k--;
		q.push(top);
	}
	int ans=0;
	while(!q.empty()){
		int top=q.top();
		ans=ans+top*top;
		q.pop();
		
	}
	

	
}
