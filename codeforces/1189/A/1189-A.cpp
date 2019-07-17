#include <bits/stdc++.h>
using namespace std;
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(false);
    int n; cin >> n;
    vector<int> s(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }
    vector<vector<pair<int, int>>> dp(20);
    for(int i = 0; i < n; i++) dp[0].push_back(make_pair(s[i], 0));
    int length = 1;
    for(int i = 1; i < 20; i++) {
        length *= 2;
        for(int j = 0; j + length <= n; j++) {
            int leave1 = dp[i-1][j].first;
            int leave2 = dp[i-1][j+length/2].first;
            int candies1 = dp[i-1][j].second;
            int candies2 = dp[i-1][j+length/2].second;
            int candies = candies1+candies2;
            if(leave1+leave2>=10) candies++;
            dp[i].push_back(make_pair((leave1+leave2)%10, candies));
        }
    }
    int q; cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;
        int i = 0, pLen = r-l+1;
        while(pLen%2 == 0) {i++;pLen/=2;}
        cout << dp[i][l-1].second <<endl;
    }
}
