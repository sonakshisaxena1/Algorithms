#include<bits/stdc++.h>
using namespace std;
#define INT_BITS 32
vector<int> a;

int leftRotateBits(unsigned int n, int d)
{
	unsigned int A, B;
	A = n << d;
	B = n >> (INT_BITS - d);
	return (A|B);
}

int rightRotateBits(unsigned int n, int d)
{
	unsigned int A, B;
	A = n >> d;
	B = n << (INT_BITS - d);
	return (A|B);
}

int main()
{
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	unsigned int n;
	int d;
	cin >> n >> d;
	cout << leftRotateBits(n,d) << "\n";
	cout << rightRotateBits(n,d);
	return 0;

}