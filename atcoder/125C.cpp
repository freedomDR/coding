#include <bits/stdc++.h>
/*
 *双指针
 *
 */
using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int n; cin>>n;
    int A[n+2], L[n+2], R[n+2];
    for(int i = 0; i < n+2; i++) {L[i] = 0; R[i] = 0;}
    for(int i = 1; i <= n; i++)
    {
        cin>>A[i];
        L[i] = __gcd(A[i], L[i-1]);
    }
    int ans = 0;
    for(int i = n; i > 0; i--)
    {
        R[i] = __gcd(R[i+1], A[i]);
        ans = max(ans, __gcd(L[i-1], R[i+1]));
    }
    cout<<ans<<endl;
    return 0;
}
