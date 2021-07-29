#include<bits/stdc++.h>

using namespace std;

int a[200005];

int main()
{
    #ifdef LOCAL
        freopen("codeforces/in.txt", "r", stdin);
    #endif
    int t;
    cin >> t;

    auto isGood = [&](int l, int r)
    {
        for(int i = l; i <= r; i++)
        {
            for(int j = i+1; j <= r; j++)
            {
                for(int k = j+1; k <= r; k++)
                {
                    if(a[i]>=a[j]&&a[j]>=a[k])
                        return false;
                    if(a[i]<=a[j]&&a[j]<=a[k])
                        return false;
                }
            }
        }
        return true;
    };

    while(t--)
    {
        int n; cin >> n;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        int ans = 0;
        for(int i = 0, j = 0; i < n; i++)
        {
            while(!isGood(j, i))
                j++;
            ans += i-j+1;
        }
        cout << ans << endl;
    }
    return 0;
}