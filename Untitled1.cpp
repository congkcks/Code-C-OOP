#include <iostream>
#include <fstream>
#include <string>
#include<bits/stdc++.h>
using namespace std;

class MatHang
{
public:
    string mahang, mausac;
    int soluong;
    double gia;

public:
    MatHang() {}
    MatHang(string mahang, string mausac, double gia)
    {
        this->mahang = mahang;
        this->mausac = mausac;
        this->gia = gia;
    }
    string getmausac()
    {
        return this->mausac;
    }
};
class Bosung:public MatHang
{
    string KichThuoc;

public:
    Bosung() : MatHang("", "", 0.0), KichThuoc("") {};
    string getkt(){
	   return (this->KichThuoc);
	}
    void nhap()
    {
        cin.ignore();
        getline(cin, mahang);
        getline(cin, mausac);
        cin >> KichThuoc;
        cin >> gia;
    }
    void in()
    {
        cout << mahang << "  " << mausac << " " << KichThuoc << " " << gia << fixed << endl;
    }
};

int main()
{
    int n;
    cin >> n;
    Bosung a[n];
    map<string,int> mp;
    map<string,int> mp1;
    for (int i = 0; i < n; i++)
    {
        a[i].nhap();
        mp[a[i].getkt()]++;
        mp1[a[i].getmausac()]++;
    }
    for (int i = 0; i < n; i++)
    {
        a[i].in();
    }
    cout<<endl;
    for(auto x :mp1)
    {
	cout<<"so luong cua mau "<<x.first<<"la : "<<x.second<<endl;	
	}
    return 0;
}
