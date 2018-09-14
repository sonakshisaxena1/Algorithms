#include<bits/stdc++.h>
using namespace std;
vector<int> a;

void binaryRepresentation(unsigned int n)
{
	if(n > 1)
		binaryRepresentation(n>>1);
	cout << (n&1);
}

int main()
{
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	unsigned int n;
	cin >> n;
	binaryRepresentation(n);
	return 0;

}