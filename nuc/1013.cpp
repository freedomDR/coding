#include <bits/stdc++.h>

int main()
{
    long long n;
    int ans;
    while(scanf("%lld", &n) != EOF)
    {
        ans = 0;
        while(n != 0)
        {
            ans += n/5;
            n /= 5;
        }
        printf("%d\n", ans);
    }
    return 0;
}

