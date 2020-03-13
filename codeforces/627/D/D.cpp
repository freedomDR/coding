#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for(auto &it:a) cin >> it;
    for(auto &it:b) cin >> it;
    for(int i = 0; i < n; i++)
    {
        c[i] = a[i]-b[i];
    }
    sort(a.begin(), a.end());
    long long ans = 0;
    for(int i = 0; i < n; i++)
    {
        int target = -c[i]+1;
        int dis = c.end()-lower_bound(c.begin()+i+1, c.end(), target);
        ans += dis;
    }
    cout << ans << endl;
    return 0;
}