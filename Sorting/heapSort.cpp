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

void heapify(int i, int n)
{
    int largest = i;
    if(2*i < n && a[2*i] > a[i])
        largest = 2*i;
    if(2*i + 1 < n && a[2*i + 1] > a[i])
         largest = 2*i + 1;
     if(largest != i)
     {
        swap(a[i], a[largest]);
        heapify(largest, n);
     }
}
void build(int k, int n)
{
    for(int i = n/2; i >= 0; i--)
    {
        heapify(i, n);
    }

    for(int i = n-1; i >= 0; i--)
    {
        // cout << a[0] << " ";
        swap(a[i], a[0]);
        heapify(0, i);

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

    build(n, n);
    for(int i =  0; i < n; i++)
    cout << a[i] << " ";
   
    // cout << findCelebrity(2);
    return 0;


}