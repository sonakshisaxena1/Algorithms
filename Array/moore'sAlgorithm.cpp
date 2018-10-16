//Moore's Algorithm
//Finding majority element if exists in an array
//Time: O(n) Space: O(1) 

#include<bits/stdc++.h>
using namespace std;
vector<int> a;

int findCandidate()
{
    int max_index = 0, count = 1;
    for(int i = 0; i < a.size(); i++)
    {
        if(a[max_index] == a[i])
            count++;
        else if (a[max_index] != a[i])
            count--;
        else if(count == 0)
        {
            max_index = i;
            count = 1;
        }
    }
    return max_index;
}

int isMajority()
{
    int index = findCandidate();
    int count = 0;
    for(int i = 0; i < a.size(); i++)
    {
        if(a[i] == a[index])
            count++;
    }

    if(count > (a.size()/2))
        return a[index];
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
    int y = isMajority();
    if(y == -1)
        cout << "No";
    else
        cout << y;
    

    return 0;
    
}