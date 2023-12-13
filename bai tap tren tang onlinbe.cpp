#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const long long mod=1e9+7;
char a[100000],b[100000];
long long find(char a[],long long so)
{
	long long res=0;
	long long sum=0;
	for(int i=0;i<strlen(a);i++)
	{
		res=res*10+a[i]-'0';
		res%=so;
		
	}
	return res;
}
long long chia2(char b)
{
	
}
long long luythua(char a[],char b[])
{
	long long res=1;
	while(b)
	if(find(b,2)==1)
	{
		res*=a;
		res*=mod;
		
	}
	a*=a;
}
	
	
	
	
}



int main()
{
	cin>>a>>b;
	long long sodu=find(b,2);
	

	return 0;	
}
