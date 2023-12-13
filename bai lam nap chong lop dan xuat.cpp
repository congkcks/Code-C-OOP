#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class DayNguyen{
	private:
		int n;
		int *x;
    public:
    	DayNguyen(){
    		n=0;
    		x=NULL;
		}
    	friend istream &operator >> (istream &cin,DayNguyen &a){
    		cout<<"nhap n vao"<<endl;
    		cin>>a.n;
    		a.x=new int[a.n];
    		for(int i=0;i<a.n;i++){
    			cin>>a.x[i];
			}
			
		}
		friend ostream &operator << (ostream &cout,DayNguyen a){
			for(int i=0;i<a.n;i++){
				cout<<a.x[i]<<" ";
			}

		}
		friend int operator - (DayNguyen a,DayNguyen b){
			int s1=0;
			int s2=0;
			for(int i=0;i<a.n;i++){
				s1=s1+a.x[i];
				
			}
			for(int i=0;i<b.n;i++){
				s2=s2+b.x[i];
			}
			return s1-s2;
		}
		friend int snt(DayNguyen a);

};
int songuyento(int x){
	for(int i=2;i<(int)sqrt(x);i++){
		if(x%i==0){
			return 0;
		}
		
	}
	return 1;
}
int snt(DayNguyen a){
	int dem=0;
	int s=0;
	for(int i=0;i<a.n;i++){
		if(songuyento(a.x[i])==1){
			dem++;
			s=s+a.x[i];
		}
	}
	if(s==0){
		return 0;
	}else  return float(s/dem);
}
int main(){
	DayNguyen x,y;
	cin>>x;
	cout<<x;
	cin>>y;
	cout<<y;
	cout<<"day A tru day B "<<x-y<<endl;
	if(snt(x)>snt(y)){
		cout<<"day A co trung bing so nguyen to lon hon day B"<<endl;
	}
	else cout<<"Day b co trung binh so nguyen to lon hon day A"<<endl;
	
	
	return 0;
	
	
}
