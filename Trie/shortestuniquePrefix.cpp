//Shortest unique Prefix

#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
int adj[205][26];
int val[205];
int node_cnt = 1;
vector<string> t;
string s;
vector<string> A;
void insert(int node, int index)
{
    val[node]++;
    if(s.size() == index)
        return;
    int c = s[index] - 'a';
    if(adj[node][c] == 0)
    {
        adj[node][c] = node_cnt;
        node_cnt++;
    }
    insert(adj[node][c], index + 1);
}

void printPrefix(int node, int index)
{
   
    string ans = "";
    if(val[adj[node][s[index] - 'a']] == 1)
    {
        ans += s[index];
        t.push_back(ans);
        return;
    }
    ans = "";
    while(val[adj[node][ s[index] - 'a']] != 1)
    {
        ans += s[index];
        node = adj[node][s[index] - 'a'];
        index++;
    }
    ans += s[index];
    t.push_back(ans);
    
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
        A.push_back(s);
        insert(0, 0);
    }
    for(int i = 0; i < A.size(); i++)
    {
        s = A[i];
        printPrefix(0, 0);
    }
    for(int i =0; i < t.size(); i++)
        cout << t[i] << " ";
    return 0;

}