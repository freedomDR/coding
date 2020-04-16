#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e5+5;

inline int ls(int p) {return p<<1;}
inline int rs(int p) {return p<<1|1;}

long long arr[maxn*4], a[maxn], tag[maxn*4];
int n, m;

void update(int p)
{
    arr[p] = arr[ls(p)]+arr[rs(p)];
}

void down(int p, int l, int r)
{
    int mid = (l+r)>>1;
    tag[ls(p)] += tag[p];
    arr[ls(p)] += tag[p]*(mid-l+1);
    tag[rs(p)] += tag[p];
    arr[rs(p)] += tag[p]*(r-mid-1+1);
    tag[p] = 0;
}

void build(int p, int l, int r)
{
    if(l == r) {arr[p] = a[l];return;}
    int mid = (l+r)>>1;
    build(ls(p), l, mid);
    build(rs(p), mid+1, r);
    update(p);
}

void change(int p, int l, int r, int cl, int cr, int v)
{
    if(cl<=l&&r<=cr)
    {
        arr[p] += v*(r-l+1);
        tag[p] += v;
        return;
    }
    int mid = (l+r)>>1;
    down(p, l, r);
    if(cl<=mid) change(ls(p), l, mid, cl, cr, v);
    if(cr>mid) change(rs(p), mid+1, r, cl, cr, v);
    update(p);
}

long long query(int p, int l, int r, int ql, int qr)
{
    long long ret = 0;
    if(ql<=l&&r<=qr) {return arr[p];}
    int mid = (l+r)>>1;
    down(p, l, r);
    if(ql<=mid) ret += query(ls(p), l, mid, ql, qr);
    if(qr>mid) ret += query(rs(p), mid+1, r, ql, qr);
    return ret;
}
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    while(m--)
    {
        int op, x, y, k;
        cin >> op;
        if(op==1)
        {
            cin >> x >> y >> k;
            change(1, 1, n, x, y, k);
        }else
        {
            cin >> x >> y;
            cout << query(1, 1, n, x, y) << endl;
        }
    }
    return 0;
}