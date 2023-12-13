#include<iostream>
using namespace std;
int n,a[100],used[100];
void in()
{
	for(int i=1;i<=n;i++)
	{
		cout<<a[i];
		
	}
	cout<<endl;
	
}
void quaylui(int i)
{
	for(int j=1;j<=n;j++)
		{
			if(used[j]==0)
			{
				a[i]=j;
				used[j]=1;
			
			if(i==n)
			{
				in();
			}
			else{
				quaylui(i+1);
				
		}
		   used[j]=0;
		}
		
		}
	
	
}
void sinhxau(int i)
{
	for(int j=0;j<=1;j++)
	{
		a[i]=j;
		if(i==n)
		{
			in();
			
		}
		else{
			sinhxau(i+1);
		}
	}
	
}
int main()
{
	cin>>n;
	sinhxau(1);
	
	
}
