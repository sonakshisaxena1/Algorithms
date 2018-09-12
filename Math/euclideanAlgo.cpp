#include<bits/stdc++.h>
using namespace std;
//Recursive Euclidean
int gcd(int a, int b)
{
	if(a == 0)
		return b;
	return gcd(a % b, a);
}


int main()
{
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	int a, b;
	cin >> a >> b;
	if(a >= b)
		cout << gcd(a,b);
	else
		cout << gcd(b,a);
	return 0;

}