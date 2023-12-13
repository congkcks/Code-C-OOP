#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class NhanVien{
	private:
		string manhanvien,hoten,namsinh;
		public:
			void nhap1()
			{
				cin.ignore();
				getline(cin,manhanvien);
				getline(cin,hoten);
				getline(cin,namsinh);
			}
			void xuat1()
			{
				cout<<manhanvien<<" "<<hoten<<" "<<namsinh<<endl;
			}
			string getten(){
				return this->hoten;
			}
			string getnamsinh()
			{
				return this->namsinh;
			}
};
class HD:public NhanVien{
	private:
		long long tiencong;
		int ngaycong;
		public:
			void nhap()
			{
				cin>>tiencong>>ngaycong;
			}
			void xuat()
			{
				long long tienluong=tinhluong();
				cout<<"tien luong cua nhan vien do la:  "<<tienluong<<endl;
			}
			float tinhluong()
			{
				long long tienluong=tiencong*ngaycong;
				return tienluong;
				
			}
			friend void timten(HD a[],int n);
			friend void tuoinhonhat(HD a[],int n);
;

		
	
	
};
void timten(HD a[],int n)
{
	string s;
	getline(cin,s);
	int check=0;
	for(int i=0;i<n;i++)
	{
		if(a[i].getten()==s)
		{
			a[i].xuat1();
			check=1;
		}
		
	}
	if(check=0)
	{
		cout<<"khong co ten cua nhan vien trong cong ty"<<endl;
	}
}
void tuoinhonhat(HD a[],int n)
{
	string check=a[0].getnamsinh();
	HD b;
	for(int i=0;i<n;i++)
	{
		if(a[i].getnamsinh()<check)
		check=a[i].getnamsinh();
		b=a[i];
		
		
	}
	cout<<"nhan vien tre tuoi nhat trong cong ty la "<<endl;
	b.xuat();
	
}
int compare(HD a,HD b)
{
	return a.getnamsinh()>b.getnamsinh();
}
void intheothutu(HD a[],int n)
{
	sort(a,a+n,compare);
	cout<<"danh sach nhan vien theo thu tu giam dan"<<endl;
	for(int i=0;i<n;i++)
	{
		a[i].xuat1();
		
	}
	
}
int main()
{
	cout<<"nhap so khach hang"<<endl;
	int n;cin>>n;
	HD *a=new HD[n];
	for(int i=0;i<n;i++)
	{
		a[i].nhap1();
		a[i].nhap();
	}
	for(int i=0;i<n;i++)
	{
		a[i].xuat1();
		a[i].xuat();
	}	
	
	
	
	
	
}
