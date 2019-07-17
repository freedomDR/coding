#include <bits/stdc++.h>

using namespace std;

const int N = 3050;
int n, s[N], c[N], dp[4][N];
int main()
{
    cin>>n;
    for(int i =0; i < n; i++) cin>>s[i];
    for(int i =0; i < n; i++) cin>>c[i];
    for(int i =0; i < n; i++){
        dp[1][i] = c[i];
        for(int j = 2; j <= 3; j++){
            dp[j][i] = 1e9 + 1e8;
            for(int k = 0; k < i; k++){
                if(s[k] < s[i]){
                    dp[j][i] = min(dp[j][i], dp[j-1][k] + c[i]);
                }
            }
        }
    }
    int ans = 1e9 + 1e8;
    for(int i = 0; i < n; i++) ans = min(ans, dp[3][i]);
    if(ans == 1e9 + 1e8)
        cout<<"-1"<<endl;
    else
        cout<<ans<<endl;
    return 0;
}
