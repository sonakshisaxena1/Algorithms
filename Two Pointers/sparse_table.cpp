#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
vector<int>A;
int tab[100005][20];

void pre()
{
  for(int i = 0; i<A.size(); i++)
    tab[i][0] = A[i];
  for(int j = 0; (1<<j) <= A.size(); j++)
    for(int i = 0; i<A.size(); i++)
      tab[i][j] = max(tab[i][j-1], tab[i+(1<<(j-1))][j-1]);
}

int query(int l, int r)
{
  // l = 1, r = 5;
  int x = log2(r-l+1);
  // x = 2
  // tab[l][x] -> max 1 to 4
  // tab[r-(1<<x)+1][x] max 2 to 5
  
  return max(tab[l][x], tab[r-(1<<x)+1][x]);
}