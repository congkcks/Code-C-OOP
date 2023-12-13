// C++ Implementation
#include <iostream>
using namespace std;
const long long M = 1e9 + 7;

// Calculate Mod of A
long long MODA(string num)
{

	long long res = 0;

	for (long long int i = 0; i < num.length(); i++)
		res = (res * 10 + num[i] - '0') % M;

	return res;
}

// Calculate Mod of B
long long MODB(string b)
{

	long long res = 0;
	for (int i = 0; i < b.length(); i++)
		res = (res * 10 + b[i] - '0') % (M - 1);

	return res;
}

// Binary Multiplication Cade
long long BinMul(long long a, long long b)
{

	long long ans = 0;

	while (b > 0) {
		if (b & 1) {
			// When the bit is set
			ans = (ans * a) % M;
			// Doing normal addition
		}
		a = (a * a) % M;
		b >>= 1;
		// right shift the number by 1
	}
	return ans;
}

// Binary Exponentitation Code
long long BinExp(long long a, long long b)
{

	long long ans = 1;
	while (b > 0) {
		if (b & 1) {
			ans = BinMul(a, ans);
		}
		a = BinMul(a, a);
		b >>= 1;
	}
	return ans;
}

// Driver code
int main()
{

	string a,b;
	cin>>a>>b;

	long long aa = MODA(a);
	long long bb = MODB(b);

	// Function call
	// Taking a = 10^16 + 7 and b = 100
	cout << BinExp(aa, bb);

	return 0;
}

