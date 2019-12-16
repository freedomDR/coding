#include <bits/stdc++.h>
using namespace std;

void dfs(int &ans, int a, int b, int c, int p)
{
    if(p == 4)
    {
        ans = min(ans, abs(a-b)+abs(b-c)+abs(a-c));
        return;
    }
    if(p == 1)
    {
        dfs(ans, a,b,c,p+1);
        dfs(ans, a-1,b,c,p+1);
        dfs(ans, a+1,b,c,p+1);
    }else if(p == 2)
    {
        dfs(ans, a, b, c, p+1);
        dfs(ans, a, b-1, c, p+1);
        dfs(ans, a, b+1, c, p+1);
    }else
    {
        dfs(ans, a, b, c, p+1);
        dfs(ans, a, b, c+1, p+1);
        dfs(ans, a, b, c-1, p+1);
    }
}

int main()
{
    int q; cin >> q;
    while(q--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int ans = INT_MAX;
        vector<int> add = {1,-1,0};
        dfs(ans, a, b, c, 1);
        cout << ans << endl;
    }
    return 0;
}
