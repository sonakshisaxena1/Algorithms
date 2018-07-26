//Removal of all the occurrences of an element in the array and
//returning the size irrespective of its content

#include<bits/stdc++.h>
using namespace std;

vector<int> A;
int count(int B)
{
  if(A.size() == 0)
    return 0;
  int i = 0;
  for(int j = 0; j < A.size(); j++)
  {
    if(A[j] != B)
    {
      A[i] = A[j];
      i++;
    }
  }

  if(i < A.size())
  {
    A.erase(A.begin() + i, A.end());
    
  }
  return A.size();

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

  return 0;
}