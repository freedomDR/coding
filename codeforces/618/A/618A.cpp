#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, sums = 0, zeros = 0;
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            int a; cin >> a;
            sums += a;
            if(a == 0) zeros++;
        }
        sums += zeros;
        int ans = 0;
        if(sums == 0) ans = zeros+1;
        else ans = zeros;
        cout << ans << endl;
    }
    return 0;
}
