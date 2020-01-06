#include <bits/stdc++.h>
using namespace std;

int go[4][35];
long long cost[4][35];
int main()
{
    int n; cin >> n;
    for(int i = 0; i < 6; i++)
    {
        string s; cin >> s;
        int from = s[0]-'A'+1, to = s[1]-'A'+1;
        if(go[from][1] == 0)
        {
            go[from][1] = to;
            cost[from][1] = 1;    
        }
    }
    for(int i = 2; i <= n; i++)
    {
        for(int j = 1; j <= 3; j++)
        {
            int x = go[j][i-1], z = 6-j-x;
            if(go[x][i-1] == z)
            {
                cost[j][i] = cost[j][i-1]+1+cost[x][i-1];
                go[j][i] = z;
            }else if(go[x][i-1] == j)
            {
                cost[j][i] = cost[j][i-1]+1+cost[x][i-1]+1+cost[j][i-1];
                go[j][i] = x;
            }
        }
    }
    cout << cost[1][n] << endl;
    return 0;
}
