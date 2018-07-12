#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("text.out", "w", stdout);
	string s = "Hi I am a coder";
	stringstream check1(s);
	string x;
	vector <string> v;
	while(getline(check1, x, ' ')){
		v.push_back(x);
	}

	for(int i = 0; i < v.size(); i++)
		cout << v[i] << endl;
	return 0;
}