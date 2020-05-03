#include<bits/stdc++.h>

using namespace std;
int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int ans1 = 0, ans2 = 0;
        ans1 = (1<<n);
        for(int i = 1; i < n/2; i++)
        {
            ans1 += (1<<i);
        }
        for(int i = 1; i <= n/2; i++)
        {
            ans2 += (1<<(n-i));
        }
        cout << abs(ans1-ans2) << endl;
    }
    return 0;
}