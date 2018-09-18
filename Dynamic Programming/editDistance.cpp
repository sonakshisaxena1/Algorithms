#include<bits/stdc++.h>
using namespace std;

int editDistance(string a, string b)
{
    if(b.length() == 0)
        return a.length();
    if(a.length() == 0)
        return b.length();
    int D[a.length()][b.length()];
    for(int i = 0; i < a.length(); i++)
    {
        for(int j = 0; j < b.length(); j++)
        {
            if(i == 0)
                D[i][j] = j;
            else if(j == 0)
                D[i][j] = i;
            else if(a[i] == b[j])
                D[i][j] = D[i-1][j-1];
            else
                D[i][j] = min(min(D[i-1][j], D[i][j-1]), D[i-1][j-1]) + 1;

        }
    }
    return D[a.length()-1][b.length()-1];
}
int main()
{
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    string a, b;
    cin >> a >> b;
    cout << editDistance(a, b);
    return 0;
}