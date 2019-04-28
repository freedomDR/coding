#include <bits/stdc++.h>

using namespace std;

void math_slove()
{
    long long n, negative_cnt = 0;
    cin>>n;
    long long A[n], a_min = LLONG_MAX, sums = 0;
    for(int i = 0; i < n; i++)
    {
        cin>>A[i];
        if(A[i] < 0) negative_cnt++;
        sums += abs(A[i]);
        a_min = min(a_min,abs(A[i]));
    }
    if(negative_cnt%2 == 0) printf("%lld\n", sums);
    else printf("%lld\n", sums - 2ll*a_min);
}

void dp_slove()
{
    long long n; cin>>n;
    long long A[n+1], dp[n+2][2];
    for(int i = 0; i < n; i++) cin>>A[i];
    dp[0][0] = 0; dp[0][1] = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        dp[i+1][0] = max(dp[i][0]+A[i], dp[i][1]-A[i]);
        dp[i+1][1] = max(dp[i][0]-A[i], dp[i][1]+A[i]);
    }
    cout<<dp[n][0]<<endl;
}

int main()
{
    /* math_slove(); */
    dp_slove();
    return 0;
}
