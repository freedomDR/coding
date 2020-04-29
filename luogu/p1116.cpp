#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> a(n);
    for(auto &it:a) cin >> it;
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(a[j]>a[i]) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}