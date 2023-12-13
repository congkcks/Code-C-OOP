#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void solve()
{
	string s;cin>>s;
	stack<char> st;
	for(char x:s)
	{
		cout<<x<<endl;
		if(x=='(')
		{
			st.push(x);
			
		}
		else{
			if(st.empty()){
				cout<<"NO"<<endl;
				return;
			}
			else{
				st.pop();
			}
		}
	}
	if(st.empty()){
		cout<<"YES"<<endl;
	}
	else cout<<"NO"<<endl;
}
int main()
{
	solve();
}
