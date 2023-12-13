#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class HocSinh{
	private:
	string hoten;
	string MHS;
	float diemrenluyen;
	float uutien;
	public:
		friend istream &operator >> (istream &cin,HocSinh &a){
			cout<<"nhap thong tin hoc sinh"<<endl;
			getline(cin,a.hoten);
			cout<<"Nhap MHS"<<endl;
			cin>>a.MHS;
			cout<<"NHap Diem :"<<endl;
			cin>>a.diemrenluyen>>a.uutien;
			return cin;
		}
		friend ostream &operator <<(ostream &cout,HocSinh a){
			cout<<a.hoten<<" "<<a.MHS<<" "<<a.diemrenluyen<<" "<<a.uutien<<endl;
		}
		float gettongdiem(){
			return this->diemrenluyen+this->uutien;
		}	
};
int comp(HocSinh a,HocSinh b){
	return a.gettongdiem()<b.gettongdiem();
	
}

int main(){
    cout<<"nhap so hoc sinh "<<endl;
    int n;
    cin>>n;
    HocSinh *a=new HocSinh[n];
    for(int i=0;i<n;i++){
    	cin.ignore();
        cin>>a[i];
    }
    sort(a,a+n,comp);
    for(int i=0;i<n;i++){
    	cout<<a[i];
    	
	}
    
    free(a);
}



