#include<bits/stdc++.h>
using namespace std;
vector<int>A;

int count(int B)
{

  sort(A.begin(), A.end());
  int minDiff = INT_MAX;
  int sum = 0;
  int i = 0;
  
  while(i < A.size() - 2)
  {
    int left = i + 1;
    int right = A.size() - 1;

    while(right > left)
    {
      int curr = A[i] + A[left] + A[right];
      int diff = abs(curr - B);
      if(diff == 0)
        return B;

      
      if(diff < minDiff)
      {
        minDiff = diff;
        sum = curr;
      }

      if(curr < B)
        left++;
      else
        right--;

    }
    i++;

  }
  return sum;
}

int main()
{

  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
  int n >> B;
  cin >> n >> B;
  for(int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    A.push_back(x);
  }

  cout << sum(B);

  return 0;
}