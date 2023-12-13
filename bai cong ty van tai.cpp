#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class CTY{
	private:
		string ten;
		int namthanhlap;
	public:
		void nhap1(){
			cout<<"nhap ten "<<endl;
			getline(cin,ten);
			cin>>namthanhlap;
		}
		void xuat1(){
			cout<<ten<<" "<<namthanhlap<<endl;
		}
		int getnam(){
			return this->namthanhlap;
		}
		string getten(){
			return this->ten;
		}
		
};
class CTPM:public CTY{
	private:
		int sltv;
	public:
		void nhap2(){
			cout<<"nhap so luong nhap trinh vien "<<endl;
			cin>>sltv;
		}
		void xuat2(){
			cout<<sltv<<endl;
		}
		int getsl(){
			return this->sltv;
		}
		
};
class CTVT:public CTPM{
	private:
		int soto;
	public:
	void nhap3(){
		    nhap1();
			cin>>soto;
		}
		void xuat3(){
			cout<<soto<<endl;
		}
		int getoto(){
			return this->soto;
		}
			
		
};
int main()
{
	cout<<"nhap so cong ty phan mem"<<endl;
	int n;cin>>n;
	cout<<"nhap so cong ty van tai "<<endl;
	int m;cin>>m;
	CTPM a[n];
	CTVT b[m];
	for(int i=0;i<n;i++){
		cout<<"nhap cong ty phan mem thu "<<i+1<<endl;
		cin.ignore();
		a[i].nhap1();
		a[i].nhap2();
	}
	for(int i=0;i<m;i++){
		cin.ignore();
		cout<<"nhap cong ty van tai thu "<<i+1<<endl;
		b[i].nhap3();
	}
	int dem=0;
	vector<string> v;
	for(int i=0;i<n;i++){
		if(a[i].getnam()>2000&&a[i].getsl()>20){
			v.push_back(a[i].getten());
		}
	}
	cout<<"cac cong ty co so nam thanh lap hon 2000 va hon 20 lap trinh vien la :"<<endl;
	for(auto x:v){
		cout<<x<<endl;
	}
}
