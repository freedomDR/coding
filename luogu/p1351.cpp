#include<bits/stdc++.h>

using namespace std;

const int mod = 10007;
const int maxn = 200005;
int ans, v[maxn], n, nxt[maxn*2], to[maxn*2], head[maxn], cnt, sums;

void addEdge(int uu, int vv)
{
    nxt[++cnt] = head[uu];
    to[cnt] = vv;
    head[uu] = cnt;
}

void dfs(int p, int fa, int maxv)
{
    int max1 = 0, max2 = 0, temp = 0, sub = 0;
    for(int i = head[p]; i; i = nxt[i])
    {
        int vv = to[i];
        if(vv == fa) continue;
        temp = (temp+v[vv])%mod;
        sub = (sub+v[vv]*v[vv]%mod)%mod;
        if(v[vv] > max1) max2 = max1, max1 = v[vv];
        else if(v[vv] > max2) max2 = v[vv];
        dfs(vv, p, v[fa]);
    }
    ans = max(ans, max(v[p]*maxv, max1*max2));
    sums = (sums+(temp*temp%mod-sub+mod)%mod+maxv*v[p]*2%mod)%mod;
}

int main()
{
    // freopen("P1351_2.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i < n; i++)
    {
        int uu, vv;
        cin >> uu >> vv;
        addEdge(uu, vv);
        addEdge(vv, uu);
    }
    for(int i = 1; i <= n; i++) cin >> v[i];
    dfs(1, 0, 0);
    cout << ans << " " << sums << endl;
    return 0;
}