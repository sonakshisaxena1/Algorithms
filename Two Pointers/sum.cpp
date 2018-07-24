//Given an array A of integers and another non negative integer k, find if there exists 2 indices i and j such that A[i] - A[j] = k, i != j.

#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
vector<int>A;

int count(int k)
{
  int i = 0;
  int j = A.size() - 1;
  int ans = 0;
  while(i < A.size())
  { 
    while(j >= 0 && A[i] + A[j] > k)
     {
       j--;
     }
    ans += A.size() - j - 1;
    i++;
  }

  return ans;
}

int main()
{
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
  
  
  int n, k;
  cin >> n >> k;
  for(int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    A.push_back(x);
  }
  sort(A.begin(), A.end());

  cout << count(k);
  return 0;
}