#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &it:a) cin >> it;
    sort(a.begin(), a.end());
    int ans = 20;
    for(int i = 1; i < n; i++)
    {
        ans = min(ans, a[i]-a[i-1]);
    }
    cout << ans << endl;
    return 0;
}