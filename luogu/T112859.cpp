#include<bits/stdc++.h>

using namespace std;
inline int lc(int x) {return x<<1;}
inline int rc(int x) {return (x<<1)+1;}
const int maxn = 1e5+5;
int n, q;
vector<vector<int>> a(maxn*4), lazy(maxn*4);
void update(int p)
{
    a[p].clear();
    for(int i = 0, j = 0; i < a[lc(p)].size() && j < a[rc(p)].size(); )
    {
        if(a[lc(p)][i] == a[rc(p)][j]) {a[p].push_back(a[lc(p)][i]);i++;j++;}
        else if(a[lc(p)][i] > a[rc(p)][j]) {j++;}
        else {i++;}
    }
}
void down(int p)
{
    for(auto v:lazy[p]) a[lc(p)].push_back(v), lazy[lc(p)].push_back(v);
    for(auto v:lazy[p]) a[rc(p)].push_back(v), lazy[rc(p)].push_back(v);
    lazy[p].clear();
}

void change(int p, int l, int r, int cl, int cr, int v)
{
    if(cl<=l&&r<=cr)
    {
        a[p].push_back(v);
        lazy[p].push_back(v);
        return;
    }
    down(p);
    int mid = (l+r)/2;
    if(cl<=mid) change(lc(p), l, mid, cl, cr, v);
    if(cr>mid) change(rc(p), mid+1, r, cl, cr, v);
    update(p);
}

vector<int> query(int p, int l, int r, int ql, int qr)
{
    if(ql<=l&&r<=qr)
    {
        return a[p];
    }
    down(p);
    int mid = (l+r)/2;
    vector<int> lans, rans;
    if(ql<=mid) lans = query(lc(p), l, mid, ql, qr);
    if(qr>mid) rans = query(rc(p), mid+1, r, ql, qr);
    if(lans.empty()) return rans;
    if(rans.empty()) return lans;
    vector<int> ans;
    for(int i = 0, j = 0; i < lans.size() && j < rans.size();)
    {
        if(lans[i] == rans[j]) {ans.push_back(lans[i]);i++;j++;}
        else if(lans[i]>rans[j]) {j++;}
        else {i++;}
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= q; i++)
    {
        int op, l, r; cin >> op >> l >> r;
        if(op == 1) change(1, 1, n, l, r, i);
        else 
        {
            vector<int> ans = query(1, 1, n, l, r);
            cout << ans.size() << endl;
        }
    }
    return 0;
}