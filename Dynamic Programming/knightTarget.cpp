//Reach a target using a knight
#include <bits/stdc++.h>
using namespace std;
vector<int>A;

int solve(int startx, int starty, int endx, int endy, int n)
{   
    int dx[8] = {1, -1, 2, -2, 1, -1, 2, -2};
    int dy[8] = {2, -2, 1, -1, -2, 2, -1, 1};
    int dist[n+1][n+1];
    memset(dist, 1000000, sizeof(dist));
    bool visited[n+1][n+1];
    memset(visited, false, sizeof(visited));
    queue< pair <int, int > > q;
    while(!q.empty())
        q.pop();
    q.push(make_pair(startx, starty));
    dist[startx][starty] = 0;
    int x, y;
    while(!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        // cout << x << " " << y << " " << dist[x][y] << "\n";
        
        if(visited[x][y])
            continue;

        visited[x][y] = true;
        for(int i = 0; i < 8; i++)
        {
            int neighx = x + dx[i];
            int neighy = y + dy[i];
            if(neighx < 1 || neighx > n || neighy < 1 || neighy > n)
                continue;
            dist[neighx][neighy] = min(dist[neighx][neighy], dist[x][y] + 1);
            q.push(make_pair(neighx,neighy));
        }
    }

    return dist[endx][endy];
}

int main()
{
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);

    int n;
    cin >> n;
    int a, b, c, d;
    cin >> a >> b >>c >> d;
    cout << solve(a, b, c, d, n);

    return 0;

}