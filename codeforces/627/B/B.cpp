#include<bits/stdc++.h>

using namespace std;

int t, n, a[5005], cnt[5005];
int main()
{
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];
        memset(cnt, 0, sizeof cnt);
        bool ok = false;
        for(int i = 1; i <= n; i++)
        {
            if(cnt[a[i]] == 1) ok = true;
            cnt[a[i]]++;
        }
        cout << (ok?"YES":"NO") << endl;
    }
    return 0;
}