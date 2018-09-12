#include<bits/stdc++.h>
using namespace std;
//A magic number is defined as a number which can be expressed as a power of 5 or sum of unique powers of 5.
int magicNumber(int n)
{
	int pow = 1, answer = 0;
	while(n)
	{
		pow *= 5;
		if(n & 1)
			answer += pow;
		n >>= 1;
	}
	return answer;
}

int main()
{
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	int n;
	cin >> n;
	cout << magicNumber(n);
	return 0;

}