#include<bits/stdc++.h>
using namespace std;

char resValue(int input)
{
	char result;
	if(input >=0 && input <= 9)
		result = (char)(input + '0');
	else
		result = (char)(input - 10 + 'A');

	return result;
}

void strev(char *str)
{
    int len = strlen(str);
    int i;
    for (i = 0; i < len/2; i++)
    {
        char temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }
}


char* toBase(int n, int b, char res[])
{
	int index = 0;
	while(n>0)
	{
		res[index] = resValue(n % b);
		n /= b;
		index++;
	}

	res[index] ='\0';
	strev(res);
	return res;
}
int main()
{
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	int n;
	int base;
	cin >> n >> base;
	char res[200];
	cout << "The number in base " << base << " is: " <<toBase(n, base, res);
	return 0;
}