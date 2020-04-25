#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e5+5;
int fa[maxn], n, a[maxn];

int findf(int f)
{
    if(f != fa[f])
        fa[f] = findf(fa[f]);
    return fa[f];
}

int main()
{
    cin >> n;
    vector<pair<int, int>> s;
    for(int i = 1; i <= n; i++) fa[i] = i;
    for(int i = 1; i <= n; i++) 
    {
        cin >> a[i];
        if(a[i] == 0) continue;
        if(i < a[i]) s.push_back(make_pair(i, a[i]));
        else s.push_back(make_pair(a[i], i));
    }
    sort(s.begin(), s.end());
    int ans = n, p = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = i+1; j <= n; j++)
        {
            if(p<s.size()&&s[p] == make_pair(i, j)) {p++;continue;}
            if(findf(i) == findf(j)) continue;
            else fa[findf(i)] = findf(j);
            ans--;
            cout << i << " " << j << endl;
        }
    }
    cout << ans << endl;
    return 0;
}