#include<bits/stdc++.h>
using namespace std;
vector<int> a;

int swap(unsigned int n)
{
	unsigned even_bits = n & 0xAAAAAAAA;
	unsigned odd_bits = n & 0x55555555;
	even_bits >>= 1;
	odd_bits <<= 1;
	return (even_bits | odd_bits);
}

int main()
{
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	unsigned int n;
	cin >> n;
	cout << swap(n);
	return 0;

}