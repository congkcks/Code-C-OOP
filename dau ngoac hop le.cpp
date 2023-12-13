#include<bits/stdc++.h>
using namespace std;
void daungoac(string s){
	stack<char> st;
	for(char x:s){
		if(x=='('){
			st.push(x);
		}
		else{
			if(st.empty()){
				cout<<"INVAIL"<<endl;
			}
			else{
				st.pop();
			}
		}
	}
	if(st.empty()!=0){
		cout<<"VAIL"<<endl;
	}
	else{
		cout<<"INVAIL"<<endl;
	}
	
}
int main(){
	string s;
	cin>>s;
	daungoac(s);
	return 0;
}
