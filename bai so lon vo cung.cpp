#include<iostream>
#include<bits/stdc++.h>
using namespace std;
using ll =long long;
bool check(ll n)
{
	if(n<0) n=n*-1;
	string s=to_string(n);
	for(int i=0;i<s.size();i++)
	{
		if((i+1)%2!=(s[i]-'0')%2)
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	ll n;
	cin>>n;
	if(check(n))
	{
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}
	
	
	
}
