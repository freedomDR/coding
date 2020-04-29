#include<bits/stdc++.h>

using namespace std;
const int maxn = 1e5+5;
int n, m, a[maxn];
int st[maxn][18];
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (!isdigit(ch)){if (ch=='-') f=-1;ch=getchar();}
	while (isdigit(ch)){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int query(int l, int r)
{
    int k = log2(r-l+1);
    return max(st[l][k], st[r-(1<<k)+1][k]);
}
int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cin >> n >> m;
    // scanf("%d %d", &n, &m);
    n = read(); m = read();
    for(int i = 1; i <= n; i++)
    {
        // cin >> a[i];
        // scanf("%d", &a[i]);
        a[i] = read();
        st[i][0] = a[i];
    }
    for(int j = 1; j < 18; j++)
    {
        for(int i = 1; i+(1<<j)-1 <= n; i++)
        {
            st[i][j] = max(st[i][j-1], st[i+(1<<(j-1))][j-1]);
        }
    }
    while(m--)
    {
        // int l, r; cin >> l >> r;
        // int l, r; scanf("%d %d", &l, &r);
        int l, r; l = read(); r = read();
        printf("%d\n", query(l, r));
        // cout << query(l, r) << endl;
    }
    return 0;
}