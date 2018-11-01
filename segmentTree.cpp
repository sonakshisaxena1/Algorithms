#include<bits/stdc++.h>
using namespace std;
vector<int>wt;
vector<int>v;
int N;
int tree[4*N];

void build(int left, int right, int sum)
{
    if(left == right)
    {
        tree[left] = sum;
        return;
    }

    mid = (left + right)/2;
    build(left, mid, );
    build(mid+1, right);
    tree[node] = tree[left] + tree[right];
}
int main()
{

    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    int n;
    cin >> n >> W;
    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        wt.push_back(a);
        v.push_back(b);
    }
    cout << knapsack();
    return 0;
}