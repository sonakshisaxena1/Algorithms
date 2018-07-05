#include<bits/stdc++.h>
using namespace std;

int val(char c)
{
	if(c >= '0' && c <= '9')
		return(int)c -'0';
	else
		return (int)c - 'A' + 10;
}
int toDecimal(string s, int base)
{
	int number = 0;
	int power = 1 ;
	int len = s.size();
	for(int i = len - 1 ; i >=0 ; i--)
	{
		if(val(s[i]) >= base)
			{
				cout << "invalid base";
				return -1;
			}
		
		number = number + val(s[i])*power;
		power = power * base;


	}

	return number;

}
int main()
{
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	string num;
	int base;
	cin >> num >> base;
	cout << "The number in decimal base is: "<<toDecimal(num,base);
	return 0; 
}