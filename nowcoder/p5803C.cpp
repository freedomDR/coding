#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5+5;
struct SegTree{
    int sum;
    int maxv;
    int gcd;
}tree[maxn<<2];
int a[maxn], n, m;
inline int ls(int p) {return p<<1;}
inline int rs(int p) {return p<<1|1;}

void pushup(int p)
{
    tree[p].sum = tree[ls(p)].sum+tree[rs(p)].sum;
    tree[p].gcd = __gcd(tree[ls(p)].gcd, tree[rs(p)].gcd);
    tree[p].maxv = max(tree[ls(p)].maxv, tree[rs(p)].maxv);
}

void build(int p, int l, int r)
{
    if(l == r) {tree[p].sum = a[l];tree[p].gcd = tree[p].maxv = abs(a[l]);return;}
    int mid = (l+r)/2;
    build(ls(p), l, mid);
    build(rs(p), mid+1, r);
    pushup(p);
}

//ul == ur
void update(int p, int l, int r, int ul, int ur, int x)
{
    if(ul<=l&&r<=ur)
    {
        a[ul]+=x;
        tree[p].sum = a[ul];
        tree[p].gcd = tree[p].maxv = abs(a[ul]);
        return;
    }
    int mid = (l+r)/2;
    if(ul<=mid) update(ls(p), l, mid, ul, ur, x);
    if(ur>mid) update(rs(p), mid+1, r, ul, ur, x);
    pushup(p);
}
int query_sum(int p, int l, int r, int ql, int qr)
{
    if(ql<=l&&r<=qr) return tree[p].sum;
    int mid = (l+r)/2;
    int ans = 0;
    if(ql<=mid) ans += query_sum(ls(p), l, mid, ql, qr);
    if(qr>mid) ans += query_sum(rs(p), mid+1, r, ql, qr);
    return ans;
}
int query_maxv(int p, int l, int r, int ql, int qr)
{
    if(ql<=l&&r<=qr) return tree[p].maxv;
    int mid = (l+r)/2;
    int ans = 0;
    if(ql<=mid) ans = max(ans, query_maxv(ls(p), l, mid, ql, qr));
    if(qr>mid) ans = max(ans, query_maxv(rs(p), mid+1, r, ql, qr));
    return ans;
}
int query_gcd(int p, int l, int r, int ql, int qr)
{
    if(ql<=l&&r<=qr) return tree[p].gcd;
    int mid = (l+r)/2;
    int ans = 0;
    if(ql<=mid) ans = __gcd(ans, query_gcd(ls(p), l, mid, ql, qr));
    if(qr>mid) ans = __gcd(ans, query_gcd(rs(p), mid+1, r, ql, qr));
    return ans;
}
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = n; i >= 1; i--) a[i] -=a[i-1];
    build(1, 1, n);
    for(int i = 1; i <= m; i++)
    {
        int op, l, r; cin >> op >> l >> r;
        if(op == 1)
        {
            int x; cin >> x;
            update(1, 1, n, l, l, x);
            if(r<n) update(1, 1, n, r+1, r+1, -x);
        }else if(op == 2)
        {
            if(l == r) cout << 0 << endl;
            else cout << query_maxv(1, 1, n, l+1, r) << endl;
        }else
        {
            int t = query_sum(1, 1, n, 1, l);
            if(l==r) cout << t << endl;
            else cout << __gcd(t, query_gcd(1, 1, n, l+1, r)) << endl;
        }
        
    }
    return 0;
}