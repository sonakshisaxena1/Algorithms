/*
Find the smallest positive integer value that cannot be represented as sum of any subset of a given array
Given a sorted array (sorted in non-decreasing order) of positive numbers, find the smallest positive integer value that cannot be represented as sum of elements of any subset of given set. 
Expected time complexity is O(n). */

#include<bits/stdc++.h>
using namespace std;
vector<int>a;
int smallestValue()
{
	int result = 1;
	for(int i = 0; i < a.size() && a[i] <= result; i++)
			result += a[i];
	return result;	
}

int main()
{
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	int n;
	cin >> n;
	for(int i =0; i < n; i++)
	{
		int x;
		cin >> x;
		a.push_back(x);
	}
	cout << smallestValue();
	
	return 0;
}
