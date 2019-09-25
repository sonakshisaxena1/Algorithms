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
void merge(int l, int mid, int h)
{
    
    int n1 = mid-l+1;
    int n2 = h-mid;
    int L[n1], R[n2];
    for(int i = 0 ;i < n1; i++)
        L[i] = a[l+i];
    for(int j = 0; j < n2; j++)
        R[j] = a[mid+1+j];

    int i = 0;
    int j = 0;
    int k = l;
    while(i < n1 & j < n2)
    {
        if(L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }

    while(j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int l, int h)
{
    if(l < h)
    {
        int mid = l + (h-l)/2;
        mergeSort(l , mid);
        mergeSort(mid+1, h);
        merge(l, mid, h);
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

    mergeSort(0, n-1);
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    // cout << findCelebrity(2);
    return 0;


}