#include<bits/stdc++.h>
using namespace std;
const int MAXN = 150010;
int main()
{
    int n; cin >> n;
    int ans = 0;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int p = 0;
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++) {
        if(p < a[i]) {
            if(p < a[i]-1){ans++;p = a[i]-1;}
            else {ans++;p = a[i];}
        }else if(p == a[i]) {
            ans++;
            p = a[i] + 1;
        }
    }
    cout << ans << endl;
}
