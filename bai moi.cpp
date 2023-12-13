#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class DiemThi{
	private:
		string mamon,tenmon;
		int tinchi;
		float diemquatrinh,diemthi;
	public:
	friend istream &operator >> (istream &cin,DiemThi &a){
		getline(cin,a.tenmon);
		cin>>a.mamon>>a.tinchi>>a.diemquatrinh>>a.diemthi;
		return cin;
	}
	friend ostream &operator << (ostream &cout,DiemThi a){
		cout<<a.tenmon<<"  "<<a.mamon<<" "<<a.diemquatrinh<<" "<<a.diemthi<<endl;
		return cout;
	}
	float diembinhquan(){
		return this->diemquatrinh*0.4+this->diemthi*0.6;
	}
	string gettenmon(){
		return this->tenmon;
	}
	int gettin(){
		return this->tinchi;
	}
};
int comp(DiemThi a,DiemThi b){
	return a.diembinhquan()<b.diembinhquan();
}
float  diemtongket(DiemThi *a,int n){
	int sotin=0;
	float s1=0,s2=0;
	for(int i=0;i<n;i++){
		s1=s1+a[i].diembinhquan()*a[i].gettin();
		sotin=sotin+a[i].gettin();
	}
	return s1/sotin;
}
int main(){
	cout<<"nhap so mon cua sinh vien "<<endl;
	int n;
	cin>>n;
	DiemThi a[n];
	for(int i=0;i<n;i++){
		cout<<"nhap thong tin mon thu "<<i+1<<endl;
		cin.ignore();
		cin>>a[i];
	}
	sort(a,a+n,comp);
	for(int i=0;i<n;i++){
		cout<<a[i];
    }
    cout<<"diem tong ket cua sinh vien"<<diemtongket(a,n)<<endl;
    return 0;
}
