//Keeping atmost two occurrences of each element in a sorted array
#include<bits/stdc++.h>
using namespace std;

vector<int> A;

int count()
{
  int count = 0;
    int n = A.size();
    for (int i = 0; i < n; i++) 
    { 
        if (i < n - 2 && A[i] == A[i+1] && A[i] == A[i+2]) 
            continue;
        else {
            A[count] = A[i];
            count++;
        }
    }
    return count;
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