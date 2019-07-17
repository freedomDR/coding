#include <bits/stdc++.h>

using namespace std;

int main()
{
    int m, n, ans, nn[101];
    memset(nn,0,sizeof(nn));
    for(int i = 1; i < 101; i++){
        for(int j = i; j < 101; j += i){
            nn[j] ^= 1; 
        }
    }
    scanf("%d", &m);
    while(m--){
        scanf("%d", &n);
        ans = 1;
        for(int i = 2; i <= n; i++)
            ans += nn[i];
        printf("%d\n", ans);

    }
    return 0;
}
