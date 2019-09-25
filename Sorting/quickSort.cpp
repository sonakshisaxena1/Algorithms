#include<bits/stdc++.h>
#define SIZE 55
#define ll long long
#define pii pair<int,int>
using namespace std;
const int mod = 1000000007;
int coins[SIZE];
int dx[8] = {0, 0, -1, 1, -1, 1, 1, -1};
int dy[8] = {-1, 1, 0, 0, -1, -1, 1, 1};

vector<int>a;
int partition(int l,  int h)
{
    int i = l-1;
    int p = a[h];
    for(int j = l; j < h; j++)
    {
        if(a[j] <= p)
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    i++;
    swap(a[i], a[h]);
    return i;
}
void quick(int l, int h)
{
    if(l < h)
    {
        int p = partition(l,h);
        quick(l, p-1);
        quick(p+1, h);
    }
}
int main()
{     
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    a.clear();
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }

    quick(0, n-1);
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    // cout << findCelebrity(2);
    return 0;


}