//Given an array ‘A’ of sorted integers and another non negative integer k, 
//find if there exists 2 indices i and j such that A[i] - A[j] = k, i != j.
#include<bits/stdc++.h>
using namespace std;

vector<int> A;
int count(int B)
{
  int i = 0; 
  int j = 0;
  while(j < A.size() && i < A.size() )
  {
    
    if(i == j)
    {
      j++;
      continue;
    }

    if(A[j] - A[i] < B )
     j++;
    else if (A[j] - A[i] > B)
      i++;
    else  
      return 1;
  }
  return 0;

}
int main()
{
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
  
  
  int n;
  int k;

  cin >> n >> k;
  for(int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    A.push_back(x);
  }


 

  
 cout << count(k);
  //cout << "x";
  
  return 0;
}