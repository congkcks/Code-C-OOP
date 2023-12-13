#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<int> v(n);
	for(int j=0;j<n;j++) cin>>v[j];
	int lonnhat=0;
	int h=0;
	int w=0;
	int i=0;
	stack<int> s;
	while(i<n){
		if(s.empty()||v[i]>v[s.top()]){
			s.push(i);
			i++;
		}
		else{
			h=v[s.top()];
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
			h=v[s.top()];
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
