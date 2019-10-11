#include<bits/stdc++.h>
using namespace std;
int dp[300001];
int main()
{
    int M, S, T;
    cin >> M >> S >> T;
    for(int i = 1; i <= T; i++)
    {
        if(M>=10){dp[i] = dp[i-1]+60; M-=10;}
        else {dp[i] = dp[i-1]; M+=4;}
    }
    for(int i = 1; i <= T; i++)
    {
        dp[i] = max(dp[i], dp[i-1]+17);
        if(dp[i] >= S) {cout << "Yes\n" << i; return 0;}
    }
    cout << "No\n" << dp[T];
    return 0;
}
