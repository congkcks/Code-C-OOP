#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int a[100][100],ok;
int n;

vector<string> res;
void nhap(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			
			cin>>a[i][j];
		}
	}
	res.clear();
	ok=0;
}
void Try(int x,int y,string s){
	if(x==n&&y==n&&a[n][n]==1){
		res.push_back(s);
		ok=1;
		return;
		
	}
	if(x==1&&y==1&&a[x][y]==0){
		ok=0;
		return;
	}
	if(x<n&&a[x+1][y]==1){
		Try(x+1,y,s=s+"D");
	}
	if(y<n&&a[x][y+1]==1){
		Try(x,y+1,s=s+"R");
	}
	if((x<n&&y<n&&a[x+1][y]==0&&a[x][y+1]==0)||x>n||y>n){
		return;
	}
}
int main(){
	cin>>n;
	nhap();
	Try(1,1,"");
	sort(res.begin(),res.end());
	for(auto x:res){
		cout<<x<<endl;
	}
	return 0;
	
}
