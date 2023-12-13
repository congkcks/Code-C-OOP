#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class HocSinh{
	private:
	string hoten;
	string MHS;
	float diemrenluyen;
	int uutien;
	public:
		friend istream &operator >> (istream &cin,HocSinh &a){
			cout<<"nhap thong tin hoc sinh"<<endl;
			getline(cin,a.hoten);
			cin>>a.MHS>>a.diemrenluyen>>a.uutien;
			return cin;
		}
		friend ostream &operator << (ostream &cout,HocSinh a){
			cout<<a.hoten<<" "<<a.MHS<<" "<<a.diemrenluyen<<" "<<a.uutien<<endl;
			return cout;
		}
		
	
	
};
int main(){
	HocSinh x;
	cin>>x;
	cout<<x;
	
	
}


