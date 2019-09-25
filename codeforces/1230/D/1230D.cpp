#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, d[7100];
ll a[7100], b[7100], ans;
int main()
{
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i != j && a[i] == a[j])
                d[i]++;
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(d[i]) 
        {
            ans += b[i];
        }
    }
    if(ans == 0) {cout << "0" << endl;return 0;}
    for(int i = 0; i < n; i++)
    {
        if(d[i]) continue;
        bool can = false;
        for(int j = 0; j < n; j++)
        {
            if(i!=j&&d[j])
            {
                if((a[i]&a[j]) == a[i]) can = true;
            }
        }
        if(can) {ans += b[i];d[i] = 1;}
    }
    cout << ans << endl;
    return 0;
}
