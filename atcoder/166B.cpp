#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> cnt(n+1);
    for(int i = 0; i < k; i++)
    {
        int d; cin >> d;
        for(int j = 0; j < d; j++)
        {
            int v; cin >> v;
            cnt[v]++;
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
        if(cnt[i]==0) ans++;
    cout << ans << endl;
    return 0;
}