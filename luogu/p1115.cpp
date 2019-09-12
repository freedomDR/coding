#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    int n, ans = -100000000, tmp = 0;
    cin >> n;
    while(n--){
        int v;
        cin >> v;
        tmp += v;
        ans = max(ans, tmp);
        tmp = max(tmp, 0);
    }
    cout << ans << endl;

}
