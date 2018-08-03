/*Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.
*/

#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

string op(int A, int B)
{
	long long int num = A;
	long long int den = B;
	bool neg = false;
	if(num < 0 )
	{
		neg = true;
		num = 0 - num;
	}
	if(den < 0){
		if(neg)
			neg = false;
		else
			neg = true;
		den = 0 - den;
	}
	if(num == 0)
		return "0";

	long long int initial = num/den;
	string ans = "";
	num = num % den;
	if(neg)
		ans += "-";
	ans += to_string(initial);

	if(num == 0)
		return ans;

	ans += ".";
	
	int value;
	bool repeat = false;
	unordered_map<int, int> m;
	while(num != 0 && repeat != true)
	{
		num = num * 10;
		if(m.find(num) != m.end())
		{
			value = m[num];
			repeat = true;
			break;
		}
		else
		{
			m[num] = ans.size();
		}
		int temp = num/den;
		ans += to_string(temp);
		num = num % den;

	}

	if(repeat)
	{
		ans += ")";
		ans.insert(value, "(");
	}

	return ans;

}

int main()

{
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	double a, b;
	cin >> a >> b;
	cout << op(a, b);
	return 0;
}