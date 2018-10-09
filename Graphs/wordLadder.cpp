//Given a dictionary, and two words ‘start’ and ‘target’ (both of same length). Find length of the smallest chain from ‘start’ to ‘target’ if it exists, such that adjacent words in the chain only differ by one character and each word in the chain is a valid word i.e., it exists in the dictionary. It may be assumed that the ‘target’ word exists in dictionary and length of all dictionary words is same.
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
typedef pair<string, int> psi;
vector<string>word;

bool isAdjacent(string a, string b)
{
    int count_diff = 0;
    for(int i = 0; i < a.length(); i++)
    {
        if(a[i] != b[i])
            count_diff++;
    }
    return (count_diff == 1);
}
int shortestChainLength(string start, string end)
{
    unordered_map<string, int> distance;
    sort(word.begin(), word.end());
    queue<string> q;
    q.push(start);
    distance[start] = 1;
    while(!q.empty())
    {
        string a = q.front();
        q.pop();
        if(a == end)
            break;
        for(int i = 0; i < word.size(); i++)
        {
            if(isAdjacent(a, word[i]))
            {
                q.push(word[i]);
                distance[word[i]] = distance[a] + 1;
            }
        } 
    }
    if(distance.find(end) == distance.end())
        return 0;
    return distance[end];
}

int main()
{
    freopen("in.in", "r",stdin);
    freopen("test.out", "w", stdout);
    int k;
    cin >> k;
    for(int i = 0; i < k; i++)
    {
        string s;
        cin >> s;
        word.push_back(s);
    }
    string start, end;
    cin >> start >> end;

    cout << shortestChainLength(start, end);
    return 0;
    
}