//Find the element before which all the elements are smaller than it, and after which all are greater
#include<bits/stdc++.h>
using namespace std;
int main()
 {
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    int t;
    cin >> t;
    while(t > 0)
    {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int leftMax[n], ans = -1;
    leftMax[0] = a[0];
    for(int i = 1; i < n; i++)
        leftMax[i] = max(leftMax[i-1], a[i]);

    int rightMin[n];
    rightMin[n-1] = a[n-1];
    for(int i = n-2; i >= 0; i--)
        rightMin[i] = min(rightMin[i+1], a[i]);
    
    for(int i = n-2; i >= 0; i--)
        if(a[i] >= leftMax[i] && a[i] <= rightMin[i])
        {
            ans = a[i];
            break;
        }
      


    if(ans != -1)
        cout << ans << "\n";
    else
        cout << "-1" << "\n";
    t--;
}
    return 0;
}