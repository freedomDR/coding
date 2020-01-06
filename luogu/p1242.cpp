#include <bits/stdc++.h>
using namespace std;

const int MAXN = 46;
int init[MAXN], ret[MAXN], cur[MAXN];
int n, can_log;

void dfs(int pos, int from, int to, int &cnts)
{
    for(int i = pos-1; i > 0; i--)
        if(cur[i] != 6-from-to) dfs(i, cur[i], 6-from-to, cnts);
    cnts++;
    cur[pos] = to;
    if(can_log)
        cout << "move " << pos << " from " << char(from+'A'-1) << " to " << char(to+'A'-1) << endl;
}

int calc(int opt)
{
    memcpy(cur, init, sizeof(init));
    int cnts = 0;
    switch(opt)
    {
        case 1:
            for(int i = n; i > 0; i--)
                if(cur[i] != ret[i]) dfs(i, cur[i], ret[i], cnts);
            break;
        case 2:
            for(int i = n-1; i > 0; i--)
                if(cur[i] != ret[n]) dfs(i , cur[i], ret[n], cnts);
            dfs(n, init[n], 6-init[n]-ret[n], cnts);
            for(int i = n-1; i > 0; i--)
                if(cur[i] != init[n]) dfs(i, cur[i], init[n], cnts);
            dfs(n, 6-init[n]-ret[n], ret[n], cnts);
            for(int i = n-1; i > 0; i--)
                if(cur[i] != ret[i]) dfs(i, cur[i], ret[i], cnts);
            break;
    }
    return cnts;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= 3; i++)
    {
        int t; cin >> t;
        while(t--)
        {
            int v; cin >> v;
            init[v] = i;
        }
    }
    for(int i = 1; i <= 3; i++)
    {
        int t; cin >> t;
        while(t--)
        {
            int v; cin >> v;
            ret[v] = i;
        }
    }
    while(n > 0 && init[n]==ret[n]) n--;
    int cost1 = calc(1), cost2 = calc(2);
    int choice = (cost1<cost2?1:2);
    can_log = 1;
    cout << calc(choice) << endl;
    return 0;
}
