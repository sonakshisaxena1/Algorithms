//sort a stack using another stack

#include<bits/stdc++.h>
using namespace std;


int main()
{
	freopen("test.in","r",stdin);
	freopen("test.out", "w",stdout);
	stack<int>s;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		s.push(x);
	}

	stack<int> tempStack;
	int temp;
	while(!s.empty())
	{
		temp = s.top();
		s.pop();
		while(!tempStack.empty() && tempStack.top() > temp)
		{
			int x = tempStack.top();
			tempStack.pop();
			s.push(x);
		}
		tempStack.push(temp);
	}

	while(!tempStack.empty())
	{
		cout << tempStack.top() << " ";
		tempStack.pop();
	}
	return 0;

}