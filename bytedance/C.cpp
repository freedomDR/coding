#include<bits/stdc++.h>
using namespace std;
int d[1000];
int g[1000][1000], n, ans[1100];

void sort()
{
    int i, j, k, sums = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(d[j]==0)
            {
                d[j]--;
                k = j;
                ans[sums++] = j;
                break;
            }
        }
        for(j = 1; j <= n; j++)
        {
            if(g[j][k] == 1)
            {
                g[j][k] == 0;
                d[j]--;
            }
        }
    }
    if(sums == n)
    {
        for(i = 0; i < n; i++)
            cout << ans[i] << " ";
        cout << endl;
    }
    else
    {
        cout << "-1" << endl;
    }
}

int main()
{
    string s;
    while(getline(cin, s))
    {
        int l = 0, cur = -1;
        s += " ";
        while(1)
        {
            if(s.find(" ", l) == string::npos) break;
            int r = s.find(" ", l);
            int v = atoi(s.substr(l,r-l).c_str());
            if(cur == -1) cur = v;
            else
            {
                g[cur][v] = 1;
                d[cur]++;
            }
            l = r+1;
        }
        n++;
    }
    sort();
    return 0;
}
