#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int k, n;
set<ll> s;
void dfs(int p, ll v, ll add)
{
    if(p == 10) return;
    s.insert(v);
    s.insert(v+add);
    dfs(p+1, v, add*k);
    dfs(p+1, v+add, add*k);
}

int main()
{
    cin >> k >> n;
    dfs(0, 0, 1);
    vector<ll> tt;
    for(auto &it:s) tt.push_back(it);
    sort(tt.begin(), tt.end());
    cout << tt[n] << endl;
    return 0;
}
