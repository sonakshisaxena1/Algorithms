//Trie implementation

#include<bits/stdc++.h>
using namespace std;
int adj[205][26];
int val[205];
int node_cnt = 1;
string s;
void insert(int node, int index)
{
    // val[node]++; --> number of strings passing through this node
    if(s.size() == index)
    {
        // val[node]++;  ---> number of strings ending at this node
        return;
    }
    int c = s[index] - 'a';
    if(adj[node][c] == 0)
    {
        adj[node][c] = node_cnt;
        node_cnt++;
    }
    insert(adj[node][c], index + 1);
}
int main()
{
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> s;
        insert(0, 0);
    }
    return 0;

}