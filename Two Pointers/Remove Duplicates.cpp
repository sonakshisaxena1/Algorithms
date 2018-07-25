#include<bits/stdc++.h>
using namespace std;

vector<int> A;
int count()
{
    if(A.size() == 0)
      return A.size();
  
    int k = 0;
    for(int i = 1; i < A.size(); i++)
    {
        if(A[k] != A[i])
        {
            A[k+1] = A[i];
            k++;
        }
    }
    
    A.erase(A.begin() + k + 1, A.end());
    return k+1;

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

  cout << count();

  return 0;
}