#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin >> n;
    vector<int> q(n);
    for(auto &it:q) cin >> it;
    int ans = 0, pos = 0, j = 0;
    while(pos < n)
    {
        ++ans;
        while(pos < n && q[pos] == j) pos++;
        j ^= 1;
    }
    cout << ans << endl;
    return 0;
}
