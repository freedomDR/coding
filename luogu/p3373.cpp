#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e5+5;
int n, m, mod;
inline int ls(int p) {return p<<1;}
inline int rs(int p) {return p<<1|1;}
long long arr[maxn*4], a[maxn], tag1[maxn*4], tag2[maxn*4];

void update(int p)
{
    arr[p] = arr[ls(p)]+arr[rs(p)];
}

void down(int p, int l, int r)
{
    int mid = (l+r)/2;
    arr[ls(p)] = (arr[ls(p)]*tag2[p]+(mid-l+1)*tag1[p])%mod;
    arr[rs(p)] = (arr[rs(p)]*tag2[p]+(r-mid)*tag1[p])%mod;
    tag2[ls(p)] = (tag2[ls(p)]*tag2[p])%mod;
    tag2[rs(p)] = (tag2[rs(p)]*tag2[p])%mod;
    tag1[ls(p)] = (tag1[ls(p)]*tag2[p]+tag1[p])%mod;
    tag1[rs(p)] = (tag1[rs(p)]*tag2[p]+tag1[p])%mod;
    tag1[p] = 0;
    tag2[p] = 1;
}

void build(int p, int l, int r)
{
    tag2[p] = 1;
    if(l==r) {arr[p] = a[l];return;}
    int mid = (l+r)>>1;
    build(ls(p), l, mid);
    build(rs(p), mid+1, r);
    update(p);
}

void change(int p, int l, int r, int cl, int cr, int v, int op)
{
    if(cl<=l&&r<=cr)
    {
        if(op == 1)
        {
            arr[p] = (arr[p]*v)%mod;
            tag2[p] = (tag2[p]*v)%mod;
            tag1[p] = (tag1[p]*v)%mod;
        }else
        {
            arr[p] = (arr[p]+v*(r-l+1)%mod)%mod;
            tag1[p] = (tag1[p]+v)%mod;
        }
        return; 
    }
    down(p, l, r);
    int mid = (l+r)>>1;
    if(cl<=mid) change(ls(p), l, mid, cl, cr, v, op);
    if(cr>mid) change(rs(p), mid+1, r, cl, cr, v, op);
    update(p);
}

long long query(int p, int l, int r, int ql, int qr)
{
    long long ret = 0;
    if(ql<=l&&r<=qr) return arr[p];
    int mid = (l+r)>>1;
    down(p, l, r);
    if(ql<=mid) ret = (ret+query(ls(p), l, mid, ql, qr))%mod;
    if(qr>mid) ret = (ret+query(rs(p), mid+1, r, ql, qr))%mod;
    return ret;
}

int main()
{
    cin >> n >> m >> mod;
    for(int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    while(m--)
    {
        int op, x, y, k;
        cin >> op;
        if(op == 3)
        {
            cin >> x >> y;
            cout << query(1, 1, n, x, y) << endl;
        }else
        {
            cin >> x >> y >> k;
            change(1, 1, n, x, y, k, op);
        }
    }
    return 0;
}