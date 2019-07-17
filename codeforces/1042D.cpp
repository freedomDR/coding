#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, t;
    scanf("%I64d %I64d", &n, &t);
    vector<long long> a(n+1, 0);
    for(int i = 1 ; i <= n; i++){
        long long tmp = 0;
        scanf("%I64d", &tmp);
        a[i] = a[i-1]+tmp;
    }
    long long ans = 0;
    for (int l = 1; l <= n; l++){
        for(int r = l; r <= n; r++){
            if(a[r] < t + a[l-1]){
                ans++;
            }
        }
    }
    printf("%I64d\n", ans);
    return 0;
}
