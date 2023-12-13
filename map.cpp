#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	
	map<string,int> mp;
	mp["tranminhhoa"]=3;
	mp["nguyen asndvkja"]=4;
	for(auto x: mp)
	{
		cout<<x.second<<endl;
	}
}
