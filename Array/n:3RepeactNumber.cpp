
//Finding  element if exists in an array more than n/3
//Time: O(n) Space: O(1) 

#include<bits/stdc++.h>
using namespace std;
vector<int> a;


int isNBy3()
{
    int count1 = 0, count2 = 0;
    int first = INT_MAX, second = INT_MAX;
    for(int i = 0; i < a.size(); i++)
    {
        if(a[i] == first)
            count1++;
        else if(a[i] == second)
            count2++;
        else if(count1 == 0)
        {
            count1++;
            first = a[i];
        }
        else if(count2 == 0)
        {
            count2++;
            second = a[i];
        }
        else
        {
            count1--;
            count2--;
        }
    }
    // cout << first << " " <<second <<" \n";
    count1 = 0;
    count2 = 0;
    for(int i = 0; i < a.size(); i++)
    {
        if(a[i] == first)
            count1++;
        else if(a[i] == second)
            count2++;
    }
     // cout << count1 << count2 << "\n";
    if(count1 > (a.size()/3))
        return first;
    else if(count2 > (a.size()/3))
        return second;
    else
        return -1;
}
int main()
{

    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    int n;
    cin >> n;
    for(int i =0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    int y = isNBy3();
    if(y == -1)
        cout << "No";
    else
        cout << y;
    

    return 0;
    
}