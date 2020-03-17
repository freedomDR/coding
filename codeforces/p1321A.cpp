#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    int cnt1 = 0, cnt2 = 0;
    for(auto &it:a) cin >> it;
    for(auto &it:b) cin >> it;
    for(int i = 0; i < n; i++)
    {
        if(a[i]==b[i]) continue;
        else if(a[i] > b[i]) cnt1++;
        else cnt2++;
    }
    if(cnt1==0)
        cout << "-1" << endl;
    else
    {
        int ans = (cnt2)/cnt1 + 1;
        cout << ans << endl;
    }
    return 0; 
}