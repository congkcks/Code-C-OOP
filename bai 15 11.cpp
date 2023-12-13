#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Nguoi{
	private:
		string hoten;
		string namsinh;
	public:
		void nhap(){
			getline(cin,hoten);
			getline(cin,namsinh);
		}
		void xuat(){
			cout<<"ho ten :"<<hoten<<" "<<"Nam Sinh:"<<namsinh<<endl;
		}
		string getnamsinh(){
			return this->namsinh;
		}
	   	
};
class BenhNhan:public Nguoi{
	private:
		string benh;
	public:
		string getbenh(){
			return this->benh;
		}
		void nhap1(){
			nhap();
			getline(cin,benh);
		}
		void xuat1(){
			xuat();
			cout<<"Loai benh :"<<benh<<endl;
			
		}
};
void thongke(BenhNhan *a,int n){
	map<string,int> mp;
	for(int i=0;i<n;i++){
		mp[a[i].getbenh()]++;
	}
	for( auto &x :mp){
		cout<<"so benh nhan cua benh "<<x.first<<" la : "<<x.second<<endl;
		
	}
	string tuoi="0";
	for(int i=0;i<n;i++){
		
			if(a[i].getbenh()=="D"){
				tuoi=a[i].getnamsinh();
			}
	}
	if(tuoi=="0"){
		cout<<"khong co benh nhan D nao "<<endl;
	}
	else{
		cout<<"benh nhan D co so tuoi nho nhat la benh nhan sinh nam  "<<tuoi<<" tuoi"<<endl;
	}

}

int main(){
	int n;
	cout<<"nhap so benh nhan"<<endl;
	cin>>n;
	cin.ignore(1);
	BenhNhan *a=new BenhNhan[n];
	for(int i=0;i<n;i++){
		a[i].nhap1();
		
	}
	for(int i=0;i<n;i++){
		a[i].xuat1();
	}
	thongke(a,n);
	
	return 0;
	
	
	
}
