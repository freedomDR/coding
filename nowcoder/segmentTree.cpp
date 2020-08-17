#include<iostream>

using namespace std;
const int maxn = 10000;
int t[maxn*4], a[maxn], lazy[maxn*4], n, k;
inline int ls(int p) {return p << 1;};
inline int rs(int p) {return p << 1 | 1;};

void update(int p)
{
    t[p] = t[ls(p)]+t[rs(p)];   
}

void down(int l, int r, int p)
{
    int mid = (l+r)/2;
    t[ls(p)] += lazy[p]*(mid-l+1);
    t[rs(p)] += lazy[p]*(r-mid-1+1);
    lazy[ls(p)] += lazy[p];
    lazy[rs(p)] += lazy[p];
    lazy[p] = 0;
}

void build(int l, int r, int p)
{
    if(l == r)
    {
        t[p] = a[l];
        return;
    }
    int mid = (l+r)/2;
    build(l, mid, ls(p));
    build(mid+1, r, rs(p));
    update(p);
}

void change(int l, int r, int p, int cl, int cr, int v)
{
    if(cl <= l && r <= cr)
    {
        t[p] += (r-l+1)*v;
        lazy[p] += v;
        return;
    }
    down(l, r, p);
    int mid = (l+r)/2;
    if(cl<=mid) change(l, mid, ls(p), cl, cr, v);
    if(cr>mid) change(mid+1, r, rs(p), cl, cr, v);
    update(p);
}

int get_sum(int l, int r, int p, int ql, int qr)
{
    if(ql <= l && r <= qr) return t[p];
    int mid = (l+r)/2, ans = 0;
    if(ql <= mid) ans += get_sum(l, mid, ls(p), ql, qr);
    if(qr > mid) ans += get_sum(mid+1, r, rs(p), ql, qr);
    return ans; 
}

int main()
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, n, 1);
    while(k--)
    {
        int op; cin >> op;
        if(op == 1)
        {
            int l, r, v; cin >> l >> r >> v;
            change(1, n, 1, l, r, v);
        }else
        {
            int l, r; cin >> l >> r;
            cout << get_sum(1, n, 1, l, r) << endl;
        }
        
    } 
    return 0;
}

//nethogs
//性能之巅