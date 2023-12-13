#include<bits/stdc++.h>
using namespace std;

int main(){
	int s;
	int t;
	cin>>s>>t;
	queue<int> q;
	int c[200005];
	for(int i=0;i<200005;i++){
		c[i]=1e9;
	}
	c[s]=0;
	q.push(s);
	while(c[t]==1e9){
		int temp=q.front();
		q.pop();
		if(temp*2<200005&&c[temp*2]==1e9){
			q.push(temp*2);
			c[temp*2]=c[temp]+1;
		}
		if(temp-1>0&&c[temp-1]==1e9){
			q.push(temp-1);
			c[temp-1]=c[temp]+1;
		}
		
		
	}
	cout<<c[t]<<endl;
	return 0;
}
