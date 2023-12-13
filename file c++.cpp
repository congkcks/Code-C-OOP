#include<iostream>
#include<fstream>
using namespace std;



int main()
{
	int n;
	cin>>n;
	int a[3][4];
	ifstream  myfile;
	myfile.open("input.txt");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			myfile>>a[i];
		}
	}
	
	
	
	myfile.close();
	
	
	
}
