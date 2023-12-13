#include<bits/stdc++.h>
using namespace std;

int solve(int s,int t){
	
	queue<pair<int,int>> q;
	q.push({s,0});
	set<int> se;
	se.insert(s);
	while(!q.empty()){
		pair<int,int> top=q.front();q.pop();
		if(top.first==t) return top.second;
		if(top.first*2==t||top.first-1==t) return top.second+1;
		if(se.find(top.first)==se.end()&&top.first*2<t){
			q.push({top.first,top.second+1});
			se.insert(top.first);
		}
		if(se.find(top.first)==se.end()&&top.first-1>0){
			q.push({top.first,top.second+1});
			se.insert(top.first);
		}	
	}
}

int main(){
	int s,t;
	cin>>s>>t;
	cout<<solve(s,t)<<endl;
	return 0;
	
}
