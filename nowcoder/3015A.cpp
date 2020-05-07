#include<bits/stdc++.h>

using namespace std;
int n, l, x[55], y[55], ans;
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) {cin >> x[i];}
    for(int i = 1; i <= n; i++) {cin >> y[i];if(x[i]<y[i]) swap(x[i], y[i]);}
    cin >> l;
    for(int i = 1; i <= 200; i++)
    {
        for(int j = 1; j <= 200; j++)
        {
            if(i*j<l) continue;
            int cnt = 0;
            for(int k = 1; k <= n; k++)
                if(x[k]>=i&&y[k]>=j) cnt++;
            ans = max(ans, cnt);
        }
    }
    if(ans == 0) cout << "-1" << endl;
    else cout << ans << endl;
    return 0;
}