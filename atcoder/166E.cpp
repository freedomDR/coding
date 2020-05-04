#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    long long ans = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = a[i]+i-1; j <= n; j++)
        {
            if(abs(j-i) == a[i]+a[j]) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}