#include<bits/stdc++.h>
using namespace std;
const long long M=1e9+7;
long long BinMul(long long a, long long b)
{
	long long ans = 1;

	while (b > 0) {
		if (b & 1) {
			// When the bit is set
			ans = (ans * a)%M;
			// Doing normal addition
		}
		a = (a * a)%M;
		b >>= 1;
		// right shift the number by 1
	}
	return ans;
}
int main()
{
	long long a,b;
	cin>>a>>b;
	cout<<BinMul(a,b);
	
	
	
}

