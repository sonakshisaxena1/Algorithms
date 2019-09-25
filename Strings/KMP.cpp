#include<bits/stdc++.h>
using namespace std;
int ans = 0;
void KMP(string txt, string pat)
{
    int m = pat.size();
    int len = 0;
    int lps[m];
    lps[0] = 0;
    int i = 1;
    while(i < m)
    {
        if(pat[len] == pat[i])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if(len != 0)
            {
                len = lps[len-1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }

    int j = 0;
    i = 0;
    int n = txt.size();
    while(i < n)
    {

        if(j < m && txt[i] == pat[j])
        {
            i++;
            j++;
        }
        if(j == m)
        {
            cout << "Found pattern at: " << i-j << "\n";
            ans++;
        }
        else if(i < n && (txt[i] != pat[j]))
        {
            if(j != 0)
                j = lps[j-1];
            else
                i++;
        }

    }
}

int main()
 {
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
     string txt, pat;
     cin >> txt >> pat;
     KMP(txt, pat);
     cout << "Number of common occurrences: " << ans;
    return 0;
}