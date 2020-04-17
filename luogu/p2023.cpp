#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e5+5;
inline int ls(int p) {return p<<1;}
inline int rs(int p) {return p<<1|1;}
long long arr[maxn*4], a[maxn], add[maxn*4], mul[maxn*4];
int n, m, mod;
void update(int p)
{
    arr[p] = (arr[ls(p)]+arr[rs(p)])%mod;
}

void down(int p, int l, int r)
{
    int mid=(l+r)/2;
    arr[ls(p)] = (arr[ls(p)]*mul[p]+add[p]*(mid-l+1)%mod)%mod;
    arr[rs(p)] = (arr[rs(p)]*mul[p]+add[p]*(r-mid)%mod)%mod;
    add[ls(p)] = (add[ls(p)]*mul[p]+add[p])%mod;
    add[rs(p)] = (add[rs(p)]*mul[p]+add[p])%mod;
    mul[ls(p)] = (mul[ls(p)]*mul[p])%mod;
    mul[rs(p)] = (mul[rs(p)]*mul[p])%mod;
    mul[p] = 1;
    add[p] = 0;
}
void build(int p, int l, int r)
{
    mul[p] = 1;
    if(l==r) {arr[p]=a[l];return;}
    int mid = (l+r)/2;
    build(ls(p), l, mid);
    build(rs(p), mid+1, r);
    update(p);
}
void change(int p, int l, int r, int cl, int cr, int k, int op)
{
    if(cl<=l&&r<=cr)
    {
        if(op==1)
        {
            arr[p] = (arr[p]*k)%mod;
            add[p] = (add[p]*k)%mod;
            mul[p] = (mul[p]*k)%mod;
        }else
        {
            arr[p] = (arr[p]+k*(r-l+1)%mod)%mod;
            add[p] = (add[p]+k)%mod;   
        }
        return;
    }
    down(p, l, r);
    int mid = (l+r)/2;
    if(cl<=mid) change(ls(p), l, mid, cl, cr, k, op);
    if(cr>mid) change(rs(p), mid+1, r, cl, cr, k, op);
    update(p);
}

long long query(int p, int l, int r, int ql, int qr)
{
    if(ql<=l&&r<=qr){return arr[p];}
    long long ret = 0;
    down(p, l, r);
    int mid = (l+r)/2;
    if(ql<=mid) ret = (ret+query(ls(p), l, mid, ql, qr))%mod;
    if(qr>mid) ret = (ret+query(rs(p), mid+1, r, ql, qr))%mod;
    return ret; 
}

int main()
{
    cin >> n >> mod;
    for(int i = 1; i <= n; i++) {cin >> a[i];a[i]%=mod;}
    build(1, 1, n);
    cin >> m;
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