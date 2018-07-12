#include<bits/stdc++.h>
#include<unordered_map>
#define ll long long
using namespace std;

vector <int> small(vector<int> A, int B)
{
	vector<int> ans;
	if(B >= A.size())
	{
		int temp = A[0];
		for(int i = 0; i < A.size(); i++)
			temp = max(temp, A[i]);
		ans.push_back(temp);
		return ans;
	}

    deque<int> q;
    for(int i = 0 ; i < B; i++)
    {
    	while(!q.empty() && A[q.back()] <= A[i])
    		q.pop_back();
    	q.push_back(i);

    }

    ans.push_back(A[q.front()]);

    for(int i = B; i < A.size(); i++)
    {
    	while(!q.empty() && A[q.back()] <= A[i])
    		q.pop_back();
    	q.push_back(i);
    	while(!q.empty() && q.front() + B <= i)
    		q.pop_front();
    	ans.push_back(A[q.front()]);
    }
    return ans;
}

int main()
{
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	vector<int> A;
	int s;
	cin >> s;
	int B;
	cin >> B;
	for(int i = 0; i < s; i++)
		{
			int x;
			cin >> x;
			A.push_back(x);
		}

	vector<int> v;
	v = small(A, B);

	for(int i = 0; i < v.size() ; i++)
		{
			 cout << v[i] << " ";
		}
	return 0;
}