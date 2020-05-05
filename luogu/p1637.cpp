#include<bits/stdc++.h>

using namespace std;
const int maxn = 3e4+5;
long long a[maxn];
int idx[maxn], fw1[maxn], fw2[maxn], sz, n;
inline int lowbit(int x) {return x&-x;}

void add(int p, int v, int op)
{
    for(int i = p; i <= sz; i += lowbit(i))
        if(op==1) fw1[i] += v;
        else fw2[i] += v;
}
int getSum(int p, int op)
{
    int ret = 0;
    while(p>0)
    {
        if(op==1)
            ret += fw1[p]; 
        else 
            ret += fw2[p];
        p-=lowbit(p);
    }
    return ret;
}
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) {cin >> a[i];idx[i]=a[i];}
    sort(a+1, a+n+1);
    sz = unique(a+1, a+n+1)-a-1;
    for(int i = 1; i <= n; i++) {idx[i] = lower_bound(a+1, a+sz+1, idx[i])-a;}
    for(int i = 1; i <= n; i++) {add(idx[i], 1, 2);}
    long long ans = 0;
    for(int i = 1; i <= n; i++)
    {
        add(idx[i], -1, 2);
        add(idx[i], 1, 1);
        int l = getSum(idx[i]-1, 1);
        int r = getSum(sz, 2)-getSum(idx[i], 2);
        ans += l*r;
    }
    cout << ans << endl;
    return 0;
}
