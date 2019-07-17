#include <bits/stdc++.h>

using namespace std;

int main()
{
    int m, n, k;
    cin>>m>>n>>k;
    vector<vector<int>> p(m+1, vector<int>(n+1, 0));
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
            cin>>p[i][j];
    int cost = 0, ci = 0, cj = 0, ans = 0;
    while(true){
        int val = 0, mi = 0, mj = 0;
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++)
                if(val < p[i][j]){val = p[i][j]; mi = i; mj = j;}
        if(ci == 0) cj = mj;
        if(val == 0) break;
        if(cost+mi+abs(ci-mi)+abs(cj-mj)+1 <= k) {
            ans += val;cost += abs(ci-mi)+abs(cj-mj)+1;p[mi][mj] = 0;
            ci = mi;cj = mj;
        }
        else break;
    }
    cout<<ans<<endl;
    return 0;
}
