//prime set subsequences
#include<bits/stdc++.h>
using namespace std;

vector<int> solve(int A, int B, int C, int D)
{
	priority_queue<int, vector<int>, greater<int> > q;
	q.push(A);
	q.push(B);
	q.push(C);
	vector<int> v;
	
	while(v.size() != D)
	{
		int tp = q.pop();
		v.push_back(tp);
		q.push(tp*A);
		q.push(tp*B);
		q.push(tp*C);
	}
	return v;
}
int main()
{
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	int n;
	cin >> n;
	cout<< solve(n);
	return 0;
}
/*
int main()
{
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);`
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
			int x;
			cin >> x;
			A.push_back(x);
	}
	cout << solve() ;
	return 0;

}*/