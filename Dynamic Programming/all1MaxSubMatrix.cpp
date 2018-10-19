//Max Rectangular SubMatrix with all 1s in a binary matrix
#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int> > &v)
{
    int n = v.size();
    int m = v[0].size();
    int ans = 0;
    for(int i = 1; i<=n; i++)
    {
        for(int r = 0; r<(n-i+1); r++)
        {
            int pt1 = 0, pt2 = 1;
            while(pt1 < m && pt2 < m)
            {
                while(pt1 < m && v[r][pt1] == 0)
                    pt1++;
                if(pt1 == m)
                    break;
                pt2 = pt1 + 1;
                while(pt2 < m && v[r][pt2] == 1)
                    pt2++;
                ans = max(ans, (pt2 - pt1)*i);
                pt1 = pt2;
            }
        }
        if(i == n)
            break;

        for(int r = 0; r<(n-i); r++)
            for(int c = 0; c<m; c++)
                v[r][c] &= v[r+1][c];
    }
    return ans;
}

int main()
{
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<vector<int> > v(n);
    for(int i = 0; i<n; i++)
    {
        v[i].resize(m);
        for(int j = 0; j<m; j++)
            cin >> v[i][j];
    }
    cout << solve(v) << "\n";

    return 0;

}