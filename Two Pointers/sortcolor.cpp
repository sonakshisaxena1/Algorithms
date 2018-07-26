//Sorting by color where the order is red blue white
//0 => red 
//1=> blue 
//2 =>white

#include<bits/stdc++.h>
using namespace std;

vector<int> A;
void count()
{
  if(A.size() == 0)
    return;
  int i = 0;
  int B = 2;
  for(int j = 0; j < A.size(); j++)
  {
    if(A[j] != B)
    {
      int temp = A[i];
      A[i] = A[j];
      A[j] = temp;
      i++;
    }
  }


  B--;
  int k = 0;
  for(int j = 0; j < i; j++)
  {
    if(A[j] != B)
    {
      int temp = A[k];
      A[k] = A[j];
      A[j] = temp;
      k++;
    }
  }
  
  B--;
  i = 0;
  for(int j = 0; j < k; j++)
  {
    if(A[j] != B)
    {
      int temp = A[i];
      A[i] = A[j];
      A[j] = temp;
      i++;
    }
  }

}

int main()
{
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
  
  
  int n;
  int k;

  cin >> n;
  for(int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    A.push_back(x);
  }

  count();
  for(int i = 0; i < n; i++)
  {
    cout << A[i] << " ";
  }
  

  return 0;
}