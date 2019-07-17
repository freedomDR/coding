#include <bits/stdc++.h>
using namespace std;
char matrix[2050][2050], ans[2050];
int dp[2050][2050], v[2050][2050];
int main()
{
    int n, k;
    cin>>n>>k;
    for(int i = 1; i <= n; i++){scanf("%s", matrix[i]+1);}
    int a_sum = 0;
    for(int i = 0; i < 2050; i++) dp[i][0] = dp[0][i] = 1e9;
    dp[0][1]=dp[1][0]=0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + (matrix[i][j]!='a');
            if(dp[i][j]<=k) a_sum = max(a_sum, i+j);
        }
    }
    for(int i = 2; i <= a_sum; i++) ans[i] = 'a';
    vector<pair<int, int>> t;
    int ii = 0, jj = 1;
    if(a_sum-2+1 > n) {ii = n; jj = a_sum - n;} 
    else {ii = a_sum-1;}
    for(;jj <= n && ii >= 1; ii--, jj++) if(dp[ii][jj] == k) v[ii][jj] = 1;
    if(a_sum == 0) {v[1][1]=1;ans[2] = matrix[1][1];}
    for(int i = max(3, a_sum+1); i < 2*n + 1; i++){
        int minn = 'z';
        int ii = i - 2, jj = 1;
        if(i-1 > n) {ii = n;jj=i-1-n;}
        for(; ii >= 1 && jj <= n; ii--, jj++){
            if(ii < n && v[ii][jj]) minn = min(minn, (int)matrix[ii+1][jj]);
            if(jj < n && v[ii][jj]) minn = min(minn, (int)matrix[ii][jj+1]);
        }
        ans[i]=minn;
        ii = i - 2, jj = 1;
        if(i-1 > n) {ii = n;jj=i-1-n;}
        for(; ii >= 1 && jj <= n; ii--, jj++){
            if(ii < n && v[ii][jj] && matrix[ii+1][jj] == minn) v[ii+1][jj] = 1;
            if(jj < n && v[ii][jj] && matrix[ii][jj+1] == minn) v[ii][jj+1] = 1;
        }
    }
    printf("%s\n", ans+2);
    return 0;
}
