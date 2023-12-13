#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int> v(n);
	priority_queue<int,vector<int>,greater<int>> q;
	for(int &x :v) cin>>x;
	for(int x:v){
		q.push(x);
	}
	int max1=0;
	int max2=0;
	int ans=0;
	while(q.size()>1){
		 max1=q.top();
		 q.pop();
		 max2=q.top();
		 q.pop();
		 ans+=max1+max2;
		 q.push(max1+max2);
	}
	cout<<ans<<endl;
}
