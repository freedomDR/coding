#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        long long cnt = 0, sums = 0;
        for(int i = n-1; i >= 0; i--)
        {
            sums += a[i];
            if(sums>=1ll*x*(n-i)) cnt = n-i;
        }
        cout << cnt << endl;
    }
    return 0;
}