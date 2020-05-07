#include<bits/stdc++.h>

using namespace std;
int n, ans = INT_MAX;
void dfs(int t, int len, int tmp)
{
    // cout << t << " " << len << " " << tmp << endl;
    if(len > n) return;
    if(len == n)
    {
        ans = min(ans, t); 
        return;      
    }
    if(t>ans) return;
    if(len != tmp)dfs(t+1, len, len);
    if(tmp) dfs(t+1, len+tmp, tmp);
}
int main()
{
    cin >> n;
    dfs(1, 1, 0);
    cout << ans-1 << endl;
    return 0;
}