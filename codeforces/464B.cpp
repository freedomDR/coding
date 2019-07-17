#include <bits/stdc++.h>

using namespace std;
long long k ,n, a, pos, ans;
int main()
{
    scanf("%lld %lld", &n, &k);
    long long res = LLONG_MAX;
    for(int i = 1; i <= k; i++){
        scanf("%lld", &a);
        if(res > n%a){
            pos = i;
            ans = n/a;
            res = n%a;
        }
    }
    printf("%lld %lld\n", pos, ans);
    return 0;
}
