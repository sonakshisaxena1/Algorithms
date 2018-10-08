//Given a number k, find the required minimum number of Fibonacci terms whose sum equal to k. We can choose a Fibonacci number multiple times.
#include<bits/stdc++.h>
using namespace std;
vector<int>f;

void findFibo(int k)
{
    int i = 3, nextTerm; 
    f.push_back(0); 
    f.push_back(1); 
    f.push_back(1); 

    while (1) 
    { 
        nextTerm = f[i - 1] + f[i - 2]; 
        if (nextTerm > k) 
            return; 
  
        f.push_back(nextTerm); 
        i++; 
    } 
    cout << f.size() << "\n";
}

int findMin(int k)
{
    findFibo(k);
    int i = f.size() - 1, count = 0;
    while(k > 0)
    {
        count += k/f[i];
        k %= f[i];
        i--;
    }
    return count;
}
int main()
{
    freopen("in.in", "r",stdin);
    freopen("test.out", "w", stdout);
    int k;
    cin >> k;
    cout << findMin(k);
    return 0;
}