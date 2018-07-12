#include<bits/stdc++.h>
#include<unordered_map>
#define ll long long
using namespace std;

int largest(vector<string> v)
{
	stack <int> s;
	for(int i = 0 ; i < v.size(); i++)
	{
		if(v[i] == "+")
		{
			
			if(!s.empty())
			{
				int x = s.top();
				s.pop();
				x = s.top() + x;
				s.pop();
				s.push(x);
				//cout << x;
			}

		}

		else if(v[i] == "-")
		{
			if(!s.empty())
			{
				int x = s.top();
				s.pop();
				x = s.top() - x;
				s.pop();
				s.push(x);
				//cout << x;
			}

		}

		else if(v[i] == "*")
		{
			if(!s.empty())
			{
				int x = s.top();
				s.pop();
				x = s.top()*x;
				s.pop();
				s.push(x);
				//cout << x;
			}

		}

		else if(v[i] == "/")
		{
			if(!s.empty())
			{
				int x = s.top();
				s.pop();
				x = s.top()/x;
				s.pop();
				s.push(x);
				//cout << x;
			}

		}

		else
			{

				s.push(stoi(v[i]));
			}

		if(s.empty())
			return 0;

 
	}

	return s.top();
}

int main()
{
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	
	vector<string> v;
	int size;
	cin >> size;
	for(int i = 0; i < size; i++)
		{
			string x;
			cin >> x;
			v.push_back(x);
		}

	cout << largest(v);

}